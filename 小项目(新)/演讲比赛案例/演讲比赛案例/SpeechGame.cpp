#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<deque>
#include<numeric>
#include<algorithm>
#include<functional>
#include<ctime>
using namespace std;

class Speaker
{
public:
	string	mName;
	int		mScore[3];
};

//生成选手信息
void CreateSpeakerInfo(map<int, Speaker> &mSpeakersInfo, vector<int> &vSpeakersID)
{
	string nameSeend = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < (int)nameSeend.size(); ++i)
	{
		//生成唯一的参数编号
		int SpeakerId = 100 + i;
		//创建选手
		Speaker spk;
		spk.mName = "选手";
		spk.mName += nameSeend[i];
		for (int i = 0; i < sizeof(spk.mScore) / sizeof(spk.mScore[0]); ++i)
		{
			spk.mScore[i] = 0;
		}

		//保存选手信息到容器中
		mSpeakersInfo.insert(make_pair(SpeakerId, spk));
		//保存参赛选手编号到容器中
		vSpeakersID.push_back(SpeakerId);
	}
}

//选手抽签决定比赛
void Draw(vector<int> &vSpeakersID)
{
	//设置随机种子
	srand((unsigned int)time(NULL));
	//打乱参赛列表的顺序
	random_shuffle(vSpeakersID.begin(), vSpeakersID.end());
}

//比赛
void Match(const int &round, map<int, Speaker> &mSpeakersInfo, vector<int> &vSpeakersID, vector<int> &vPromotionList)
{
	srand((unsigned int)time(NULL));
	//保存分组信息multimap<分数,编号> 默认是从小到大;下面指定从大到小
	multimap<int, int, greater<int>> mGroups;

	//遍历参数选手列表
	for (auto &id : vSpeakersID)
	{
		//保存10为评委得分数
		deque<int> dScores;
		for (int i = 0; i < 10; ++i)
		{
			//评委打分
			int score = rand() % 50 + 50;
			dScores.push_front(score);	//头插法保存分数数据到容器
		}
		
		//对分数进行排序(默认升序排列)
		sort(dScores.begin(), dScores.end());
		//去除最高分
		dScores.pop_back();
		//去除最低分
		dScores.pop_front();
		//求平均分
		int avg = accumulate(dScores.begin(), dScores.end(), 0) / dScores.size();
		//保存当前选手的分数
		mSpeakersInfo[id].mScore[round - 1] = avg;
		//保存分组信息
		mGroups.insert(make_pair(avg, id));

		//对每组人员进行排名晋级
		if (6 == mGroups.size())
		{
			multimap<int, int, greater<int>>::iterator it = mGroups.begin();
			for (int i = 0; i < 3; ++i)
			{
				vPromotionList.push_back(it->second);	//保存晋级名单选手ID
				++it;
			}

			//每组晋级完；清空mGroups
			mGroups.clear();
		}
	}
}

//输出晋级名单信息
void Show(const int &round, map<int, Speaker> &mSpeakersInfo, const vector<int> &vPromotionList)
{
	cout << "第" << round << "轮比赛晋级名单如下:" << endl;
	for (auto id : vPromotionList)
	{
		cout << "Name:" << mSpeakersInfo[id].mName << "  Score:" << mSpeakersInfo[id].mScore[round - 1] << endl;
	}
	cout << "---------------" << endl;
}

void test01()
{
	//实例化一个容器；保存选手信息<编号，选手>
	map<int, Speaker> mSpeakersInfo;
	//实例化一个容器；保存选手编号<编号>；
	vector<int> vSpeakersID;
	//创建选手信息
	CreateSpeakerInfo(mSpeakersInfo, vSpeakersID);


	//保存晋级名单
	vector<int> vPromotionListID;
	for (int round = 1; round < 4; ++round)
	{
		//random_shuffle打乱参赛编号(抽签)
		Draw(vSpeakersID);
		//参加比赛
		Match(round, mSpeakersInfo, vSpeakersID, vPromotionListID);
		//显示晋级名单
		Show(round, mSpeakersInfo, vPromotionListID);
		//更新参赛选手名单
		swap(vSpeakersID, vPromotionListID);
		vPromotionListID.clear();
	}
}

int main()
{
	/*******************************************************/
	/*

	*/
	/*******************************************************/
	test01();
	
	system("pause");
	return 0;
}
