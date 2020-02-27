#include"rsa.h"

//bool IsPrimeBigInt(DataType& data)
//{
//	brdm::mt11213b gen(time(nullptr));
//	if (miller_rabin_test(data, 25, gen))
//	{
//		if (miller_rabin_test((data - 1) / 2, 25, gen))
//		{
//			return true;
//		}
//	}
//	return false;
//}

void RSA::ecrept(const char* filename, const char* fileout)//�ļ�����
{
	fstream fs;
	fs.open(filename, ios::in | ios::out | ios::binary);//�Զ�д��ʽ���ļ�
	if (!fs)
	{
		perror("input file open failed\n");
		return;
	}

	char* buffer = new char[NUMBER];
	DataType tmp;
	int size = sizeof(DataType);
	int curNum;
	int DataTypeNum;

	while (!fs.eof())
	{
		fs.read(buffer, NUMBER);//ÿ�ζ�256�ֽ�
		curNum = fs.gcount();//�����������ֽ���
		DataTypeNum = curNum / size;
		tmp = (DataType)buffer[DataTypeNum * size - 1];
		//tmp���滺�����к���һ������һ��DataType��С���ݣ�
		//��Ϊ�п��ܻ�������֣�NUMBER����DataType����������
		//�ͻ����һ��DataType����һ����ǰһ��256�ֽڱ����ߣ���һ���ں�һ��256�ֽڱ�����
		//�ͻ���ܴ�����

		for (int i = 0; i < DataTypeNum * size - 1; i += size - 1)
		{
			//��DataTypeΪ��λ���м���
			ecrept((DataType)buffer[i], m_key._eKey, m_key._pKey);
		}
		fs.write((char*)buffer, curNum * sizeof(DataType));//���ܺ�д�뵽fout��
	}
	delete[] buffer;
	fs.close();
}
void RSA::dcrept(const char* filename, const char* fileout)//�ļ�����
{

	ifstream fin(filename, ifstream::binary);
	ofstream fout(fileout, ifstream::binary);
	if (!fin.is_open())
	{
		perror("input file open failed\n");
		return;
	}
	char* bufferout = new char[NUMBER];
	DataType* buffer = new DataType[NUMBER];
	while (!fin.eof())
	{
		fin.read((char*)buffer, NUMBER*sizeof(DataType));
		int curNum = fin.gcount();//�����������ֽ���
		curNum /= sizeof(DataType);
		for (int i = 0; i < curNum; i++)
		{
			bufferout[i] = (char)decrept(buffer[i], m_key._dKey, m_key._pKey);//��DataTypeΪ��λ���н���
		}
		fout.write(bufferout, curNum);//���ܺ�д�뵽fout��
	}

	delete[] buffer;
	delete[] bufferout;
	fin.close();
	fout.close();
}

DataType RSA::ecrept(DataType data, DataType ekey, DataType pkey)//���ܺ���
{
	//msgE-->���ģ�data-->���ģ�ekey-->��Կ��pkey-->n
	/*���ܣ�msgE = (data^ekey)% pkey 
				 = ((data^(b0*2^0) * data^(b1*2^1)*......*data^(bn*2^n))% pkey 
	             = ((data^(2^i)) *......*(data^(2^n)))% pkey  //i����data ����λΪ1��λ��
				 = (((data^(2^i)) % pkey) *......*((data^(2^n)) % pkey))% pkey
��Ai = (data^(2^i))% pkey
  An = (data^(2^n))% pkey
     = (data^(2^(n-1))% pkey * data^(2^(n-1))% pkey)% pkey
	 = (An-1 * An-1) %pkey
				 = (Ai * ......* An);
				 ����ÿ�ζ�%pkey���Ͳ�������������
	*/
	DataType Ai = data;
	DataType msgE = 1;
	//data^ekey % pkey
	while (ekey)
	{
		if (ekey & 1)//ȡ������λΪ1��
		{
			msgE = (msgE * Ai) % pkey;//msgE = ����Ai ,��һ��Ai = data^ 2^ i % pkey
		}
		ekey >>= 1;//ȡ��һλ
		Ai = (Ai * Ai) % pkey; //Ai+1 = (Ai * Ai) % pkey
	}
	return msgE;//����
}

DataType RSA::decrept(DataType data, DataType dkey, DataType pkey)//���ܺ���
{


	//msgE-->���ģ�data-->���ģ�dkey-->˽Կ��pkey-->n
	//���ܣ�msgE = (data^dkey)%n 
	return ecrept(data, dkey, pkey);
}


DataType RSA::getPrime()//��ȡ����
{
	/*boost::random::mt199937 gen(time(NULL));
	  boost::random::uniform_int_distribution<DataType> dist(0,DataType(1)<<256);
	  */
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
	if (data % 2 == 0)
	{
		return false;
	}

	for (int i = 3; i <= sqrt(data); i += 2)//��2�Ժ�ż��һ����������
	{
		if (data % i == 0)
		{
			return false;
		}
		return true;
	}
}
DataType RSA::getPKey(DataType prime1, DataType prime2)//��ȡn
{
	//f(n) = f(p1*p2)
	return prime1 * prime2;
}

DataType RSA::getOrla(DataType prime1, DataType prime2)//ŷ��������
{
	//f(nm) = f(n)f(m) = (n-1)(m-1)
	return (prime1 - 1)*(prime2 - 1);
}

DataType RSA::getEKey(DataType orla)//��ȡ������Կe
{
	//1 < e < f(n)
	/*boost::random::mt199937 gen(time(NULL));
	boost::random::uniform_int_distribution<DataType> dist(2,orla);
	*/
	srand(time(NULL));
	DataType ekey;
	while (true)
	{
		//ekey = dist(gen);
		ekey = rand() % orla;//ģ��϶�С��f(n)
		if (ekey > 1 && getGcd(ekey, orla) == 1)//1 < e < orla e��orla����(���Լ��=1)
		{
			return ekey;
		}
	}

}
DataType RSA::getDKey(DataType ekey, DataType orla)//��ȡ������Կd
{
	// e * d % f(n) = 1  (f(n) = orla)
	//DataType x = 0, y = 0;
	//exGcd(ekey, orla, x, y);
	////�任����˽Կd��һ���Ƚ�С��ֵ
	//return (x% orla + orla) % orla;
	DataType dkey = orla / ekey;
	while (true)
	{
		if ((dkey * ekey) % orla == 1)
		{
			return dkey;
		}
		++dkey;
	}
	return dkey;
	
}
DataType RSA::getGcd(DataType data1, DataType data2)//��ȡ�����������Լ��
{
	//����ʱ��data1 >= data2
	if (data2 == 0)
	{
		return data1;
	}
	return getGcd(data2, data1 % data2);
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

Key RSA::getallKey()//�����װ����˽�г�Ա�Ľӿ�
{
	return m_key;
}
//��˽Կ

//��ģ��Ԫ��(��Կe)
DataType exGcd(DataType a, DataType b, DataType& x, DataType& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	DataType gcd = exGcd(b, a % b, x, y);
	DataType x1 = x, y1 = y;
	x = y1;
	y = x1 - a / b * y1;
	return gcd;
}