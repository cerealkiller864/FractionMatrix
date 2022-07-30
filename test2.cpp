#include <iostream>
#include <sstream>

using namespace std;

int gcd(int& a, int& b)
{ //b will always be the greater number
    if (a==0 || b==0) return 0;
	
	int GCD;
	if (a>b) //swapping if a > b
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	for (int i = 1; i <= a; i++)
	{
		if (a%i==0 && b%i==0) {GCD=i;}
	}

	return GCD;
}


int main()
{
 int n1 = -2;
 int n2 = -4;
 cout << gcd(n1, n2);
}
