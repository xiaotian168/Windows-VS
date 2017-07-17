#include"Config.h"

Config *Config::pConfig = new Config();
Config::Config()
{

}

Config* Config::getInstance()
{
	return pConfig;
}

Config::~Config()
{

}