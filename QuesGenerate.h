#pragma once

#ifndef _QUESGENERATE_H
#define _QUESGENERATE_H

#include<iostream>
#include<math.h>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<algorithm>
using namespace std;

class generate_ques
{
private:
	char delete_sudoku[163];
public:
	void QuesGenerate(int cont);
	void DeleteNumber();
};

void generate_ques::QuesGenerate(int cont)
{
	ifstream fin("../sudoku.txt");
	const int LINE_LENGTH = 100;
	char str[LINE_LENGTH];
	int linecount = 0;

	ofstream out("../pro_sudoku.txt");			//创建流类对象并打开文件
	while (fin.getline(str, LINE_LENGTH))				//读数独终局
	{	
		int ll = strlen(str);
		for (int i = 0; i < ll; i++)
		{
			delete_sudoku[linecount * 18 + i] = str[i];
		}
		linecount++;
		delete_sudoku[linecount * 17 + linecount - 1] = '\n';

		if (linecount % 9 == 0)
		{	
			cont--;
			linecount = 0;
			if (cont)
			{
				delete_sudoku[161] = '\n';
			}
			else
			{
				delete_sudoku[161] = '\0';
			}
			delete_sudoku[162] = '\0';

			//读完一整个数独，开始挖空
			DeleteNumber();
			out << delete_sudoku;
			memset(delete_sudoku, '0', sizeof(delete_sudoku));
		}
	}
	out.close();
}

void generate_ques::DeleteNumber()
{
	//先在每个宫取出两个
	for (int k = 0; k < 9; k++)
	{
		int hole[2];//3*3里面掏的位置
		hole[0] = rand() % 9;
		hole[1] = rand() % 9;

		//随机生成两个空
		while (k == 0 && hole[0] == 0)	//防止左上角的数被删掉
		{
			hole[0] = rand() % 9;
		}
		while (k == 0 && hole[1] == 0)	//防止左上角的数被删掉
		{
			hole[1] = rand() % 9;
		}
		while (hole[0] == hole[1])//防止重复
		{
			hole[1] = rand() % 9;
		}
		delete_sudoku[(3 * (k / 3) + hole[0] / 3) * 18 + (3 * (k % 3) + hole[0] % 3) * 2] = '0';
		delete_sudoku[(3 * (k / 3) + hole[1] / 3) * 18 + (3 * (k % 3) + hole[1] % 3) * 2] = '0';
	}

	//还需要取出12-42个
	int additional;
	additional = 12 + rand() % 31;	//决定要取的个数

	while (additional--)
	{
		int k = rand() % 81;
		int i = k / 9;
		int j = k % 9;

		//j *= 2;
		if (delete_sudoku[i * 18 + j] != '0' && (i + j) != 0)
		{
			delete_sudoku[i * 18 + j * 2] = '0';
		}
		else
		{
			additional++;
		}
	}
}

#endif
