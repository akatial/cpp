#pragma warning(disable:4786)  // VisualC++6.0の警告対策
#include <set>
#include <iostream>

int main()
{
	using namespace std;

	set<int> nums;  // 空のset

	// 要素を追加する
	nums.insert( 200 );
	nums.insert( 500 );
	nums.insert( 100 );
	nums.insert( 400 );
	nums.insert( 300 );

	// 要素を出力する
	set<int>::iterator it = nums.begin();
	while( it != nums.end() )
	{
		cout << *it << endl;
		++it;
	}

	// 要素数を出力する
	cout << "要素数：" << (unsigned int)nums.size() << endl;

	// 要素の全削除
	nums.clear();

	// 全削除されているか確認
	if( nums.empty() )
	{
		cout << "空です" << endl;
	}

	return 0;
}

/*

C++ セット(std::set)

C++ セットは順序づけられたオブジェクトの集合を保持する連想コンテナである。
begin() 	セットの先頭を指すイテレータを返す
clear() 	全ての要素を削除する
count() 	一致する要素の数を返す
empty() 	セットが空なら真
end() 	セットの末尾を指すイテレータを返す
equal_range() 	特定のキーと一致する先頭・末尾要素を指すイテレータを返す
erase() 	要素を削除する
find() 	要素を検索する
get_allocator() 	セットのアロケータを返す
insert() 	要素を挿入する
key_comp() 	キーを比較する関数を返す
lower_bound() 	特定の値以上である最初の要素を指すイテレータを返す
max_size() 	要素の最大数を返す
rbegin() 	セットの末尾を指すリバースイテレータを返す
rend() 	セットの先頭を指すリバースイテレータを返す
size() 	セット中の要素数を返す
swap() 	二つのセットを入れ替える
upper_bound() 	特定の値を越える最初の要素を指すイテレータを返す
value_comp() 	値を比較する関数を返す
 */
