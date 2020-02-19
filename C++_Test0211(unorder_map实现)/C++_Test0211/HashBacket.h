#pragma once

#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace YD
{
	class DealInt
	{
	public:
		int operator ()(const int num)
		{
			return num;
		}
	};

	class DealString
	{
	public:
		int operator ()(const string& str)
		{
			int seed = 128;//����
			int sum = 0;
			for (auto& e : str)
			{
				sum = seed * sum + e;//128���ƣ���һλ�ǵ�һ���ַ����ڶ�λ�ǵڶ����ַ�
			}
			return sum & 0x7fffffff;//����Խ�磬ȡ��32λ����(��תҲ�У�����ʽת��)
		}
	};

	template<class T>//�ڵ���
	class HashBucketNode
	{
		T m_val;
		HashBucketNode<T>* m_next;
		HashBucketNode(const T& val = T()) :
			m_val(val),
			m_next(nullptr)
		{}
		template<class K, class V, class KeyOfValue, class HF>
		friend class HashBucket;
	};


	template<class K, class V, class KeyOfValue, class HF = DealInt>
	class HashBucket//��ϣͰ
	{
	private:
		vector<HashBucketNode<V>*> m_data;//����ָ��
		size_t m_size;//�Ѳ���Ԫ�صĸ���
		static long long s_m_primeTable[30];//��ϣ������ĳ��ȵ�����
		//�����Ԫ�ض����������ڶ��������ǵ�һ���������������������Ǹ��������Դ�����
		//����ѧ���ۿ�֪��ʹ�ó�������������ϣ���������Ϊ����ʱ��������ϣ��ͻ�ĸ�����ͣ�
		//��Ϊ��ÿ�ζ�Ҫmod�����������������Ϊ����ʱ������������ֻ���Լ���1��������ͻֻ��
		//��������һ��
		static int s_m_PrimePos;//��ϣ������ĳ��ȵ�������±�

		int HashFunc(const K& Key)//��ɢ������̽��
		{
			HF func;//�ȸ���Ԫ�ص����ͷֱ����int��
			return func(Key) % capacity();//���ó�����������ȡKeyֵ
		}

		void CheckCapacity()
		{
			if (m_size * 100 / capacity() >= 70)//�غ�����������0.7---0.8֮��
				//�غ����� = m_size / m_table.size();
			{
				vector<HashBucketNode<V>*> tmp(s_m_primeTable[++s_m_PrimePos], nullptr);
				HashBucketNode<V>* cur;
				tmp.swap(m_data);
				m_size = 0;
				for (int i = 0; i < tmp.size(); i++)
				{
					for (cur = tmp[i]; cur; cur = cur->m_next)
					{
						insert(cur->m_val);
					}
				}
				tmp.clear();
			}
		}
	public:
		class iterator
		{
		public:
			HashBucket<K, V, KeyOfValue, HF>* m_hb;//ָ���ϣͰ��ָ��
			HashBucketNode<V>* m_node;//ָ��Ͱ�и����ڵ��ָ��

			iterator(HashBucketNode<V>* node = nullptr,
				HashBucket<K, V, KeyOfValue, HF>* hp = nullptr) :
				m_node(node),
				m_hb(hp)
			{}

			iterator(const iterator& it) :
				m_node(it.m_node),
				m_hb(it.m_hb)
			{}

			V& operator*()
			{
				return m_node->m_val;
			}

			V* operator->()
			{
				return &(m_node->m_val);
			}

			iterator operator++()//ǰ��++
			{
				V val = m_node->m_val;
				m_node = m_node->m_next;//m_node���ھͲ���
				if (!m_node)//�˽ڵ�Ϊ��ʱ�������Ͱ��Ѱ����һ���ڵ�
				{
					int BucketNum = m_hb->HashFunc(KeyOfValue()(val)) + 1;
					//ͨ���º���KeyOfValue���Key��val��һ��pair<K,V>
					//�ҵ���һ����Ϊ�յ�Ͱ,���ܻ�Խ�磬����Ҫ��++�����͵�֪�����ܲ���++
					for (; BucketNum < m_hb->capacity(); BucketNum++)
					{
						if (m_hb->m_data[BucketNum])//���Ͱ���ڽڵ�
						{
							m_node = m_hb->m_data;
							break;
						}
					}
				}
				return *this;
			}
			iterator operator++(int)//����++
			{
				iterator<K, V, KeyOfValue, HF> tmp = *this;
				++(*this);
				return tmp;
			}

			iterator operator--()//ǰ��--
			{
				V val = m_node->m_val;
				int BucketNum = m_hb->HashFunc(KeyOfValue()(val));
				HashBucketNode<V>* cur = nullptr;
				if (m_hb->m_data[BucketNum] == m_node)
					//����ڵ������Ͱ�ĵ�һ���ڵ㣬������һ��Ͱ
				{
					BucketNum--;
					for (; BucketNum >= 0; BucketNum--)
					{
						if (m_hb->m_data[BucketNum])//���Ͱ���нڵ�,ֱ�������һ��������
						{

							cur = m_hb->m_data[BucketNum];
							for (; cur->m_next; cur = cur->m_next);
						}
					}
				}
				//else�������Ͱ�нڵ��ҵ�һ���ڵ㲻��m_node
				//ֱ����������m_next==m_node����

				else
				{
					for (; cur->m_next == m_node; cur = cur->m_next);
				}
				m_node = cur;
				return *this;
			}

			iterator operator--(int)//����--
			{
				iterator<K, V, KeyOfValue, HF> tmp = *this;
				--(*this);
				return tmp;
			}


			iterator operator == (const iterator& it)
			{
				return m_hb == it.m_hb && m_node == it.m_node;
			}

			iterator operator != (const iterator& it)
			{
				return m_hb != it.m_hb || m_node != it.m_node;
			}
		};

		HashBucket(size_t capacity = s_m_primeTable[0]) ://���캯��
			m_data(capacity, nullptr),//ע�⣺m_table.size()�ǹ�ϣ���������m_size�ǵ�ǰ�����м���Ԫ��
			m_size(0)
		{}

		iterator begin()
		{
			int BucketNum = 0;
			for (; BucketNum < capacity(); BucketNum++)
			{
				if (m_data[BucketNum])
				{
					return iterator(m_data[BucketNum], this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}


		size_t size()//��ϣ�����нڵ�ĸ���
		{
			return m_size();
		}

		size_t capacity()//���ع�ϣ���������
		{
			return m_data.size();
		}

		bool empty()const//�жϹ�ϣ�����Ƿ�Ϊ��
		{
			return m_size == 0;
		}

		void swap(HashBucket<K, V, KeyOfValue, HF>& ht)//����������ϣ����
		{
			m_data.swap(ht);
		}


		bool Is_In_Bucket(const K& key)//�ж�key�Ƿ��ڹ�ϣ����
		{
			int BucketNum = HashFunc(key);
			HashBucketNode<V>* cur = nullptr;
			for (cur = m_data[BucketNum]; cur; cur = cur->m_next)
			{
				if (KeyOfValue()(cur->m_val) == key)
				{
					return true;
				}
			}
			return false;
		}

		size_t Count_Empty_Bucket(const K& key)//ͳ�ƿ�Ͱ�ĸ���
		{
			int count = 0;
			int BucketNum;
			HashBucketNode<V>* cur = nullptr;
			for (BucketNum = 0; BucketNum < capacity(); BucketNum++)
			{
				if (!m_data[BucketNum])
				{
					count++;
				}
			}
			return count;
		}

		size_t Bucket_Size(const K& key)//ͳ��ĳ��Ͱ�нڵ�ĸ���
		{
			int count = 0;
			int BucketNum = HashFunc(key);
			HashBucketNode<V>* cur;
			for (cur = m_data[BucketNum]; cur; cur = cur->m_next)
			{
				count++;
			}
			return count;
		}

		pair<iterator, bool> insert(const V& val)//����Ԫ��
		{
			CheckCapacity();//����Ƿ����㹻�������Բ���

			int n = HashFunc(val);//��ȡ���ļ�ֵ
			HashBucketNode<V>* tmp;
			pair<iterator, bool> p;
			if (m_data[n])//���������ͷ����Ϊ�գ������
			{
				for (tmp = m_data[n]; tmp; tmp = tmp->m_next)
				{
					if (tmp->m_val == val)//�ҵ���ͬ��return 
					{
						p.first = end();
						p.second = false;
						return p;
					}
				}
			}
			tmp = new HashBucketNode<T>(val);
			tmp->m_next = m_data[n];//ͷ��
			m_data[n] = tmp;
			iterator it(m_data[n], this);
			p.first = it;
			p.second = true;
			m_size++;
			return p;
		}


		iterator Find(const V& value)//����Ԫ��
		{
			int n = HashFunc(value);//��ȡ������Ԫ�صļ�
			HashBucketNode<V>* cur;

			for (cur = m_data[n]; cur; cur = cur->m_next)
			{
				if (cur->m_val == value)
				{
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator erase(const V& val)//ɾ��Ԫ��
		{
			int n = HashFunc(KeyOfValue()(val));//��ȡ������Ԫ�صļ�
			HashBucketNode<V>* tmp;
			HashBucketNode<V>* cur;
			if (m_data[n])//ȷ�����Ͱ����Ԫ��
			{
				if (m_data[n]->m_val == val)//ͷ�����Ǵ�ɾֵ
				{
					iterator res(m_data[n], this);
					++res;//ɾ�������������ƶ���ֹ������ʧЧ
					tmp = m_data[n];
					m_data[n] = tmp->m_next;
					delete tmp;
					m_size--;
					return res;
				}
				else//ɾ��Ԫ�����м�򲻴���
				{
					for (tmp = m_data[n]; tmp->m_next; tmp = tmp->m_next)
					{
						if (tmp->m_next->m_val == val)
						{
							iterator res(tmp->m_next, this);
							++res;//ɾ�������������ƶ���ֹ������ʧЧ
							cur = tmp->m_next;
							tmp->m_next = cur->m_next;
							delete cur;
							m_size--;
							return res;
						}
					}
				}
			}
			return end();
		}

		void clear()
		{
			HashBucketNode<V>* tmp;
			for (auto& head : m_data)
			{
				while (head)
				{
					tmp = head;
					head = head->m_next;
					delete tmp;
				}
			}
			m_size = 0;
		}




		~HashBucket()
		{
			clear();
		}

	};
	template<class K, class V, class KeyOfValue, class HF>
	long long HashBucket<K, V, KeyOfValue, HF>::s_m_primeTable[30] = {
		11, 23, 47, 89, 179,
		353, 709, 1409, 2819, 5639,
		11273, 22531, 45061, 90121, 180233,
		360457, 720899, 1441807, 2883593, 5767169,
		11534351, 23068673, 46137359, 92274737, 184549429,
		369098771, 738197549, 1476395029, 2952790016u, 4294967291u };
	template<class K, class V, class KeyOfValue, class HF>
	int HashBucket<K, V, KeyOfValue, HF>::s_m_PrimePos = 0;
};