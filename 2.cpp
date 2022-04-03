#include <iostream>
using namespace std;
	
int main() 
{
	int i;
	int b = 64;
	int a [13] = {2,112,18,54,26,69,65,66,72,255,243,236,376};
	int c [13] = {2,112,18,54,26,69,65,66,72,255,243,236,376};
	
	for(i = 0;i<13;i++)
	{
		a[i] &= b;
		if (a[i] == b)
		{
			c[i] >>= 1;
		}
		
	}
	int d=0;
	for(i = 0;i<13;i++)
	{
		d += c[i];
		
	}
	 	cout << d;
	return 0;
}
