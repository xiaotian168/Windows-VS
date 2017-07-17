#include<iostream>
#include<string>
using namespace std;

//��Ϊԭʼ���ࣨ�����ࣩ
class Animal
{
public:
	virtual void speak() = 0;
	virtual ~Animal() {}
};

//����԰��
class park
{
public:
	park()
	{
		for (int i = 0; i < 20; ++i)
		{
			animal[i] = NULL;
		}

		mSize = 0;
	}

	~park()
	{
		for (int i = 0; i < mSize; ++i)
		{
			delete animal[i];
			animal[i] = NULL;
		}

		mSize = 0;
	}

	void speak()
	{
		cout << "park speak" << endl;
	}

	void addAnimal(Animal *a)
	{
		if (NULL == a)
		{
			return;
		}

		if (this->mSize == 20)
		{
			return;
		}

		this->animal[this->mSize++] = a;
	}

	int Size()
	{
		return mSize;
	}

	Animal *animal[20];
private:
	
	int mSize;
};

class a1: public Animal
{
public:
	void speak()
	{
		cout << "a1��" << endl;
	}
};

class a2 : public Animal
{
public:
	void speak()
	{
		cout << "a2��" << endl;
	}
};

class a3 : public Animal
{
public:
	void speak()
	{
		cout << "a3��" << endl;
	}
};

void test()
{
	//ʵ����һ������԰����
	park p1;
	
	//���Ӷ���
	p1.addAnimal(new a1);
	p1.addAnimal(new a2);
	p1.addAnimal(new a1);
	p1.addAnimal(new a2);
	p1.addAnimal(new a3);

	for (int i = 0; i < p1.Size(); ++i)
	{
		p1.animal[i]->speak();
	}

}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return 0;
}
