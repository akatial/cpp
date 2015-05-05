#include<fstream>
using namespace std;

int main(void)
{
  ofstream ofs; //ofstream = output file stream
  ofs.open( "test.txt" );
  
  ofs << "testmessage" <<  endl;
  
  ofs.close();
  return 0;
  
}
