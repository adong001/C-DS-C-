#include"goods.h"

Goods::Goods(float price, int amount)
{
	m_price = price;
	m_amount = amount;
}

void Goods:: Discount(int discount)
{
	m_price *= discount;
}

void BossMenu()
{
	int choice;
	while (1)
	{
		printf("\n\n\n\t\t\t\t��ӭ����������Ʒ����ϵͳ--BOSSģʽ\n\n\n\n");
		printf("\t\t\t\t1.����\n\n");
		printf("\t\t\t\t2.��ʾ������Ʒ��Ϣ\n\n");
		printf("\t\t\t\t3.�����\n\n");
		printf("\t\t\t\t4.�˳�\n\n");
		switch (choice)
		{
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: exit(1); break;
		default: printf("��������!!!"); break;
		}
		system("cls");
	}
}

