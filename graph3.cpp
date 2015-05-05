#include <iostream>

using namespace std;

const long hatena = 10000000;
const int MAX = 1000;

int V, E;
int val[MAX];
int id = 0;

struct node
{
  int value;
  struct node *next;
};

struct node *adj[MAX], *z, *t;

void show(void)
{
  int i;
  for( i = 0 ; i < V ; i++ )
    {
      cout << i + 1 << ":" << val[i] << endl;
    }
}

void visit(int k)
{
  struct node *t;
  val[k] = ++id;
  for( t = adj[k] ; t != z ; t = t->next )
    {
      if( val[t->value] == hatena )
	{
	  visit(t->value);
	}
    }
}

void search(void)
{
  int i;
  for( i = 0 ; i < V ; i++ )
    {
      val[i] = hatena;
    }
  for( i = 0 ; i < V ; i++ )
    {
      if( val[i] == hatena )
	visit(i);
    }
}

void init(void)
{
  cin >> V >> E;
  z = new node;
  z->next = z;
  int i;
  for( i = 0 ; i < V ; i++ )
    {
      adj[i] = z;
    }
  int V1, V2;
  for( i = 0 ; i < E ; i++ )
    {
      cin >> V1 >> V2;
      t = new node;
      t->value = V1;
      t->next = adj[V2];
      adj[V2] = t;
      t = new node;
      t->value = V2;
      t->next = adj[V1];
      adj[V1] = t;
    }  
}

int main(void)
{  
  init();
  search();
  show();
  return 0;
}
