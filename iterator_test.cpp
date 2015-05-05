#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
  vector<int> the_vector;
  vector<int>::iterator the_iterator;
  
  for( int i=0; i < 11; i++ ) the_vector.push_back(i);
  int total = 0;
  the_iterator = the_vector.begin();
  while( the_iterator != the_vector.end() ) {
    cout << *the_iterator << endl;
    total += *the_iterator;
    ++the_iterator;
    
  }
  
  cout << "Total=" << total << endl;
}
