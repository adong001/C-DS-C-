#pragma once
#include"HashBacket.h"
namespace YD
{
	//��������
	template<class K, class V, class KeyOfValue, class HF = DealInt>
	class iterator
	{
	public:
		HashBucket<K, V, KeyOfValue, HF>* m_hb;//ָ���ϣͰ��ָ��
		HashBucketNode<V>* m_node;//ָ��Ͱ�и����ڵ��ָ��

		iterator(HashBucketNode<V>* node = nullptr,
			HashBucket<K,V,KeyOfValue,HF>* hp =  nullptr):
			m_node(node),
			m_hb(hp)
		{}
			
		iterator(const iterator& it):
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
			iterator<K,V,KeyOfValue,HF> tmp = *this;
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
			iterator<K, V,KeyOfValue, HF> tmp = *this;
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
};