#include <iostream>
#include <ctime>
#include <cstdlib>

struct node
{
  int value;
  struct node* left;
  struct node* right;
};

void make_node(struct node *p, int data)
{
  p->value = data;
  p->left = p->right = NULL;
}

struct node* insert( struct node* rp, int num )
{
  if ( rp == NULL )
    {
      rp = new Node(num);
      return rp;
    }
    else if ( rp->value >= num )
      {
	if ( rp->left != NULL )
	  insert(rp->left, num);
	else
	  {
	    rp->left = new Node(num);
	    return rp;
	  }
      }
    else  
      {
	if ( rp->right != NULL )
	  insert(rp->right, num);
	else
	  {
	    rp->right = new Node(num);
	    return rp;
	  }
      }
    return rp;
}
  
void print_pre_order( Node* p )
{
  if ( p != NULL ) std::cout << p->value << " ";
  if ( p->left != NULL ) print_pre_order(p->left);
  if ( p->right != NULL ) print_pre_order(p->right);
}

int main()
{
  srand(static_cast<unsigned int>(time(NULL)));
  struct node *rp = NULL;
  int n;
  std::cin >> n;
  while ( n-- )
    { 
      int v = rand() % 100;
      std::cout << v << " ";
      rp = insert(rp, v);
    }
  std::cout << std::endl;
  t.print_pre_order(rp);
  std::cout << std::endl;
}
