#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}
int nCr(int n, int r)
{
	double sum = 1;
	for (int i = 1; i <= r; i++)
	{
		sum = sum * (n - r + i) / i;
	}
	return (int)sum;
}

int main()
{

	int a = 4, b = 8;
	cout << "The GCD of the two numbers is " << gcd(a, b);
}
