#include "pch.h"
#include "CppUnitTest.h"
#include "..//Floyd.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Floyd;

namespace Lab3Test
{
	TEST_CLASS(Lab3Test)
	{
	public:
		
		TEST_METHOD(ReadFromFile)
		{
			string Path_File = "C:\txt.txt";
			vector <string> List_of_Cities;
			vector <vector <double>> Matrix;
			vector <string> firstAnswer = { "Saint-Petersburg", "Moscow", "London", "Paris" };
			vector <vector <double>> secondAnswer = { {0, 5, numeric_limits<double>::infinity(), 14}, {7, 0, 25, 35}, {numeric_limits<double>::infinity(), 35, 0, 8}, {numeric_limits<double>::infinity(),20, 12, 0} };
			Read_File(Matrix, List_of_Cities, Path_File);
			for (int i = 0; i < List_of_Cities.size(); i++)
			{
				Assert::AreEqual(List_of_Cities[i], firstAnswer[i]);
				for (int j = 0; j < Matrix[i].size(); j++)
					Assert::AreEqual(Matrix[i][j], secondAnswer[i][j]);
			}
		}

		TEST_METHOD(FloydTest)
		{
			string Path_File = "C:\txt.txt";
			vector <string> List_of_Cities;
			vector <vector <double>> Matrix;
			vector <vector <vector <size_t>>> Way;
			Read_File(Matrix, List_of_Cities, Path_File);
			FloydWarshall(Matrix, Way);
			vector <vector <double>> Answer = { {0, 5, 12, 8}, {6, 0, 4, 9}, {10, 6, 0, 8}, {2, 11, 7, 0} };
			for (int i = 0; i < Matrix.size(); i++)
				for (int j = 0; j < Matrix[i].size(); j++)
					Assert::AreEqual(Matrix[i][j], Answer[i][j]);
		}
	};
}
