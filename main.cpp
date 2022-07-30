#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <utility>

using namespace std;

int gcd(int& a, int& b)
{
    if (a==0 || b==0) return 0;

	int GCD, n1=abs(a), n2=abs(b);
	if (n1>n2) //n2 must be greater than n1
	{
		int tmp = n1;
		n1 = n2;
		n2 = tmp;
	}

	for (int i = 1; i <= n1; i++)
	{
		if (n1%i==0 && n2%i==0) {GCD=i;}
	}

	return GCD;
}

void reduceFraction(pair<int, int>& p)
{	
	int GCD = gcd(p.first, p.second);
	if (GCD==0 || GCD==1) {return;}
	else
	{
		p.first = (p.first / GCD);
		p.second = (p.second / GCD);
	}
}



void readFraction(string& s, vector<pair<int, int>>& v)
{
	int FIRST, SECOND;
	for (int i=0; i<s.length(); i++)
	{
		if (s[i]=='/')
		{
			FIRST = stoi(s.substr(0, i));
			SECOND = stoi(s.substr(i+1, s.length()-i));
			if (SECOND==0) {cout << "DIVIDE BY 0!"; exit(0);}
			v.push_back(make_pair(FIRST, SECOND));
		}
	}
}

void formatFraction(pair<int, int>& p)
{
	if (p.first>0 && p.second<0) {p.first=-p.first; p.second=-p.second;}
	else if (p.first<0 && p.second<0) {p.first=-p.first; p.second=-p.second;}
}

int main()
{
	ifstream inputfile("input.txt");
	ofstream outputfile("output.txt");
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

	// read matrix
	int size=rows*cols;
	vector<pair<int, int>> mat;
	mat.reserve(size);
	while (getline(inputfile, line))
	{
		istringstream ss(line);
		string fractionString;
		while (ss >> fractionString)
		{
			readFraction(fractionString, mat);
		}
	}

	// check and reduce fractions of matrix
	for (int i=0; i<size; i++)
	{
		reduceFraction(mat[i]);
		formatFraction(mat[i]);
	}

	//write result to outputfile
	for (int i=0; i<size; i++)
	{
		outputfile << mat[i].first << '/' << mat[i].second << ' ';
		if ((i+1)%cols==0) {outputfile << endl;}
	}
	return 0;
}
