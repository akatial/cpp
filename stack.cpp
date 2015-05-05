//#include <stack>
#include <cstdio>

const int MAX = 10;
static int i = 0;

void push(int *stack, int value)
{
  stack[++i] = value;
}

void pop(int *stack)
{
  i--;
}

int peek(int *stack)
{
  return stack[i];
}

int main(void)
{
  int stack[MAX];
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  printf("%d\n", stack[i]);
  pop(stack);
  printf("%d\n", stack[i]);
  pop(stack);
  printf("%d\n", stack[i]);
}

/*
using namespace std;

int main(void)
{
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  printf("%d\n", s.top());
  s.pop();
  printf("%d\n", s.top());
  s.pop();
  printf("%d\n", s.top());
  s.pop();
  printf("%d\n", s.top());
  
  return 0;
}
*/
