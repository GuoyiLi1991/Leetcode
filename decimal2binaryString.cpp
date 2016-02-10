#include <iostream>
#include <cstring>

using namespace std;

string Decimal2Binary(int n)
{
	string binary = "";
	int mask = 1;

	//assume 32 bit decimal number
	for (int i =0; i<31; i++)
	{
		if((mask & n) == 0) 
			binary = "0" +binary;
		else 
			binary = "1" + binary;

		mask <<= 1;
	}

	cout <<binary <<endl;
	return binary;
}

int main()
{
	cout <<"INT_MAX = "<<INT_MAX <<endl;
	int n;
	while (cin >> n)
		Decimal2Binary(n);
}