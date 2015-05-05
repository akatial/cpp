#include <iostream>
#include <vector>

int main()
{
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for ( int i = 0 ; i < n ; ++i ) { v[i] = i; }
  int cnt1, cnt2;
  int min, max, mid;
  cnt1 = cnt2 = 0;
  for ( int k = 0 ; k < n ; ++k ) {
	min = 0, max = n-1;
	while ( min <= max ) {
	  cnt1++;
	  mid = (min+max)/2;
	  if ( v[mid] == k ) { break; }
	  else if ( v[mid] < k ) { min = mid + 1; }
	  else if ( v[mid] > k ) { max = mid - 1; }
	}
	min = -1, max = n;
	while ( max - min > 1 ) {
	  cnt2++;
	  mid = (min+max)/2;
	  if ( v[mid] >= k ) { max = mid; }
	  else { min = mid; }
	} 
  }
  std::cout << cnt1 << " " << cnt2 << std::endl;
  return 0;
}
