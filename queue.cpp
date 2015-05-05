#include <cstdio>

const int MAX = 5;//define MAX 5とするよりもいい。なぜなら、値が変わらないことを保証するから。
static int head = 0;
static int tail = 0;
int queue[MAX];
//ローカル変数にするか、グローバル変数にするか。それは単体の関数で使うのか複数の関数で使うのかで
//分けて考えればいい。

//プロトタイプ宣言をするかしないかは関数の目次を作りたいかどうかや関数が多すぎて分け分からなくなり
//そうかどうかで決める。プロトタイプ宣言するときは、宣言の順番に関数を記述していく。しないときは
//main関数の上に逆順でつくる。

//スコープはできるだけ狭くするのが職人だ。

void deq(void)
{
  head++;
  if(head == MAX) head = 0;
}

int front(void)
{
  return queue[head];
}

void enq(int value)
{
  queue[tail] = value;
  tail++;
  if(tail == MAX) tail = 0;
}

int main(void)
{
  enq(1);
  enq(2);
  enq(3);
  printf("%d\n", front());
  deq();
  printf("%d\n", front());
  deq();
  printf("%d\n", front());
  
  return 0;
}

/*#include <queue>
#include <cstdio>

using namespace std;

int main(void)
{
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  printf("%d\n", q.front());
  q.pop();
  printf("%d\n", q.front());
  q.pop();
  printf("%d\n", q.front());
  
  return 0;
}
*/
