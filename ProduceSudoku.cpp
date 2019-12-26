void ProduceSudoku(int count)
{	
	//int count = 5;
	ofstream out("D:\\A\\软件工程\\sudoku.txt");			//创建流类对象并打开文件
	
	do
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << num[(j + change[i]) % 9] << " ";
				out << num[(j + change[i]) % 9] << " ";
			}
			cout << endl;
			out << endl;
		}
		cout << endl << endl;
		out << endl << endl;
		count--;
	} while (next_permutation(num + 1, num + 9) && count);		//根据全排列生成第一行
	
	out.close();
}
