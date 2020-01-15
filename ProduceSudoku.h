#pragma once

#ifndef _PRODUCESODUKU_H
#define _PRODUCESODUKU_H

#include<iostream>
#include<cstring>
#include<math.h>
#include<fstream>
#include<algorithm>
using namespace std;

class produce
{
private:
	char num[9] = { '4','1','2','3','5','6','7','8','9' };	
	int rule_1[2] = { 36,63 };
	int rule_2[6] = { 147,174,417,471,714,741 };
	int rule_3[6] = { 258,285,528,582,825,852 };
	int map[9];			//数独的各行的位移量（相对第一行）
	char ostrfile[163];		//18*9=162，存放生成的数独（单个），每次使用初始化
public:
	void ChangeMap(int num_1, int num_2, int num_3);
	bool AllisNum(string str);
	void ProduceSudoku(int count);
};

//生成转换的数组map，通过rule_1,rule_2,rule_3合并形成
void produce::ChangeMap(int num_1, int num_2, int num_3)
{
	memset(map, 0, sizeof(map));
	for (int i = 0; i < 3; i++)
	{
		int a = pow(10, (2 - i));
		map[i] = num_1 / a;
		num_1 = num_1 % a;
	}
	for (int i = 0; i < 3; i++)
	{
		int a = pow(10, (2 - i));
		map[i + 3] = num_2 / a;
		num_2 = num_2 % a;
	}
	for (int i = 0; i < 3; i++)
	{
		int a = pow(10, (2 - i));
		map[i + 6] = num_3 / a;
		num_3 = num_3 % a;
	}
}

//判断参数是否合理，即是否第二个参数全为数字
//返回值：1——全为数字；0——不全为数字
bool produce::AllisNum(string str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		int tmp = (int)str[i];
		if (tmp >= 48 && tmp <= 57)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

//生成数独部分，包括输出到文件（主要是）
void produce::ProduceSudoku(int count)
{
	ofstream out("D:\\A\\软件工程\\sudoku.txt");			//创建流类对象并打开文件

	while (next_permutation(num + 1, num + 9) && count)
	{	
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				for (int k = 0; k < 6; k++)
				{
					ChangeMap(rule_1[i], rule_2[j], rule_3[k]);
					memset(ostrfile, '0', sizeof(ostrfile));	//用来输出，先初始化
					for (int row = 0; row < 9; row++)
					{
						for (int col = 0; col < 9; col++)
						{
							ostrfile[18 * row + 2 * col] = num[(col + map[row]) % 9];
							if (col != 8)
							{
								ostrfile[18 * row + 2 * col + 1] = ' ';
							}
							else
							{
								//out << endl;
								ostrfile[18 * row + 2 * col + 1] = '\n';
							}
						}
					}
					count--;
					if (count)
					{
						ostrfile[161] = '\n';
					}
					else
					{
					`	ostrfile[161] = '\0';
					}
					ostrfile[162] = '\0';	//每个数独添加一个结尾
					out << ostrfile;
					
					if (!count)
					{
						return;
					}
				}
			}
		}
	}
	out.close();
}

#endif // !1
