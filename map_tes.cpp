#pragma warning(disable:4786)  // VisualC++6.0の警告対策
#include <map>
#include <string>
#include <iostream>

int main()
{
	using namespace std;

	map<int, string> names;  // キーがint、値がchar*のmap

	// 要素を追加する
	names.insert( map<int, string>::value_type( 10, "aaa" ) );
	names.insert( map<int, string>::value_type( 30, "ccc" ) );
	names.insert( map<int, string>::value_type( 50, "eee" ) );
	names.insert( map<int, string>::value_type( 40, "ddd" ) );
	names.insert( map<int, string>::value_type( 20, "bbb" ) );

	// 要素を出力する
	map<int, string>::iterator it = names.begin();
	while( it != names.end() )
	{
		cout << (*it).first << ":" << (*it).second << endl;
		++it;
	}

	// 要素数を出力する
	cout << "要素数：" << (unsigned int)names.size() << endl;

	// 要素の全削除
	names.clear();

	// 全削除されているか確認
	if( names.empty() )
	{
		cout << "空です" << endl;
	}
	return 0;
}
/*
C++ マップ(std::map)

C++ マップはキー／値の対を保持する連想コンテナである。
begin() 	マップの先頭を指すイテレータを返す。
clear() 	全ての要素を削除する
count() 	キー値が一致する要素の数を返す
empty() 	マップが空なら真
end() 	マップの末尾を指すイテレータを返す
equal_range() 	特定のキーと一致する先頭・末尾要素を指すイテレータを返す
erase() 	要素を削除する
find() 	要素を検索する
get_allocator() 	マップのアロケータを返す
insert() 	要素を挿入する
key_comp() 	キーを比較する関数を返す
lower_bound() 	キーが特定の値以上である最初の要素を指すイテレータを返す
max_size() 	要素の最大数を返す
rbegin() 	マップの末尾を指すリバースイテレータを返す
rend() 	マップの先頭を指すリバースイテレータを返す
size() 	マップ中の要素数を返す
swap() 	二つのマップを入れ替える
upper_bound() 	キーが特定の値を越える最初の要素を指すイテレータを返す
value_comp() 	値を比較する関数を返す
 */
