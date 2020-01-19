#include "stdafx.h"
#include "CppUnitTest.h"
#include "../re/ProduceSudoku.h"
#include "../re/Judge.h"
#include "../re/QuesGenerate.h"
#include "../re/SolveSudoku.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest01
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			produce soduku1;
			int re = soduku1.AllisNum("1213");
			Assert::AreEqual(re, 1);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			produce soduku2;
			int re = soduku2.AllisNum("-10");
			Assert::AreEqual(re, 1);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			produce soduku3;
			int re = soduku3.AllisNum("abc");
			Assert::AreEqual(re, 1);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			produce soduku4;
			int re = soduku4.ProduceSudoku(0);
			Assert::AreEqual(re, 0);
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			produce soduku5;
			int re = soduku5.ProduceSudoku(1);
			Assert::AreEqual(re, 0);
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: 在此输入测试代码
			produce soduku6;
			int re = soduku6.ProduceSudoku(999999);
			Assert::AreEqual(re, 0);
		}
		TEST_METHOD(TestMethod7)
		{
			// TODO: 在此输入测试代码
			produce soduku7;
			int re = soduku7.ProduceSudoku(1000000);
			Assert::AreEqual(re, 0);
		}
		TEST_METHOD(TestMethod8)
		{
			// TODO: 在此输入测试代码
			produce soduku8;
			int re = soduku8.ProduceSudoku(1000000);
			Assert::AreEqual(re, 0);
		}
		TEST_METHOD(TestMethod9)
		{
			// TODO: 在此输入测试代码
			judge j;
			int re = j.JudgeCommand("-c");
			Assert::AreEqual(re, 0);
		}	
		TEST_METHOD(TestMethod10)
		{
			// TODO: 在此输入测试代码
			judge j;
			int re = j.JudgeCommand("-s");
			Assert::AreEqual(re, 0);
		}
		TEST_METHOD(TestMethod11)
		{
			// TODO: 在此输入测试代码
			judge j;
			int re = j.JudgeCommand("-g");
			Assert::AreEqual(re, 0);
		}
		TEST_METHOD(TestMethod12)
		{
			// TODO: 在此输入测试代码
			judge j;
			int re = j.JudgeCommand("-v");
			Assert::AreEqual(re, 0);
		}
		TEST_METHOD(TestMethod13)
		{
			// TODO: 在此输入测试代码
			Solve s;
			int re = s.pcheck("D:\\A\\软件工程\\pro.txt");
			Assert::AreEqual(re, 1);
		}
		TEST_METHOD(TestMethod14)
		{
			// TODO: 在此输入测试代码
			Solve s;
			int re = s.pcheck("D:\\A\\软件工程\\1.txt");
			Assert::AreEqual(re, 1);
		}
		TEST_METHOD(TestMethod15)
		{
			// TODO: 在此输入测试代码
			Solve s;
			int re = s.SolveSudoku("D:\\A\\软件工程\\pro.txt");
			Assert::AreEqual(re, 0);
		}
	};
}
