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

//����ѧ����Ϣ
void CreateStudents(vector<Student> &v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		Student stu;
		stu.mScore = 0;
		stu.mName = "ѧ��";
		stu.mName += nameSeed[i];
		v.push_back(stu);
	}
}

//ѧ�����
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

		sort(saveSorce.begin(), saveSorce.end());	//����
		//ȥ����߷ֺ���ͷ�
		saveSorce.pop_back();
		saveSorce.pop_front();

		for (auto dval : saveSorce)
		{
			val->mScore += dval;
		}

		val->mScore /= saveSorce.size();
	}

}


//��ʾѧ����Ϣ
void ShowStudents(vector<Student> &v)
{
	//���򣻴�С����
	sort(v.begin(), v.end());
	for (auto val : v)
	{
		cout << "name:" << val.mName << "\tscore:" << val.mScore << endl;
	}

}

//3. ��ί��ְ���
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
