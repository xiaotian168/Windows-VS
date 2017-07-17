#include<iostream>
#include<string>
using namespace std;

struct Person
{
	Person(string name = "", int age = 0) { this->name = name; this->age = age; }
	string name;
	int age;
};

bool myCompare(const Person &p1, const Person &p2)	//p1���򷵻��棻���򷵻ؼ�
{
	return p1.age > p2.age ? true : false;
}

template<class T, class _CallBack>
void Sort(T a[], int size, _CallBack fun)
{
	if (size <= 0 )
	{
		return;
	}

	for (int i = 1; i < size; ++i)
	{
		if (fun(a[i], a[i - 1]))	//����
		{
			T temp = a[i];
			int j = 0;
			for (j = i - 1; j >= 0 && fun(temp, a[j]); --j)
			{
				if (fun(temp, a[j]))
				{
					a[j+1] = a[j];
				}
			}
			a[j+1] = temp;
		}
	}
}

//ʹ�÷º���(��������)
struct CompareClass
{
	bool operator()(const Person& p1, const Person& p2)
	{
		return p1.age > p2.age;
	}
};

void test()
{
	Person arr[5];
	arr[0] = Person("aaa", 10);
	arr[1] = Person("bbb", 60);
	arr[2] = Person("ccc", 30);
	arr[3] = Person("ddd", 20);
	arr[4] = Person("eee", 50);

	int size = sizeof(arr) / sizeof(*arr);

	//1.ʹ�ú���ָ�루�ص�������
	//Sort<Person>(arr, size, myCompare);

	//2.ʹ�ú������󣨷º�����α������
	Sort<Person>(arr, size, CompareClass());

	for (int i = 0; i < size; ++i)
	{
		cout << "name: " << arr[i].name << "\tage: " << arr[i].age << endl;
	}

}


int main()
{
	/*******************************************************/
	/*
		����
			ʹ��ģ��ʵ�ֲ�������
	*/
	/*******************************************************/
	test();

	cout << endl;
	system("pause");
	return 0;
}
