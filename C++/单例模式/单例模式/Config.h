#pragma once
#include<iostream>
using namespace std;

//1.����һ����̬��ָ��ǰ���ָ�루private�������ԣ�
//2.����һ����̬��Ա������ͨ���˺�������̬��ָ�뷵�س�ȥ��public�������ԣ�
//3.����Ĺ��캯����������������Ϊprivate�������ԣ�
Config *Config::pConfig = new Config();
class Config
{
public:
	static Config* getInstance();
private:
	Config();
	~Config();
private:
	static Config *pConfig;
};