#pragma once

#ifndef _PRODUCESODUKU_H
#define _PRODUCESODUKU_H

#include<iostream>
#include<math.h>
#include<fstream>
#include<algorithm>
using namespace std;

int num[9] = { 4,1,2,3,5,6,7,8,9 };
int rule_1[2] = { 36,63 };
int rule_2[6] = { 147,174,417,471,714,741 };
int rule_3[6] = { 258,285,528,582,825,852 };
int map[9];

/*生成转换的数组map*/
void ChangeMap(int num_1, int num_2, int num_3)
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

void ProduceSudoku(int count)
{
	//int count = 5;
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
					for (int row = 0; row < 9; row++)
					{
						for (int col = 0; col < 9; col++)
						{
							//cout << num[(j + map[i]) % 9] << " ";
							out << num[(col + map[row]) % 9] << " ";
						}
						//cout << endl;
						out << endl;
					}
					//cout << endl << endl;
					out << endl << endl;
					count--;
					cout << count << endl;
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
