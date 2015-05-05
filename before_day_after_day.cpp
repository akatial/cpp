#include  <iostream>

static int  days[2][12] = {
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   /* 平年 */
  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   /* 閏年 */
};

class Date
{
private:
  int  year;     
  int  month;     
  int  day;
public:    
  Date()
  {
  }

  Date(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;        
  }
  
  void set(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;    
  }

  void print()
  {
    std::cout << year << " " << month << " " << day << std::endl;
  }

  int isleap(int year)
  {
    return (year % 4 == 0  &&  (year % 100 != 0  ||  year % 400 == 0));
  }

  void after(int n)
  {
    if (n < 0)
      return before(-n);
    
    day += n;

    while (day > days[isleap(year)][month - 1]) 
      {
	day -= days[isleap(year)][month - 1];
	if (++month > 12) 
	  {
	    year++;
	    month = 1;
	  }
      }
  }
  
  void before(int n)
  {
    if (n < 0)
      return after(-n);

    day -= n;

    while (day < 1) 
      {
	if (--month < 1) 
	  {
	    year--;
	    month = 12;
	  }
	day += days[isleap(year)][month - 1];
      }
  }
};



int main()
{
  int  y, m, d, n;

  std::cin >> y >> m >> d;
  std::cin >> n;

  Date D;
  D.set(y, m, d);
  D.before(n);
  D.print();
  D.set(y, m, d);
  D.after(n);
  D.print();
  return 0;
}
