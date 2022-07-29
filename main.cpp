#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cmath>
#include <sstream>

using namespace std;

int main()
{
	ifstream inputfile("input.txt");
	ofstream outputfile("output.txt", ios::trunc);
	if (inputfile.good() && outputfile.good())
	{
		cout << "Accessed file successfully" << endl;
	}

	//read number of rows and cols of matrix
	int rows, cols, count=1;
	string line;
	while (count <=2 && getline(inputfile, line))
	{
		istringstream ss(line);
		ss >> ((count==1) ? rows : cols);
		count++;
	}

	vector<float> mat;
	mat.reserve(rows*cols);
	// read matrix
	while (getline(inputfile, line))
	{
		istringstream ss(line);
		double tmp;
		while (ss>>tmp)
		{
			mat.push_back(tmp);
		}
	}
	
	for (auto num : mat) {cout << num << ' ';}
	return 0;
}
