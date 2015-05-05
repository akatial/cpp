#include <iostream>
#include <string>

using namespace std;

int main(void)
{
 string plain_text;
 string cipher_text;
 
 cin >> plain_text;
 for( int i = 0 ; i < plain_text.size() ; i++ )
 {
     if( plain_text[i] > 96 && plain_text[i] < 110 ) cipher_text[i] = plain_text[i]  + 13, cout << cipher_text[i];
     if( plain_text[i] > 109 && plain_text[i] < 123 ) cipher_text[i] = plain_text[i] - 13, cout << cipher_text[i];
 }
 cout << endl; 

 return 0;
}
