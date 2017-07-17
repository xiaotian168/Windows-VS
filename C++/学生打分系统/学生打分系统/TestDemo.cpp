#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<ctime>
#include<algorithm>
using namespace std;

class Student
{
public:
	Student(string name = "", int score = 0)
	{
		this->mName = name;
		this->mScore = score;
	}
	bool operator<(const Student &stu)
	{
		return this->mScore < stu.mScore;
	}

public:
	string	mName;
	int		mScore;
};

//创建学生信息
void CreateStudents(vector<Student> &v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		Student stu;
		stu.mScore = 0;
		stu.mName = "学生";
		stu.mName += nameSeed[i];
		v.push_back(stu);
	}
}

//学生打分
void SetScore(vector<Student> &v)
{
	srand((unsigned int)time(NULL));
	for (auto val = v.begin(); val != v.end(); ++val)
	{
		deque<int> saveSorce;
		for (int i = 0; i < 10; ++i)
		{
			int score = rand() % 51 + 50;
			saveSorce.push_back(score);
		}

		sort(saveSorce.begin(), saveSorce.end());	//排序
		//去除最高分和最低分
		saveSorce.pop_back();
		saveSorce.pop_front();

		for (auto dval : saveSorce)
		{
			val->mScore += dval;
		}

		val->mScore /= saveSorce.size();
	}

}


//显示学生信息
void ShowStudents(vector<Student> &v)
{
	//排序；从小到大
	sort(v.begin(), v.end());
	for (auto val : v)
	{
		cout << "name:" << val.mName << "\tscore:" << val.mScore << endl;
	}

}

//3. 评委打分案例
void test()
{
	vector<Student> v;
	CreateStudents(v);
	SetScore(v);
	ShowStudents(v);

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
