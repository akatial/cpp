#include <iostream>
#include <ctime>
#include <cstdlib>

class Node
{
public:
  int value;
  Node* left;
  Node* right;
  Node(int data)
  {
    value = data;
    left = right = NULL;
  }
};

class Tree
{
public:
  Node* insert( Node* rp, int num )
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
};

int main()
{
  srand(static_cast<unsigned int>(time(NULL)));
  Tree t;
  Node *rp = NULL;
  int n;
  std::cin >> n;
  while ( n-- )
    { 
      int v = rand() % 100;
      std::cout << v << " ";
      rp = t.insert(rp, v);
    }
  std::cout << std::endl;
  t.print_pre_order(rp);
  std::cout << std::endl;
}
