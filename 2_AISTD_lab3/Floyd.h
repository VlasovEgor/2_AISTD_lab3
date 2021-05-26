#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <iomanip>
using namespace std;

namespace Floyd
{
	int Found_City(const vector <string>& List_of_Cities, string city)
	{
		for (int i = 0; i < List_of_Cities.size(); i++)
		{
			if (List_of_Cities[i] == city) return i;
		}
		return -1;
	}

	void FloydWarshall(vector <vector <double>>& Matrix, vector <vector<vector <size_t>>>& Way)
	{
		Way.resize(Matrix.size());
		for (int i = 0; i < Matrix.size(); i++)
			Way[i].resize(Matrix[i].size());
		for (int k = 0; k < Matrix.size(); k++)
		{
			for (int i = 0; i < Matrix.size(); i++)
			{
				for (int j = 0; j < Matrix.size(); j++)
				{
					if (Matrix[i][j] > Matrix[i][k] + Matrix[k][j])
					{
						Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
						Way[i][j].push_back(k);
					}
				}
			}
		}
	}
	void Read_File(vector <vector <double>>& Matrix, vector <string>& List_of_Cities, string Path_File)
	{
		double first_Cost;
		double second_Cost;
		ifstream File(Path_File);
		string Data;
		size_t indexFirstCity, indexSecondCity;
		if (!File.is_open())
		{
			cout << "unable to open" << endl;
			exit(0);
		}
		while (!File.eof())
		{
			getline(File, Data);
			if (Data.empty()) break;
			size_t first_sign = Data.find(';');
			size_t second_sign = Data.find(';', first_sign + 1);
			size_t third_sign = Data.find(';', second_sign + 1);
			string First_City = Data.substr(0, first_sign);
			string Last_City = Data.substr(first_sign + 1, second_sign - first_sign - 1);
			string strFirstCost = Data.substr(	 + 1, third_sign - second_sign - 1);
			string strSecondCost = Data.substr(third_sign + 1);

			if (strFirstCost != "N/A")
				first_Cost = atof(strFirstCost.c_str());
			else
				first_Cost = 99999999999;

			if (strSecondCost != "N/A")
				second_Cost = atof(strSecondCost.c_str());
			else
				second_Cost =9999999999;
			//if name of first city is not dound in list
			if (Found_City(List_of_Cities, First_City) == -1)
			{	
				cout << "enter a city from the list" << endl;
				List_of_Cities.push_back(First_City);
				Matrix.push_back({});
				for (int i = 0; i < List_of_Cities.size(); i++)
					if (i != List_of_Cities.size() - 1) 
						Matrix[List_of_Cities.size() - 1].push_back(numeric_limits<double>::infinity());
					else Matrix[List_of_Cities.size() - 1].push_back(0);
				for (int i = 0; i < List_of_Cities.size() - 1; i++)
					Matrix[i].push_back(numeric_limits<double>::infinity());
			}
			indexFirstCity = Found_City(List_of_Cities, First_City);
			if (Found_City(List_of_Cities, Last_City) == -1)
			{
				List_of_Cities.push_back(Last_City);
				Matrix.push_back({});
				for (int i = 0; i < List_of_Cities.size(); i++)
					if (i != List_of_Cities.size() - 1) 
						Matrix[List_of_Cities.size() - 1].push_back(numeric_limits<double>::infinity());
					else Matrix[List_of_Cities.size() - 1].push_back(0);
				for (int i = 0; i < List_of_Cities.size() - 1; i++)
					Matrix[i].push_back(numeric_limits<double>::infinity());
			}
			indexSecondCity = Found_City(List_of_Cities, Last_City);
			Matrix[indexFirstCity][indexSecondCity] = first_Cost;
			Matrix[indexSecondCity][indexFirstCity] = second_Cost;
		}
	}
}