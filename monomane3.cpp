#include <fstream>
#include <string>

using namespace std;

int main(void)
{
  ifstream ifs("text.in", ios::in);
  ofstream ofs("text.out", ios::trunc);
  string tmp;
  while( ifs && getline(ifs, tmp) )
    ofs << tmp << endl;
  return 0;
}
