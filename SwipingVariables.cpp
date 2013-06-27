#include <windows.h>
#include <iostream>

#define BITMODEs
#define PRINTs

using namespace std;

int main()
{

  {
		double Time;
		__int64 freq, start, end;
		
		if(QueryPerformanceFrequency((_LARGE_INTEGER*)&freq)){
			QueryPerformanceCounter((_LARGE_INTEGER*)&start);

			for(int times = 0 ; times < 1 ; ++times) {

			int x, y;

			x = 2;
			y = 4;

#ifdef PRINT			
			cout << "x : " << x << endl;
			cout << "y : " << y << endl;
			cout << endl;
#endif

#ifdef BITMODE

			for(int i=0 ; i<32 ; ++i) {
				if(((x & (0x01) << i) >> i) == 0x01) {
					if(((y & (0x01) << i) >> i) == 0x00) {
						y |= ((0x01) << i);
						x ^= ((0x01) << i);
					}
				}

				else if(((x & (0x01) << i) >> i) == 0x00) {
					if(((y & (0x01) << i) >> i) == 0x01) {
						y ^= ((0x01) << i);
						x |= ((0x01) << i);
					}
				}
			}

#else

			x = x + y;

			y = x - y;
			x = x - y;

#endif

#ifdef PRINT
			cout << "x : " << x << endl;
			cout << "y : " << y << endl;
#endif
			}

			// Attatch Here
		
			QueryPerformanceCounter((_LARGE_INTEGER*)&end);
			Time = (float)((double)(end - start)/freq); // (°É¸°½Ã°£/freq) : ÃÊ·Î È¯»ê
			Time *= 1000; // Convert Seconds to Milliseconds.
		}		
		cout << "Time : " << Time << "ms" << endl;
	}

}
