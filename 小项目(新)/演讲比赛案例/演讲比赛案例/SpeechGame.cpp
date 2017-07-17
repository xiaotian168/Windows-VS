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

//����ѡ����Ϣ
void CreateSpeakerInfo(map<int, Speaker> &mSpeakersInfo, vector<int> &vSpeakersID)
{
	string nameSeend = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < (int)nameSeend.size(); ++i)
	{
		//����Ψһ�Ĳ������
		int SpeakerId = 100 + i;
		//����ѡ��
		Speaker spk;
		spk.mName = "ѡ��";
		spk.mName += nameSeend[i];
		for (int i = 0; i < sizeof(spk.mScore) / sizeof(spk.mScore[0]); ++i)
		{
			spk.mScore[i] = 0;
		}

		//����ѡ����Ϣ��������
		mSpeakersInfo.insert(make_pair(SpeakerId, spk));
		//�������ѡ�ֱ�ŵ�������
		vSpeakersID.push_back(SpeakerId);
	}
}

//ѡ�ֳ�ǩ��������
void Draw(vector<int> &vSpeakersID)
{
	//�����������
	srand((unsigned int)time(NULL));
	//���Ҳ����б��˳��
	random_shuffle(vSpeakersID.begin(), vSpeakersID.end());
}

//����
void Match(const int &round, map<int, Speaker> &mSpeakersInfo, vector<int> &vSpeakersID, vector<int> &vPromotionList)
{
	srand((unsigned int)time(NULL));
	//���������Ϣmultimap<����,���> Ĭ���Ǵ�С����;����ָ���Ӵ�С
	multimap<int, int, greater<int>> mGroups;

	//��������ѡ���б�
	for (auto &id : vSpeakersID)
	{
		//����10Ϊ��ί�÷���
		deque<int> dScores;
		for (int i = 0; i < 10; ++i)
		{
			//��ί���
			int score = rand() % 50 + 50;
			dScores.push_front(score);	//ͷ�巨����������ݵ�����
		}
		
		//�Է�����������(Ĭ����������)
		sort(dScores.begin(), dScores.end());
		//ȥ����߷�
		dScores.pop_back();
		//ȥ����ͷ�
		dScores.pop_front();
		//��ƽ����
		int avg = accumulate(dScores.begin(), dScores.end(), 0) / dScores.size();
		//���浱ǰѡ�ֵķ���
		mSpeakersInfo[id].mScore[round - 1] = avg;
		//���������Ϣ
		mGroups.insert(make_pair(avg, id));

		//��ÿ����Ա������������
		if (6 == mGroups.size())
		{
			multimap<int, int, greater<int>>::iterator it = mGroups.begin();
			for (int i = 0; i < 3; ++i)
			{
				vPromotionList.push_back(it->second);	//�����������ѡ��ID
				++it;
			}

			//ÿ������ꣻ���mGroups
			mGroups.clear();
		}
	}
}

//�������������Ϣ
void Show(const int &round, map<int, Speaker> &mSpeakersInfo, const vector<int> &vPromotionList)
{
	cout << "��" << round << "�ֱ���������������:" << endl;
	for (auto id : vPromotionList)
	{
		cout << "Name:" << mSpeakersInfo[id].mName << "  Score:" << mSpeakersInfo[id].mScore[round - 1] << endl;
	}
	cout << "---------------" << endl;
}

void test01()
{
	//ʵ����һ������������ѡ����Ϣ<��ţ�ѡ��>
	map<int, Speaker> mSpeakersInfo;
	//ʵ����һ������������ѡ�ֱ��<���>��
	vector<int> vSpeakersID;
	//����ѡ����Ϣ
	CreateSpeakerInfo(mSpeakersInfo, vSpeakersID);


	//�����������
	vector<int> vPromotionListID;
	for (int round = 1; round < 4; ++round)
	{
		//random_shuffle���Ҳ������(��ǩ)
		Draw(vSpeakersID);
		//�μӱ���
		Match(round, mSpeakersInfo, vSpeakersID, vPromotionListID);
		//��ʾ��������
		Show(round, mSpeakersInfo, vPromotionListID);
		//���²���ѡ������
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
