#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

namespace Matrix//�ڽӾ���
{
	//�����ֵ����V�ͱߵ�����W,DΪtrue�Ǵ�������ͼ��false��������ͼ
	template<class V, class W, bool D = false>
	class Graph
	{
	private:
		vector<V> m_vertex;//���㼯��
		vector<vector<W>> m_line;//�߼���
		unordered_map<V, int> m_pos;//�����ֵ��Ӧ�ڶ��㼯���е��±�
	public:
		Graph(const V* a, int n)//���캯��
		{
			m_vertex.resize(n);
			m_line.resize(n);
			for (int i = 0; i < n; i++)
			{
				m_vertex[i] = a[i];
				m_line[i].resize(n, W());
				m_pos[a[i]] = i;
			}
		}

		//��ȡ����src�ھ����е��±�
		int GetPosInMatrix(const V& src)
		{
			if (m_pos.find(src) != m_pos.end())
			{
				return m_pos[src];
			}
			throw invalid_argument("�Ƿ�����");
		}
		//���һ����src��detȨ��Ϊweight�ı�
		void AddEdge(const V& src, const V& det, const W& weight)
		{
			//1.�Ȼ�ȡ���������ھ����е��±�
			int srcIndex = GetPosInMatrix(src);
			int detIndex = GetPosInMatrix(det);
			if (m_line[srcIndex][detIndex] != W())//�������Ѿ�������,�����ڲ���
			{
				return;
			}
			//2.�޸��ڽӾ����е�ֵ
			m_line[srcIndex][detIndex] = weight;
			if (D == false)//����ͼҪ���������
			{
				m_line[detIndex][srcIndex] = weight;
			}
		}

		void _DFS(int srcIndex, vector<bool>& visted)
		{
			visted[srcIndex] = true;
			cout << m_vertex[srcIndex] << "[" << srcIndex << "]";
			for (int i = 0; i < m_vertex.size(); i++)
			{
				if (m_line[srcIndex][i] != W() && visted[i] != true)
				{
					cout << " -(" << m_line[srcIndex][i] << ")- ";
					_DFS(i, visted);
				}
			}
		}
		void DFS(const V& v)//������ȱ���
		{
			int index = GetPosInMatrix(v);
			vector<bool> flag(m_vertex.size(), false);//����Ѿ�������Ϊtrue
			_DFS(index, flag);
			cout << endl;
		}

		void BFS(const V& v)//������ȱ���
		{
			int index = GetPosInMatrix(v);
			vector<bool> flag(m_vertex.size(), false);//����Ѿ�������Ϊtrue
			queue<int> q;
			q.push(index);
			flag[index] = true;
			while (!q.empty())
			{
				int levelsize = q.size();//ÿһ��ĸ���
				for (int i = 0; i < levelsize; i++)
				{
					int pos = q.front();
					cout << m_vertex[pos] << "[" << pos << "]";
					for (int i = 0; i < m_vertex.size(); i++)
					{
						if (flag[i] != true && m_line[pos][i] != W())
						{
							q.push(i);
							flag[i] = true;
						}
					}
					q.pop();
				}
				cout << endl;
			}
			cout << endl;
		}
	};

	void TestGraph()
	{
		string a[8] = { "ղķ˹", "����", "Τ��", "����ɭ", "������", "����", "�Ʊ�", "�ǵ�" };
		Graph<string, int> g(a, 8);
		g.AddEdge("ղķ˹", "Τ��", 100);
		g.AddEdge("ղķ˹", "����", 98);
		g.AddEdge("ղķ˹", "����", 98);
		g.AddEdge("����", "����ɭ", 99);
		g.AddEdge("����", "������", 90);
		g.AddEdge("������", "����ɭ", 90);
		g.AddEdge("�Ʊ�", "�ǵ�", 100);
		/*g.DFS("ղķ˹");
		g.DFS("����");
		g.DFS("�ǵ�");*/
		g.BFS("ղķ˹");
		g.BFS("����");
		g.BFS("�ǵ�");
	}
}

namespace List//�ڽӱ�
{
	template<class W>//��������һ��Ȩ�ع���һ���ڵ�
	struct ListNode
	{
		int m_det;//����
		W m_w;//�ߵ�Ȩ��
		ListNode* m_next;
		ListNode(int det, W w) :
			m_det(det),
			m_w(w)
		{
			m_next = nullptr;
		}
	};

	template<class V, class W, bool D = false>
	class Graph
	{
	private:
		typedef ListNode<W> Edge;
		vector<V> m_vertex;//���㼯��    
		vector<Edge*> m_list;//�ڽӱ�ÿ��Ԫ����һ��������ɣ�
		unordered_map<V, int> m_pos;//�����ֵ��Ӧ�ڶ��㼯���е��±�

		//1.���㼯�ϴ洢 ����ֵ ���±��Ӧ���
		//2.ͨ�������ֵ��m_pos���ҵ���Ӧ�ı��
		//3.�ڽӱ��д洢һ�������ڽӱ��±����src���±�
		//��������д洢�ĸ����ڵ�����һ��det�±��src��det֮��ı�Ȩ��
		//ͨ��src���±��det���±��ڶ��㼯�����ҵ����������ֵ,��Ȩ��w��ȷ����һ�Թ�ϵ
	public:
		Graph(const V* a, int n)//���캯��
		{
			m_vertex.resize(n);
			m_list.resize(n);
			for (int i = 0; i < n; i++)
			{
				m_list[i] = nullptr;
				m_vertex[i] = a[i];
				m_pos[a[i]] = i;
			}
		}

		//��ȡ����src�ھ����е��±�
		int GetPosInMatrix(const V& src)
		{
			if (m_pos.find(src) != m_pos.end())
			{
				return m_pos[src];
			}
			throw invalid_argument("�Ƿ�����");
		}

		//�ж��Ƿ����һ����ϵ
		bool JudgeExitLine(const V& src, const V& det, const W& weight)
		{
			int srcIndex = GetPosInMatrix(src);
			int detIndex = GetPosInMatrix(det);
			Edge* cur = m_list[srcIndex];
			while (cur)
			{
				if (cur->m_det == detIndex && cur->m_w == weight)
				{
					return true;
				}
				cur = cur->m_next;
			}
			return false;
		}

		//��m_list[src]�����һ����ϵ(src,det,weight)
		void AddSrcEdge(int srcIndex, int detIndex, const W& weight)
		{
			Edge* node = new Edge(detIndex, weight);
			//����ͷ��
			node->m_next = m_list[srcIndex];//�½ڵ����ͷ��
			m_list[srcIndex] = node;//����ͷ���
		}


		//���һ����src��detȨ��Ϊweight�ı�
		void AddEdge(const V& src, const V& det, const W& weight)
		{
			if (JudgeExitLine(src, det, weight))//�ж������ϵ������ʱ���ڲ���
			{
				return;
			}
			//1.�Ȼ�ȡ���������ھ����е��±�
			int srcIndex = GetPosInMatrix(src);
			int detIndex = GetPosInMatrix(det);

			//2.���ڽӱ����������һ���ڵ�
			AddSrcEdge(srcIndex, detIndex, weight);
			if (D == false)//����ͼҪ���������
			{
				AddSrcEdge(detIndex, srcIndex, weight);
			}
		}

		void _DFS(int srcIndex, vector<bool>& flag)
		{
			flag[srcIndex] = true;
			cout << m_vertex[srcIndex] << "[" << srcIndex << "]";
			Edge* tmp = m_list[srcIndex];
			while (tmp)
			{
				if (flag[tmp->m_det] != true)
				{
					cout << " -(" << m_list[srcIndex]->m_w << ")- ";
					_DFS(tmp->m_det, flag);
				}
				tmp = tmp->m_next;
			}
		}
		void DFS(const V& v)//������ȱ���
		{
			int index = GetPosInMatrix(v);
			vector<bool> flag(m_vertex.size(), false);//����Ѿ�������Ϊtrue
			_DFS(index, flag);
			cout << endl;
		}

		void BFS(const V& v)//������ȱ���
		{
			int index = GetPosInMatrix(v);
			vector<bool> flag(m_vertex.size(), false);//����Ѿ�������Ϊtrue
			queue<int> q;
			q.push(index);
			flag[index] = true;
			while (!q.empty())
			{
				int levelsize = q.size();//ÿһ��ĸ���
				for (int i = 0; i < levelsize; i++)
				{
					int pos = q.front();
					cout << m_vertex[pos] << "[" << pos << "]";
					Edge* node = m_list[pos];
					while (node)
					{
						if (flag[node->m_det] != true)
						{
							q.push(node->m_det);
							flag[node->m_det] = true;
						}
						node = node->m_next;
					}
					q.pop();
				}
				cout << endl;
			}
			cout << endl;
		}
	};

	void TestGraph()
	{
		string a[8] = { "ղķ˹", "����", "Τ��", "����ɭ", "������", "����", "�Ʊ�", "�ǵ�" };
		Graph<string, int> g(a, 8);
		g.AddEdge("ղķ˹", "Τ��", 100);
		g.AddEdge("ղķ˹", "����", 98);
		g.AddEdge("ղķ˹", "����", 98);
		g.AddEdge("����", "����ɭ", 99);
		g.AddEdge("����", "������", 90);
		g.AddEdge("������", "����ɭ", 90);
		g.AddEdge("�Ʊ�", "�ǵ�", 100);
		/*g.DFS("ղķ˹");
		g.DFS("����");
		g.DFS("�ǵ�");*/
		g.BFS("ղķ˹");
		g.BFS("����");
		g.BFS("�ǵ�");
	}
}