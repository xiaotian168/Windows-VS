#include<iostream>
#include<string>
using namespace std;


/*
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化
*/

//1. 字符串初始化
void test1()
{
	string str1;
	string str2 = "hello world!"; // string str2("hello world!");
	string str3(str2);
	string str4(3, 'a');

	//遍历
	int len = str2.size();
	for (int i = 0; i < len; ++i)
	{
		cout << str2[i] << " ";
	}
	cout << endl;

	//遍历（使用迭代器）
	for (auto pStart = str4.begin(); pStart != str4.end(); ++pStart)
	{
		cout << *pStart << " ";
	}

}

/*
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
*/

/*
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/

//2.获取单个字符
void test2()
{
	string s1 = "abcd";
	try
	{
		//1.[]
		//cout << s1[5] << "\n";	//下标越界程序直接终止；不会抛出异常

		//2. at(index)
		cout << s1.at(5) << "\n";	//越界会抛出异常；
	}
	catch (exception &e)
	{
		cout << "下标越界异常!\n";
		cout << e.what() << "\n";
	}

}

/*
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c
*/
//3.赋值追加
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
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s

*/

//4.查找替换
void test4()
{
	string s1 = "hello world";
	int pos = s1.find("e");
	//pos = s1.find("0");
	cout << pos << "\n";

	//如果查找成功返回字符串第一次出现的位置(从0开始)
	//如果查找失败，返回-1

	s1.replace(1, 3, "ppp");
	cout << "s = " << s1 << endl;
}

//注意引用失效
void test5()
{
	string s = "aaaa";
	cout << (int)&s[0] << endl;

	char &ref = s[0];

	s += "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	cout << (int)&s[0] << endl;

	//ref = 'p';	//err 引用失效；原先的内存释放掉了；相当于操作野指针
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
