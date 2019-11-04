#ifndef _BTREE_H_
#define _BTREE_H_
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef char BTDataType;

typedef struct BinaryTreeNode 
{  BTDataType _data;  
   struct BinaryTreeNode* lchild;  
   struct BinaryTreeNode* rchild; 
}BTNode;


BTNode* BinaryTreeCreate(BTDataType* src);//ͨ��ǰ�����������"ABD##E#H##CF##G##"����������

void BinaryTreeDestory(BTNode* root);//���ٶ�����

int BinaryTreeSize(BTNode* root);//�����Ľڵ����

int BinaryTreeLeafSize(BTNode* root);//������Ҷ�ӽڵ����

int BinaryTreeLevelKSize(BTNode* root, int k);//���K��ڵ���

BTNode* BinaryTreeFind(BTNode* root, BTDataType x); //������ĳ��ֵ

int BinaryTreeDeep(BTNode* root);//���������

// ����
void BinaryTreePrevOrder(BTNode* root); //�������

void BinaryTreeInOrder(BTNode* root);//�������

void BinaryTreePostOrder(BTNode* root);//�������


void BinaryTreeLevelOrder(BTNode* root);// �������

int BinaryTreeComplete(BTNode* root); // �ж϶������Ƿ�����ȫ������

// �ǵݹ���� 
void BinaryTreePrevOrderNonR(BTNode* root);//�������

void BinaryTreeInOrderNonR(BTNode* root);//�������

void BinaryTreePostOrderNonR(BTNode* root);//�������

void TestBinaryTree();

#endif
