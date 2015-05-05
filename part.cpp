#include <iostream>

typedef unsigned long long ull;
// 変数Nは二次元配列memoの縦と横の大きさ
const int N = 100;
// 変数memo[n][a]はnをa以下の整数和で表現する場合の数
ull memo[N][N];
// 変数cnt1は関数part1を呼び出した回数 
ull cnt1;
// 変数cnt2は関数part2を呼び出した回数
ull cnt2;

// 関数part3は分割数を動的計画法(漸化式)で計算
ull part3(ull m)
{
 ull n, a;
 for ( a = 0 ; a <= m ; a++ )
   memo[0][a] = 1;
 for ( n = 0 ; n <= m ; n++ )
   memo[n][1] = 1;
 for ( n = 1 ; n <= m ; n++ )
   {
   for (a = 2 ; a <= m ; a++ )
     {
       memo[n][a] = memo[n][a-1];
       if ( n >= a )
	 memo[n][a] += memo[n-a][a];
     }
   }
 return memo[m][m];
}

// 関数part1と関数part2はnをa以下の整数和で表現する場合の数を返す
// 関数part1はメモ化なし 関数part2はメモ化あり
ull part2(ull n, ull a)
{
  //std::cout << n << " " << a << std::endl;
  cnt2++;
  if ( memo[n][a] ) return memo[n][a];
  ull ret;
  if ( n == 0 || a == 1 )
    return 1;
  ret = part2(n, a-1);
  if (n >= a )
    ret += part2(n-a, a);
  return memo[n][a] = ret;
}

ull part1(ull n, ull a)
{
  //std::cout << n << " " << a << std::endl;
  cnt1++;
  ull ret;
  if ( n == 0 || a == 1 )
    return 1;
  ret = part1(n, a-1);
  if ( n >= a )
    ret += part1(n-a, a);
  return ret;
}

int main()
{
  ull n;
  std::cin >> n;
  /*std::cout << part1(n, n) << std::endl;
  std::cout << cnt1 << std::endl;
  std::cout << part2(n, n) << std::endl;
  std::cout << cnt2 << std::endl;*/
  std::cout << part3(n) << std::endl;
  return 0;
}
