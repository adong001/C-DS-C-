#include"rsa.h"

DataType RSA::ecrept(DataType data, DataType ekey, DataType pkey)//���ܺ���
{
	//i : 0,1,2,...���һλ
	DataType Ai = data;
	DataType msgE = 1;
	//data^ekey % pkey
	while (ekey)
	{
		if (ekey & 1)
		{
			msgE = (msgE * Ai) % pkey;
		}
		ekey >>= 1;
		Ai = (Ai - Ai) % pkey;
	}
	return msgE;
}

DataType RSA::decrept(DataType data, DataType dkey, DataType pkey)//���ܺ���
{
	return ecrept(data, dkey, pkey);
}


DataType RSA::getPrime()//��ȡ����
{
	srand(time(NULL));
	DataType prime;
	while (true)
	{
		prime = rand() % 100 + 2;
		if (IsPrime(prime))
		{
			break;
		}
	}
	return prime;
}

bool RSA::IsPrime(DataType data)//�ж��Ƿ�Ϊ����
{
	for (int i = 2; i <= sqrt(data); i++)
	{
		if (data%i == 0)
		{
			return false;
		}
		return true;
	}
}
DataType RSA::getPKey(DataType prime1, DataType prime2)//��ȡ��Կ,��n
{
	return prime1 * prime2;
}

DataType RSA::getOrla(DataType prime1, DataType prime2)//ŷ��������
{
	return (prime1 - 1)*(prime2 - 1);
}

DataType RSA::getEKey(DataType orla)//��ȡ������Կe
{
	//1 < e < f(n)
	srand(time(NULL));
	DataType ekey;
	while (true)
	{
		ekey = rand() % orla;//ģ��϶�С��f(n)
		if (ekey > 1 && getGcd(ekey, orla) == 1)
		{
			return ekey;
		}
	}

}
DataType RSA::getDKey(DataType ekey, DataType orla)//��ȡ������Կd
{
	// e * d % f(n) = 1  (f(n) = orla)
	DataType dkey = orla / ekey;
	while (true)
	{
		if ((dkey * ekey) % orla == 1)
		{
			return dkey;
		}
		++dkey;
	}
}
DataType RSA::getGcd(DataType data1, DataType data2)//��ȡ�����������Լ��
{
	//����ʱ��data1 >= data2
	DataType residual;
	while (residual = data1 % data2)
	{
		data1 = data2;
		data2 = residual;
	}
	return data2;
}

void RSA::getKeys()
{
	DataType prime1 = getPrime();
	DataType prime2 = getPrime();
	while (prime1 == prime2)
	{
		prime2 = getPrime();
	}

	DataType orla = getOrla(prime1, prime2);
	m_key._pKey = getPKey(prime1, prime2);
	m_key._eKey = getEKey(orla);
	m_key._dKey = getDKey(m_key._eKey,orla);
}

Key RSA::getallKey()
{
	return m_key;
}