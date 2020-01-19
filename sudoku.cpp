#include "ProduceSudoku.h"
#include "QuesGenerate.h"
#include "SolveSudoku.h"
#include "Judge.h"

int main(int argc, char *argv[])
{	
	if (strcmp(argv[1], "-c") == 0)
	{
		produce soduku;
		cout << "produce soduku" << endl;

		if (soduku.AllisNum(argv[2]) == 0)	//非全数字
		{
			cout << "ERROR PARAMETER, 第二个参数不全为数字" << endl;
			return 0; 
		}
		soduku.ProduceSudoku(atoi(argv[2]));
	}
	else if (strcmp(argv[1], "-s") == 0)
	{
		cout << "solve soduku" << endl;
		Solve soduku;
		soduku.SolveSudoku(argv[2]);
	}
	else if (strcmp(argv[1], "-g") == 0)
	{
		cout << "generate soduku" << endl;
		generate_ques pro;
		pro.QuesGenerate(atoi(argv[2]));
	}
	else
	{	
		cout << "输入的第一个参数有误" << endl;
		return 1;
	}
	//system("pause");
	return 0;
}
