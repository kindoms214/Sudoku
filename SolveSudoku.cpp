void SolveSudoku()
{	
	char single_character;
	int s_count = 0, row = 0, col = 0;
	ifstream ProblemOfSudoku("D:\\A\\软件工程\\Sudoku\\sudoku.txt");

	//读数独题目
	ProblemOfSudoku >> single_character;
	while (!ProblemOfSudoku.eof()) {
		if (ProblemOfSudoku.good()) {
			if (single_character <= '9'&& single_character >= '0')	//判断是否是有效数独数字（0表示该位为空）
			{
				s_count++;
				solve_sudoku[row][col] = single_character - '0';
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
				row = 0, col = 0;

				//调用一次DFS()求解数独函数
				DFS(0);
				OutputSudoku();
			}
			ProblemOfSudoku >> single_character;
		}
	}
	cout << s_count << endl;
}

/* 判断key填入n时是否满足条件 */
bool Check(int n, int key)
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
int DFS(int n)
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
}

/*输出求解完的数独*/
void OutputSudoku()
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
