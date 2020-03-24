#include"rsa.h"

void GetRandom()
{
	//mt19937:һ�������������
	rp::mt19937 gen(time(nullptr));
	cout << "random" << endl;
	//ָ��������ķ�Χ 0 ~ (1<<786) 
	rp::uniform_int_distribution<mp::cpp_int> dist(0, mp::cpp_int(1) << 768);

	cout << dist(gen) << endl;
}

bool IsPrimeBigInt(DataType& data)
{
	rp::mt11213b gen(time(nullptr));
	if (miller_rabin_test(data, 25, gen))
	{
		if (miller_rabin_test((data - 1) / 2, 25, gen))
		{
			return true;
		}
	}
	return false;
}

void RSA::Encrypt(const char* filename, const char* fileout)//�ļ�����
{
	ifstream fin(filename, ifstream::binary);
	ofstream fout(fileout, ifstream::binary);
	if (!fin.is_open())
	{
		perror("input file open failed\n");
		return;
	}
	
	int length = sizeof(DataType);
	int size = NUMBER * length;

	//��ȡ���ֽ�һ����DataType������������֤һ�β����ȡ���DataType������
	char* bufferin = new char[size];
	DataType* bufferout = new DataType[NUMBER];
	int curNum;

	while (!fin.eof())
	{
		fin.read(bufferin, size);//ÿ�ζ�NUMBER��DataType�ֽڵ�����
		curNum = fin.gcount();//�����������ֽ������п��ܺ��������
		curNum /= length;//����curNum��DataType�ֽڵ�����
		int i,j;
		for (i = 0,j = 0; i < curNum; i++)
		{
			//���ܺ���д��bufferout��������
			bufferout[i] = Encrypt((DataType)bufferin[j], m_key.m_eKey, m_key.m_pKey);
			j += length;//bufferin��charÿ��ƫ��DataType��С��λ��
		}
		fout.write((char*)bufferout, curNum * length);//���ܺ�д�뵽fout��
	}
	delete[] bufferin;
	delete[] bufferout;
	fin.close();
	fout.close();
}

void RSA::Decrypt(const char* filename, const char* fileout)//�ļ�����
{

	ifstream fin(filename, ifstream::binary);
	ofstream fout(fileout, ifstream::binary);
	if (!fin.is_open())
	{
		perror("input file open failed\n");
		return;
	}	
	
	int length = sizeof(DataType);
	int size = NUMBER * length;
	int curNum;

    DataType* bufferin = new DataType[NUMBER];
	char* bufferout = new char[size];

	while (!fin.eof())
	{
		fin.read((char*)bufferin, size);//ÿ�ζ�NUMBER��DataType�ֽڵ�����
		curNum = fin.gcount();//�����������ֽ������п��ܺ��������
		curNum /= length;//����curNum��DataType�ֽڵ�����
		int i, j;
		for (i = 0, j = 0; i < curNum; i++)
		{
			//���ܺ���д��bufferout��������
			bufferout[j] = (char)Decrypt(bufferin[i], m_key.m_dKey, m_key.m_pKey);
			j += length;//bufferout��charÿ��ƫ��DataType��С��λ��
		}
		fout.write(bufferout, curNum * length);//���ܺ�д�뵽fout��
	}
	//��ȡ���ֽ�һ����DataType������������֤һ�β����ȡ���DataType������

	delete[] bufferin;
	delete[] bufferout;
	fin.close();
	fout.close();
}

DataType RSA::Encrypt(DataType data, DataType ekey, DataType pkey)//���ܺ���
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

DataType RSA::Decrypt(DataType data, DataType dkey, DataType pkey)//���ܺ���
{
	//msgE-->���ģ�data-->���ģ�dkey-->˽Կ��pkey-->n
	//���ܣ�msgE = (data^dkey)%n 
	return Encrypt(data, dkey, pkey);
}


DataType RSA::GetPrime()//��ȡ����
{
	rp::mt19937 gen(time(NULL));
	rp::uniform_int_distribution<DataType> dist(DataType(1), DataType(1) << 256);
	//�����ȡһ��50λ��256λ�Ĵ���
	//srand(time(NULL));  
	DataType prime;
	while (true)
	{
		//prime = rand() % 100 + 2;
		prime = dist(gen);
		if (IsPrime(prime))
		{
			break;
		}
	}
	cout << "prime = " << prime << endl;
	return prime;
}

bool RSA::IsPrime(DataType data)//�ж��Ƿ�Ϊ����
{
	rp::mt11213b gen(time(nullptr));
	if (miller_rabin_test(data, 25, gen))
	{
		if (miller_rabin_test((data - 1) / 2, 25, gen))
		{
			return true;
		}
	}
	return false;
}
DataType RSA::GetPKey(DataType prime1, DataType prime2)//��ȡn
{
	//f(n) = f(p1*p2)
	return prime1 * prime2;
}

DataType RSA::GetOrla(DataType prime1, DataType prime2)//ŷ��������
{
	//f(nm) = f(n)f(m) = (n-1)(m-1)
	return (prime1 - 1)*(prime2 - 1);
}

DataType RSA::GetEKey(DataType orla)//��ȡ������Կe
{
	//1 < e < f(n)
	rp::mt19937 gen(time(NULL));
	rp::uniform_int_distribution<DataType> dist(2,orla);//��ȡһ��2--orla�Ĵ���
	
	//srand(time(NULL));
	DataType ekey;
	while (true)
	{
		ekey = dist(gen);
		//ekey = rand() % orla;//ģ��϶�С��f(n)
		if (ekey > 1 && GetGcd(ekey, orla) == 1)//1 < e < orla e��orla����(���Լ��=1)
		{
			return ekey;
		}
	}

}
DataType RSA::GetDKey(DataType ekey, DataType orla)//��ȡ������Կd
{
	// e * d % f(n) = 1  (f(n) = orla)
	DataType x = 0, y = 0;
	ExGcd(ekey, orla, x, y);
	//�任����˽Կd��һ���Ƚ�С��ֵ
	return (x % orla + orla) % orla;
	/*DataType dkey = orla / ekey;
	while (true)
	{
		if ((dkey * ekey) % orla == 1)
		{
			return dkey;
		}
		++dkey;
	}
	return dkey;*/
	
}
DataType RSA::GetGcd(DataType data1, DataType data2)//��ȡ�����������Լ��
{
	//����ʱ��data1 >= data2
	if (data2 == 0)
	{
		return data1;
	}
	return GetGcd(data2, data1 % data2);
}

void RSA::GetKeys()
{
	DataType prime1 = GetPrime();
	DataType prime2 = GetPrime();
	while (prime1 == prime2)
	{
		prime2 = GetPrime();
	}

	DataType orla = GetOrla(prime1, prime2);
	m_key.m_pKey = GetPKey(prime1, prime2);
	m_key.m_eKey = GetEKey(orla);
	m_key.m_dKey = GetDKey(m_key.m_eKey,orla);
}

Key RSA::GetAllKey()//�����װ����˽�г�Ա�Ľӿ�
{
	return m_key;
}
//��˽Կ

//��ģ��Ԫ��(��Կe)
DataType ExGcd(DataType a, DataType b, DataType& x, DataType& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	DataType gcd = ExGcd(b, a % b, x, y);
	DataType x1 = x, y1 = y;
	x = y1;
	y = x1 - a / b * y1;
	return gcd;
}