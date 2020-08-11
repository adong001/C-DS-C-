#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

namespace Kruskal//Kruskal�㷨
{
	//�����ֵ����V�ͱߵ�����W,DΪtrue�Ǵ�������ͼ��false��������ͼ
	template<class V, class W, bool D = false>
	class Graph
	{
	private:
		vector<V> m_vertex;//���㼯��
		vector<int> m_arr;//���鼯���ϣ���⻷
		map<W, pair<int, int>> m_map;//�߼���
		unordered_map<V, int> m_pos;//����ֱ���ҵ������±�
	public:
		Graph(const V* a, int n)//���캯��
		{
			m_vertex.resize(n);
			m_arr.resize(n, -1);
			for (int i = 0; i < n; i++)
			{
				m_vertex[i] = a[i];
				m_pos[a[i]] = i;
			}
		}

		int Find(int index)//����Ԫ�����ĸ�������
		{
			while (m_arr[index] >= 0)
			{
				index = m_arr[index];
			}
			return index;
		}

		bool Union(int srcindex, int detindex)
		{
			if (srcindex == detindex)//��ͬ���㲻�ܺϲ�
			{
				return false;
			}
			m_arr[srcindex] += m_arr[detindex];//det�ϲ���src��
			m_arr[detindex] = srcindex;
			return true;

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
			int srcIndex = GetPosInMatrix(src);
			int detIndex = GetPosInMatrix(det);
			m_map[weight] = { srcIndex, detIndex };//�ϲ�������

		}

		void kruskal()
		{
			W Sum = W();
			auto mit = m_map.begin();
			for (int i = 0; i < m_vertex.size() - 1; i++, mit++)//n�����㣬��С��������n-1����
			{
				int x = Find(mit->second.first);
				int y = Find(mit->second.second);
				if (Union(x, y) == false)//������������һ�����ϣ����ܺϲ����γɻ�
				{
					i--;//���ܺϲ�ʱ��i++������һ���ߣ�������Ҫ��ѭ�������++����
					continue;
				}
				Sum += mit->first;
				cout << m_vertex[mit->second.first] << "[" << mit->second.first << "] ---(" << mit->first << ")---";
				cout << m_vertex[mit->second.second] << "[" << mit->second.second << "]\n";
			}
			cout << "��С����������Ȩֵ��" << Sum << endl;
		}
	};
	void TestGraph()
	{
		string a[7] = { "Τ��", "������", "����", "ղķ˹", "����", "�Ʊ�", "����ɭ" };
		Graph<string, int> g(a, 7);
		g.AddEdge("ղķ˹", "����ɭ", 18);
		g.AddEdge("ղķ˹", "����", 24);
		g.AddEdge("ղķ˹", "����", 14);
		g.AddEdge("����", "����ɭ", 22);
		g.AddEdge("����", "������", 25);
		g.AddEdge("Τ��", "������", 10);
		g.AddEdge("Τ��", "����", 28);
		g.AddEdge("�Ʊ�", "����", 16);
		g.AddEdge("�Ʊ�", "����ɭ", 12);
		cout << "Kruskal :\n";
		g.kruskal();
	}
}


namespace Prime//Prime�㷨
{
	//�����ֵ����V�ͱߵ�����W,DΪtrue�Ǵ�������ͼ��false��������ͼ
	template<class V, class W, bool D = false>
	class Graph
	{
	private:
		pair<W, pair<int, int>> m_min;//�洢��С�ı�
		vector<V> m_vertex;//���㼯��
		vector<vector<W>> m_line;//�߼���
		unordered_map<V, int> m_pos;//�����ֵ��Ӧ�ڶ��㼯���е��±�,
	public:
		Graph(const V* a, int n)//���캯��
		{
			m_vertex.resize(n);
			m_line.resize(n);
			m_min = { INT_MAX, { -1 , -1 } };
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

			if (m_min.first > weight)//�ҵ���С�ı�
			{
				m_min.first = weight;
				m_min.second = { srcIndex, detIndex };
			}

			//2.�޸��ڽӾ����е�ֵ
			m_line[srcIndex][detIndex] = weight;
			if (D == false)//����ͼҪ���������
			{
				m_line[detIndex][srcIndex] = weight;
			}
		}

		void prime()
		{
			W Sum = W();
			//1.��ʼ�����ҵ���С�ıߣ�����m_pos��begin()λ��
			unordered_set<int> s;//�洢�Ѿ��ҵ��Ķ�����±�
			s.insert(m_min.second.first);
			s.insert(m_min.second.second);
			Sum += m_min.first;
			cout << m_vertex[m_min.second.first] << "[" << m_min.second.first << "] ---(" << m_min.first << ")---";
			cout << m_vertex[m_min.second.second] << "[" << m_min.second.second << "]\n";
			//2.Ѱ���ҵ��ڵ��������ߵ���Сֵ
			
			for (int i = 1; i < m_vertex.size()-1; i++)
			{
				pair<W, pair<int, int>> min = { INT_MAX, { -1, -1 } };
				for (auto& e : s)
				{
					for (int i = 0; i < m_vertex.size(); i++)
					{
						if (m_line[e][i] != W() && s.find(i) == s.end())//�ߴ��������ӵĽڵ㲻��s��
						{
							min.first = min.first > m_line[e][i] ? m_line[e][i] : min.first;
							min.second = { e, i };
						}
					}
					
				}
				cout << m_vertex[min.second.first] << "[" << min.second.first << "] ---(" << min.first << ")---";
				cout << m_vertex[min.second.second] << "[" << min.second.second << "]\n";
				s.insert(min.second.second);
				Sum += min.first;
			}
			cout << "��С����������Ȩֵ��" << Sum << endl;
		}
	};

	void TestGraph()
	{
		string a[7] = { "Τ��", "������", "����", "ղķ˹", "����", "�Ʊ�", "����ɭ" };
		Prime::Graph<string, int> g(a, 7);
		g.AddEdge("ղķ˹", "����ɭ", 18);
		g.AddEdge("ղķ˹", "����", 24);
		g.AddEdge("ղķ˹", "����", 14);
		g.AddEdge("����", "����ɭ", 22);
		g.AddEdge("����", "������", 25);
		g.AddEdge("Τ��", "������", 10);
		g.AddEdge("Τ��", "����", 28);
		g.AddEdge("�Ʊ�", "����", 16);
		g.AddEdge("�Ʊ�", "����ɭ", 12);
		cout << "Prime :\n";
		g.prime();
	}
}

