#include <iostream>
#include <sstream>
#include <string>

using namespace std ;

int main ( void )
{
  string line ;
  unsigned int nseco = 0 ;
  unsigned int nchar = 0 ;
  unsigned int nint = 0 ;
  unsigned int ndouble = 0 ;
  unsigned int nif = 0 ;
  unsigned int nswitch = 0 ;
  unsigned int nfor = 0 ;
  unsigned int nwhile = 0 ;
  while ( getline ( cin, line ) )
    {
      istringstream iss ( line ) ;
      string word ;
      while ( iss >> word )
	{
	  for( unsigned int i = 0 ; i < word.size() ; i++ )
	    {
	      if ( word.substr(i, 1) == ";" ) nseco++ ;
	      if ( word.substr(i, 4) == "char" ) nchar++ ;
	      if ( word.substr(i, 3) == "int" ) nint++ ;
	      if ( word.substr(i, 6) == "double" ) ndouble++ ;
	      if ( word.substr(i, 2) == "if" ) nif++ ;
	      if ( word.substr(i, 6) == "switch" ) nswitch++ ;
	      if ( word.substr(i, 3) == "for" ) nfor++ ;
	      if ( word.substr(i, 6) == "nwhile" ) nwhile++ ;
	    }
	} 
    }
  cout << "; : " << nseco << endl ;
  cout << "char : " << nchar << endl ;
  cout << "int : " << nint << endl ;
  cout << "double : " << ndouble << endl ;
  cout << "if : " << nif << endl ;
  cout << "switch : " << nswitch << endl ;
  cout << "for : " << nfor << endl ;
  cout << "while : " << nwhile << endl ;
  return 0 ;
}
