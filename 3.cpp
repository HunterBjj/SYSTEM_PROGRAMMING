#include <iostream>
 #include <stdlib.h>
 using namespace std;
 int main()
 {
    setlocale(LC_ALL, "Russian");
    int a = rand();
    int m[a];
    int b = 1;
    int c = a/2;
        for(int i = 0;i < a; ++i )
        {
        	if (i<c)
        	{
        		m[i] = b;
        		b++;
        	}
        	else
			{
				m[i] = b;
				b--;
        	}
        }
        for(int i = 0; i < a; ++i)
            {
            	cout << "Значение элемента массива m[" << i << "] = " << m[i] << "\n";
            }
    delete [] m;
    return 0;
 }
