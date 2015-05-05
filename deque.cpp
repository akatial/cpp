#include <iostream>

class DequeEmptyException
{
public:
  DequeEmptyException()
  {
    std::cout << "Deque Empty" << std::endl;
  }
};

class Node
{
public:
  int data;
  Node* prev;
  Node* next;
};

class Deque
{
private:

  Node *pfront;
  Node *pback;
  int count;

public:

  Deque()
  {
    pfront = NULL;
    pback = NULL;
    count = 0;
  }

  bool empty()
  {
    return count == 0;
  }

  void push_front(int data)
  {
    Node* tmp = new Node();
    tmp->data = data;
    tmp->prev = tmp->next = NULL;
    if ( empty() )
      {
	pfront = pback = tmp;
      }
    else
      {
	tmp->next = pfront;
	pfront->prev = tmp;
	pfront = tmp;
      }
    count++;
  }

  void push_back(int data)
  {
    Node* tmp = new Node();
    tmp->data = data;
    tmp->prev = tmp->next = NULL;
    if ( empty() )
      {
	pfront = pback = tmp;
      }
    else
      {
	pback->next = tmp;
	tmp->prev = pback;
	pback = tmp;
      }
    count++;
  }

  int pop_front()
  {
    if ( empty() )
      throw new DequeEmptyException();
    int res = pfront->data;
    Node* tmp = pfront;
    if ( pfront->next != NULL )
      {
	pfront = pfront->next;
	pfront->prev = NULL;
      }
    else
	pfront = NULL;
    count--;
    delete tmp;
    return res;
  }
  
  int pop_back()
  {
    if ( empty() )
      throw new DequeEmptyException();
    int res = pback->data;
    Node *tmp = pback;
    if ( pback->prev != NULL )
      {
	pback = pback->prev;
	pback->next = NULL;
      }
    else
      pback = NULL;
    count--;
    delete tmp;
    return res;
  }
  
  int front()
  {
    if ( empty() )
      throw new DequeEmptyException();
    return pfront->data;
  }

  int back()
  {
    if ( empty() )
      throw new DequeEmptyException();
    return pback->data;
  }

  int size()
  {
    return count;
  }
  
  void clear()
  {
    pfront = NULL;
    pback = NULL;
    count = 0;    
  }
  
};

int main()
{
  Deque d;
  for ( int i = 98 ; i >= 0 ; i -= 2 )
    d.push_back(i);
  for ( int i = 99 ; i >= 0 ; i -= 2 )
    d.push_front(i);
  int len = d.size() / 2;
  for ( int i = 0 ; i < len ; i += 1 )
    {
      std::cout << d.back() << " " << d.front() << " ";
      d.pop_front();
      d.pop_back();
    }
  std::cout << std::endl;
  return 0;
}
