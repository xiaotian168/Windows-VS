#include<iostream>
#include<string>
using namespace std;


/*
string();//����һ���յ��ַ��� ����: string str;
string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
string(const char* s);//ʹ���ַ���s��ʼ��
string(int n, char c);//ʹ��n���ַ�c��ʼ��
*/

//1. �ַ�����ʼ��
void test1()
{
	string str1;
	string str2 = "hello world!"; // string str2("hello world!");
	string str3(str2);
	string str4(3, 'a');

	//����
	int len = str2.size();
	for (int i = 0; i < len; ++i)
	{
		cout << str2[i] << " ";
	}
	cout << endl;

	//������ʹ�õ�������
	for (auto pStart = str4.begin(); pStart != str4.end(); ++pStart)
	{
		cout << *pStart << " ";
	}

}

/*
string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s);//���ַ���s������ǰ���ַ���
string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
string& assign(const char *s);//���ַ���s������ǰ���ַ���
string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s);//���ַ���s������ǰ�ַ���
string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
*/

/*
char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
char& at(int n);//ͨ��at������ȡ�ַ�
*/

//2.��ȡ�����ַ�
void test2()
{
	string s1 = "abcd";
	try
	{
		//1.[]
		//cout << s1[5] << "\n";	//�±�Խ�����ֱ����ֹ�������׳��쳣

		//2. at(index)
		cout << s1.at(5) << "\n";	//Խ����׳��쳣��
	}
	catch (exception &e)
	{
		cout << "�±�Խ���쳣!\n";
		cout << e.what() << "\n";
	}

}

/*
string& operator+=(const string& str);//����+=������
string& operator+=(const char* str);//����+=������
string& operator+=(const char c);//����+=������
string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string &s);//ͬoperator+=()
string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c
*/
//3.��ֵ׷��
void test3()
{
	string s1 = "aaa";
	string s2;
	s2 += s1;
	cout << s2 << endl;
	s2 += "bbb";
	cout << s2 << endl;
	s2 += 'g';
	cout << s2 << endl;

	s2.append(3, 'c');
	cout << s2 << endl;
}

/*
int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s

*/

//4.�����滻
void test4()
{
	string s1 = "hello world";
	int pos = s1.find("e");
	//pos = s1.find("0");
	cout << pos << "\n";

	//������ҳɹ������ַ�����һ�γ��ֵ�λ��(��0��ʼ)
	//�������ʧ�ܣ�����-1

	s1.replace(1, 3, "ppp");
	cout << "s = " << s1 << endl;
}

//ע������ʧЧ
void test5()
{
	string s = "aaaa";
	cout << (int)&s[0] << endl;

	char &ref = s[0];

	s += "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	cout << (int)&s[0] << endl;

	//ref = 'p';	//err ����ʧЧ��ԭ�ȵ��ڴ��ͷŵ��ˣ��൱�ڲ���Ұָ��
}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	cout << endl;
	system("pause");
	return 0;
}
