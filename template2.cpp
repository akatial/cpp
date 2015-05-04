// sequence template
#include <iostream>
using namespace std;

template <class T, int N> //template <type_name variable_name>
class mysequence 
{
public:
  void setMember(int x, T value);
  T getMember(int x);
private:
  T memblock[N];
};

template <class T, int N> //template classのメンバ関数を実装するときには必要
void mysequence<T, N>::setMember(int x, T value)// class_name<typename>:: 
//名前空間を指定することで、その関数がどのクラスに所属しているのかを明確にする
{
  memblock[x] = value;
}

template <class T, int N>
T mysequence<T, N>::getMember(int x)
{
  return memblock[x];
}

int main(int argc, char **argv)
{
  mysequence<int, 5> myints;
  mysequence<double, 5> mydoubles;
  myints.setMember(0, 199);
  mydoubles.setMember(3, 3.14);
  cout << myints.getMember(0) << endl;
  cout << mydoubles.getMember(3) << endl;
  
  return 0;
}


#if 0
template <class S, class T>
class class_name
{
public:
  //まずはコンストラクタを記述すること
  class_name()
  {
    
  }
  //それからデストラクタを記述すること
  ~class_name()
  {

  }
  メンバ関数 
private:
  メンバ変数
};
#endif 

#if 0

// template specialization
#include <iostream>
using namespace std;

// class template
template <class T>
class container
{
public:

  container(T argument)
  {
    element = argument;
  }

  T increase()
  {
    return ++element;
  }

private:

  T element;
};

#endif

#if 0

// class template specialization
template <>
class container <char>
{
public:

  container(char argument)
  {
    element = argument;
  }

  char changeCase()
  {
    if ( element >= 'a' && element <= 'z') element += 'A' - 'a';
    else if ( element >= 'A' && element <= 'Z') element -= 'A' - 'a';
    return element;
  }

private:
  char element;
};

int main(int argc, char **argv)
{
  container<int> myint(7);
  container<char> mychar1('a');
  container<char> mychar2('B');
  cout << myint.increase() << endl;
  cout << mychar1.changeCase() << endl;
  cout << mychar2.changeCase() << endl;

  return 0;
}

#endif

#if 0
// class templates
#include <iostream>
using namespace std;

template <class T>
class mypair
{
public:
  mypair(T first, T second)
  {
    a = first, b = second;
  }
  T getMax();
private:
  T a, b;
};

template <class T>
T mypair<T>::getMax()
{
  T result;
  result = a > b ? a : b;
  return result;
}

int main(int argc, char **argv)
{
  mypair<int> myObject(100, 75);
  cout << myObject.getMax() << endl;
  return 0;
}

#endif 

# if 0

// function template
#include <iostream>
using namespace std;

template <class T>
T getMax (T a, T b) 
{
  T result;
  result = (a > b)? a : b;
  return result;
}

int main (int argc, char **argv) 
{
  int i = 5, j = 6, k;
  long l = 10, m = 5, n;
  k = getMax<int>(i, j);
  n = getMax<long>(l, m);
  cout << k << endl;
  cout << n << endl;
  return 0;
}

#endif 
