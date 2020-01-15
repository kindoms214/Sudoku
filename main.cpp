#include"ProduceSoduku.h"

int main(int argc, char *argv[])
{
			//int a;
			//produce soduku;
			//soduku.ProduceSudoku(1000000);
	
			if (strcmp(argv[1], "-c") == 0)
			{	
						produce soduku;
						cout << "produce soduku" << endl;
						if (soduku.AllisNum(argv[2]) == 0)	//非全数字
						{
										cout << "ERROR PARAMETER" << endl;
										return 0;
						}
						soduku.ProduceSudoku(atoi(argv[2]));
						//soduku.ProduceSudoku(100000);
			}
			else if (strcmp(argv[1], "-s") == 0)
			{	
						cout << "solve" << endl;
						//SolveSudoku();
			}
	
			//cin >> a;
			return 0;
}
