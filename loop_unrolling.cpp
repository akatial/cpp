#include <iostream>
#include <omp.h>

const int N = 100;

using namespace std;

int main(void)
{
  //#pragma omp parallel for
    for( int i = 0 ; i < N ; i++ )
    {
    cout << i << endl;
    }
  /*
  cout << 0 << endl;
  cout << 1 << endl;
  cout << 2 << endl;
  cout << 3 << endl;
  cout << 4 << endl;
  cout << 5 << endl;
  cout << 6 << endl;
  cout << 7 << endl;
  cout << 8 << endl;
  cout << 9 << endl;
  cout << 10 << endl;
  cout << 11 << endl;
  cout << 12 << endl;
  cout << 13 << endl;
  cout << 14 << endl;
  cout << 15 << endl;
  cout << 16 << endl;
  cout << 17 << endl;
  cout << 18 << endl;
  cout << 19 << endl;
  cout << 20 << endl;
  cout << 21 << endl;
  cout << 22 << endl;
  cout << 23 << endl;
  cout << 24 << endl;
  cout << 25 << endl;
  cout << 26 << endl;
  cout << 27 << endl;
  cout << 28 << endl;
  cout << 29 << endl;
  cout << 30 << endl;
  cout << 31 << endl;
  cout << 32 << endl;
  cout << 33 << endl;
  cout << 34 << endl;
  cout << 35 << endl;
  cout << 36 << endl;
  cout << 37 << endl;
  cout << 38 << endl;
  cout << 39 << endl;
  cout << 40 << endl;
  cout << 41 << endl;
  cout << 42 << endl;
  cout << 43 << endl;
  cout << 44 << endl;
  cout << 45 << endl;
  cout << 46 << endl;
  cout << 47 << endl;
  cout << 48 << endl;
  cout << 49 << endl;
  cout << 50 << endl;
  cout << 51 << endl;
  cout << 52 << endl;
  cout << 53 << endl;
  cout << 54 << endl;
  cout << 55 << endl;
  cout << 56 << endl;
  cout << 57 << endl;
  cout << 58 << endl;
  cout << 59 << endl;
  cout << 60 << endl;
  cout << 61 << endl;
  cout << 62 << endl;
  cout << 63 << endl;
  cout << 64 << endl;
  cout << 65 << endl;
  cout << 66 << endl;
  cout << 67 << endl;
  cout << 68 << endl;
  cout << 69 << endl;
  cout << 70 << endl;
  cout << 71 << endl;
  cout << 72 << endl;
  cout << 73 << endl;
  cout << 74 << endl;
  cout << 75 << endl;
  cout << 76 << endl;
  cout << 77 << endl;
  cout << 78 << endl;
  cout << 79 << endl;
  cout << 80 << endl;
  cout << 81 << endl;
  cout << 82 << endl;
  cout << 83 << endl;
  cout << 84 << endl;
  cout << 85 << endl;
  cout << 86 << endl;
  cout << 87 << endl;
  cout << 88 << endl;
  cout << 89 << endl;
  cout << 90 << endl;
  cout << 91 << endl;
  cout << 92 << endl;
  cout << 93 << endl;
  cout << 94 << endl;
  cout << 95 << endl;
  cout << 96 << endl;
  cout << 97 << endl;
  cout << 98 << endl;
  cout << 99 << endl;
  */
  return 0;
}
