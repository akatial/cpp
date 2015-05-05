#include <iostream>
using namespace std; 

// 演算（全ループ）の回数
extern int count;
 
// インクリメントのルーチン
extern void increment();
 
// 九九ルーチン
int main() 
{
	int i;
	int j;
	for (i = 1; i <= 9; i++) 
	{
		for (j = 1; j <= 9; j ++) 
		{
			cout << i << " * " << j << " = " << (i * j) << "\n";
			increment();
		}
	}
	cout << count << " 回の計算を行いました。\n";
 
	return 0;
}
