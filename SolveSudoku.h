#pragma once
#ifndef _SOLVESUDOKU_H
#define _SOLVESUDOKU_H

#include<iostream>
#include<math.h>
#include<fstream>
#include<algorithm>
using namespace std;

class Solve
{
private:
	int solve_sudoku[9][9];
	bool sign = false;
	char re_sudoku[163] = {'0'};	//存输出
public:
	int SolveSudoku(const char * argv);
	bool Check(int n, int key);
	int DFS(int n);
	void OutputSudoku();
	int pcheck(const char * argv);
};

int Solve::pcheck(const char * argv)
{
	fstream f;
	f.open(argv, ios::in);
	if (!f)
	{
		cout << "文件不存在" << endl;
		return 0;
	}
	else
	{
		cout << "文件已经存在" << endl;
		return 1;
	}
}

int Solve::SolveSudoku(const char * argv)
{	
	ifstream ProblemOfSudoku(argv);		//打开文件
	ofstream out("../sudoku.txt");			//创建流类对象并打开文件

	const int LINE_LENGTH = 100;
	char str[LINE_LENGTH];
	int linecount = 0;

	//读数独题目
	while (ProblemOfSudoku.getline(str, LINE_LENGTH))				//读数独终局
	{
		int ll = strlen(str);
		for (int i = 0; i < ll; i++)
		{
			if (i % 2 == 0)
			{
				solve_sudoku[linecount][i / 2] = str[i] - '0';
			}
		}
		linecount++;

		if (linecount % 9 == 0)
		{	
			linecount = 0;
			DFS(0);
			//OutputSudoku();
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					re_sudoku[i * 18 + j * 2] = solve_sudoku[i][j]+'0';
					if (j != 8)
					{
						re_sudoku[i * 18 + j * 2 + 1] = ' ';
					}
					else
						re_sudoku[i * 18 + j * 2 + 1] = '\n';
				}
			}
			re_sudoku[162] = '\0';
			out << re_sudoku;
			sign = false;
			memset(solve_sudoku, 0, sizeof(solve_sudoku));
		}
	}
	return 0;
}

/* 判断key填入n时是否满足条件 */
bool Solve::Check(int n, int key)
{
	/* 判断n所在横列是否合法 */
	for (int i = 0; i < 9; i++)
	{
		/* j为n竖坐标 */
		int j = n / 9;
		if (solve_sudoku[j][i] == key) return false;
	}

	/* 判断n所在竖列是否合法 */
	for (int i = 0; i < 9; i++)
	{
		/* j为n横坐标 */
		int j = n % 9;
		if (solve_sudoku[i][j] == key) return false;
	}

	/* x为n所在的小九宫格左顶点竖坐标 */
	int x = n / 9 / 3 * 3;

	/* y为n所在的小九宫格左顶点横坐标 */
	int y = n % 9 / 3 * 3;

	/* 判断n所在的小九宫格是否合法 */
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (solve_sudoku[i][j] == key) return false;
		}
	}
	/* 全部合法，返回正确 */
	return true;
}

/* 深搜构造数独 */
int Solve::DFS(int n)
{
	/* 所有的都符合，退出递归 */
	if (n > 80)
	{
		sign = true;
		return 0;
	}
	/* 当前位不为空时跳过 */
	if (solve_sudoku[n / 9][n % 9] != 0)
	{
		DFS(n + 1);
	}
	else
	{
		/* 否则对当前位进行枚举测试 */
		for (int i = 1; i <= 9; i++)
		{
			/* 满足条件时填入数字 */
			if (Check(n, i) == true)
			{
				solve_sudoku[n / 9][n % 9] = i;
				/* 继续搜索 */
				DFS(n + 1);
				/* 返回时如果构造成功，则直接退出 */
				if (sign == true) return 0;
				/* 如果构造不成功，还原当前位 */
				solve_sudoku[n / 9][n % 9] = 0;
			}
		}
	}
	return 0;
}

/*输出求解完的数独*/
void Solve::OutputSudoku()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << solve_sudoku[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

#endif // !SOLVESUDOKU
