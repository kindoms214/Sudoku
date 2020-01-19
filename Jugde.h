#pragma once

#ifndef _JUDGE_H
#define _JUDGE_H

#include<iostream>
#include<string.h>
using namespace std;

class judge
{
private:
public:
	int JudgeCommand(const char * argv);
};

int judge::JudgeCommand(const char * argv)
{	
	if (strcmp(argv, "-c") == 0 || strcmp(argv, "-s") == 0 || strcmp(argv, "-g") == 0)
	{
		return 0;
	}
	else
	{	
		return 1;
	}
}

#endif
