#pragma once

#ifndef _QUESFENERATE_H
#define _QUESFENERATE_H

#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>
#include<algorithm>
using namespace std;

int delete_sudoku[9][9];

void QuesGenerate(int cont);
void DeleteNumber();
void OutputQues();

void QuesGenerate(int cont)
{
	char single_character;
	int s_count = 0, row = 0, col = 0;
	int localnum = 0;
	ifstream ProblemOfSudoku("D:\\A\\软件工程\\sudoku.txt");

	//读数独题目
	ProblemOfSudoku >> single_character;
	while (!ProblemOfSudoku.eof() && localnum != cont)
	{	
		//cout << s_count << endl;
		if (ProblemOfSudoku.good()) 
		{
			if (single_character <= '9'&& single_character >= '0')	//判断是否是有效数独数字（0表示该位为空）
			{
				s_count++;
				delete_sudoku[row][col] = single_character - '0';
				col++;
				if (s_count % 9 == 0)
				{
					row++;
					col = 0;
				}
			}

			//读出一整个，进行数独的求解
			if (s_count % 81 == 0)
			{	
				ProblemOfSudoku >> single_character;
				s_count = 0;
				//cout << s_count << endl;
				row = 0, col = 0;
				//OutputQues();

				//生成题目
				if (localnum != cont )
				{
					DeleteNumber();
					localnum++;
					//memset(delete_sudoku, 0, sizeof(delete_sudoku));
					continue;
				}
				else
				{
					return;
				}
				//cout << "shu: " << localnum << "  " << cont << endl;
			}
			
		}ProblemOfSudoku >> single_character;
	}
	//cout << s_count << endl;
}

//delete_sudoku[9][9];
void DeleteNumber()
{	
	//先在每个宫取出两个
	for (int k = 0; k < 9; k++)
	{
		int i, j, hole[2];//3*3里面掏的位置
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
		//cout << k << "  " << hole[0] << "   " << hole[1] << endl;

		delete_sudoku[3 * (k / 3) + hole[0] / 3][3 * (k % 3) + hole[0] % 3] = 0;
		delete_sudoku[3 * (k / 3) + hole[1] / 3][3 * (k % 3) + hole[1] % 3] = 0;

		//cout << "re:" << 3 * (k / 3) + hole[0] / 3 << "  " << 3 * (k % 3) + hole[0] % 3 << endl;
	}

	//还需要取出12-42个
	int additional;
	additional = 12 + rand() % 31;	//决定要取的个数

	while (additional--)
	{
		int k = rand() % 81;
		int i = k / 9;
		int j = k % 9;

		j *= 2;
		if (delete_sudoku[i][j] != 0 && i != 0 && j != 0)
			delete_sudoku[i][j] = 0;
		else additional++;
	}
	OutputQues();
}

void OutputQues()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << delete_sudoku[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

#endif
