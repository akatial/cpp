#include <algorithm>
#include <list>
#include <iostream>

class CEqual
{
public:
  CEqual(int num){ m_num = num; }

  // 引数とメンバ変数の値が同じか
  bool operator()(int num) const
  {
    return ( m_num == num );
  }

private:
  int m_num;
};

int main()
{
  using namespace std;
	
  CEqual eq( 1 );
  list<int> nums;
  int i;

  for( i = 0; i < 30; ++i )
    {
      nums.push_back( i / 10 );  // 0～2の値が10個ずつ入る
    }

  // 値が2の要素を10に置き換える
  replace( nums.begin(), nums.end(), 2, 10 );

  // 値がeq.m_numと同じ要素を100に置き換える
  replace_if( nums.begin(), nums.end(), eq, 100 );

  // 結果を出力
  /*
  list<int>::iterator it = nums.begin();
  while( it != nums.end() )
    {
      cout << *it << endl;
      ++it;
    }
  */
  for(int tmp : nums)
    {
      cout << tmp << endl;
    }

  return 0;
}
