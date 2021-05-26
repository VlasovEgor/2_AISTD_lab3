#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include "Floyd.h"

using namespace std;
using namespace Floyd;

void main()
{
	cout << " Enter the path to the file:\n ";
	string Path_File;
	cin >> Path_File;
	vector <string> List_of_Cities;
	vector <vector <double>> Matrix;
	vector <vector <vector <size_t>>> Way;
	Read_File(Matrix, List_of_Cities, Path_File);
	FloydWarshall(Matrix, Way);
	cout << "\n List_of_Cities:\n";
	for (int i = 0; i < List_of_Cities.size(); i++)
		cout << " * " << List_of_Cities[i] << endl;
	cout << "\n departure city - ";
	string First_City;
	cin >> First_City;
	cout << "\n arrival city - ";
	string Last_City;
	cin >> Last_City;
	size_t inFirst_City = Found_City(List_of_Cities, First_City);
	size_t inLast_City = Found_City(List_of_Cities, Last_City);
	if (Matrix[inFirst_City][inLast_City] != numeric_limits<double>::infinity())
	{
		cout << "\n the most profitable flight:  " << First_City;
		for (int i = 0; i < Way[inFirst_City][inLast_City].size(); i++)
		{
			cout << " -> " << List_of_Cities[Way[inFirst_City][inLast_City][i]];
		}
		cout << " -> " << Last_City;
		cout << "\n the cost of the flight: " << Matrix[inFirst_City][inLast_City];
	}
	else
	{
		cout << "\n from the city" << First_City << " in the city " << Last_City << " no paths";
	}
}
