#include <map>
#include <string>
#include <iostream>

int main()
{
  //using namespace std;

  std::map<int, std::string> names;  // キーがint、値がchar*のmap

  // 要素を追加する
  names.insert( std::pair<int, std::string>( 10, "aaa" ) );
  names.insert( std::pair<int, std::string>( 30, "ccc" ) );
  names.insert( std::pair<int, std::string>( 50, "eee" ) );
  names.insert( std::pair<int, std::string>( 40, "ddd" ) );
  names.insert( std::pair<int, std::string>( 20, "bbb" ) );

  // 要素を出力する
  std::map<int, std::string>::iterator it = names.begin();
  while( it != names.end() )
    {
      std::cout << (*it).first << ":" << (*it).second << std::endl;
      ++it;
    }
  return 0;
}
