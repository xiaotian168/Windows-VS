#pragma once
#include<iostream>
using namespace std;

//1.定义一个静态的指向当前类的指针（private访问属性）
//2.定义一个静态成员函数；通过此函数将静态的指针返回出去（public访问属性）
//3.将类的构造函数、析构函数定义为private访问属性；
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