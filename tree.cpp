#include <iostream>
#include <cassert>

const int N = 7;

struct node 
{
  int value;
  struct node *left;
  struct node *right;
};

void print_post_order(struct node *p)
{
  if( p->left != NULL ) print_post_order(p->left);
  if( p->right != NULL ) print_post_order(p->right);
  if( p != NULL ) std::cout << p->value << std::endl;;
}

void print_in_order(struct node *p)
{
  if( p->left != NULL ) print_in_order(p->left);
  if( p != NULL ) std::cout << p->value << std::endl;;
  if( p->right != NULL ) print_in_order(p->right);
}

void print_pre_order(struct node *p)
{
  if( p != NULL ) std::cout << p->value << std::endl;;
  if( p->left != NULL ) print_pre_order(p->left);
  if( p->right != NULL ) print_pre_order(p->right);
}

struct node* create_node(int num)
{
  struct node *new_node;
  
  new_node = new struct node;
  assert( new_node != NULL );
  new_node->value = num;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

struct node* insert_node(struct node *p, int num)
{
  if( p == NULL )
    {
      p = create_node(num);
      return p;
    }
  if( p->value >= num )
    {
      if( p->left != NULL )
	insert_node(p->left, num);
      else
	{
	  p->left = create_node(num);
	  return p;
	}
    }
  else
    {
      if( p->right != NULL )
	insert_node(p->right, num);
      else
	{
	  p->right = create_node(num);
	  return p;
	}
    }
  return p;
}

int main(void)
{
  int i;
  struct node *rp = NULL;
  int num[N] = {4, 2, 5, 1, 3, 2, 7};
  for( i = 0 ; i < N ; i++ )
    {
      rp = insert_node(rp, num[i]);
    }
  print_pre_order(rp);
  std::cout << std::endl;;
  print_in_order(rp);
  std::cout << std::endl;;
  print_post_order(rp);
  return 0;
}
