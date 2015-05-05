#include <map>
#include <string>
#include <iostream>

int main()
{
  std::map<int, std::string> names;  // キーがint、値がchar*のstd::map

  // 要素を追加する
  names.insert( std::make_pair( 10, "aaa" ) );
  names.insert( std::make_pair( 30, "ccc" ) );
  names.insert( std::make_pair( 50, "eee" ) );
  names.insert( std::make_pair( 40, "ddd" ) );
  names.insert( std::make_pair( 20, "bbb" ) );

  // 要素を出力する
  for( std::pair<int, std::string> it : names)
    {
      std::cout << it.first << ":" << it.second << std::endl;
    }
  /*
  std::map<int, std::string>::iterator it = names.begin();
  while( it != names.end() )
    {
      std::cout << (*it).first << ":" << (*it).second << std::endl;
      ++it;
    }
  */
  return 0;
}
