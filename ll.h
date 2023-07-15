#include <iomanip>
#include <iostream>

using namespace std;

#include "node.h"

class LL {
  NodePtr hol; // head of linked list
  int size;

public:
  LL();
  int delete(int value);
  int isEmpty();
  void insert(int value);
  void printList();
  ~LL();

  void insert_value(int value);
  void printListR();
  int deletes_val(int value);

};

LL::LL() {
  this->hol = NULL;
  size = 0;
}

LL::~LL() {
  cout << "deleting all nodes" << endl;
  NodePtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) 
  {
    hol = hol->get_next();
    delete t;
    t = hol;
  }
}

LL::LL()
{
  this -> hol = NULL;
  size=0;
}
LL::~LL()
{
  cout<<"deleting"<<endl;
  NodePtr t;
  t=hol;
  for(int x=0; x<size; x++)
    {
      hol=hol->get_next();
      delete t;
      t=hol;
    }
}

void LL::insert(int value)
{
  NodePtr newPtr;
  NodePtr previousPtr;
  NodePtr currentPtr;

  newPtr = new Node(value);

  if(newPtr!=NULL)
  {
    previousPtr=NULL;
    currentPtr=hol;
      while(currentPtr!=NULL&&value>currentPtr->get_data())
        {
          previousPtr=currentPtr;
          currentPtr=currentPtr->get_next();
        }

    if (previousPtr==NULL)
    {
      newPtr->set_next(hol);
      hol=newPtr;
    }
    else
    {
    previousPtr->set_next(newPtr);
    newPtr->set_next(currentPtr);
    }
    ++size;
  }
 else
  {
  cout<<value<<"not inserted."<<endl;
  }
}

int LL::delete(int value)
{
  NodePtr previousPtr;
  NodePtr currentPtr;
  NodePtr tempPtr;

  if(value==hol->get_data())
  {
    tempPtr=hol;
    hol=hol->get_next();
    size--;

  delete tempPtr;
  return value;
  }
  else
  {
    previousPtr=currentPtr;
    currentPtr=currentPtr->get_next();

    while(currentPtr!=NULL&&currentPtr->get_data()!=value)
      {
        previousPtr=currentPtr;
        currentPtr=currentPtr->get_next();
      
        if(currentPtr==hol) currentPtr=NULL;
      }
   
    if(currentPtr!=NULL)
    {
      tempPtr=currentPtr;
      previosPtr->set_next(currentPtr->get_next());
      currentPtr=currentPtr->get_next();
      delete tempPtr;
      size--;
      return value;
    }
  }
  return '\0'
}

int LL::isEmpty()
{
  return hol==NULL;
}

void LL::printList()
{
  NodePtr currentPtr;
  currnetPtr=hol;

  if(size==0)
  {
    cout<<"List empty"<<endl;
  }
  else
  {
    cout<<"list is:"<<endl;

    for(int i=0; i<size; i++)
      {
        currentPtr->print();
        cout<<"->";
        currentPtr=currentPtr->get_next();
      }

    puts("NULL\n");
  }
}

void LL::insert_value(int value)
{
  NodePtr newPtr;
  NodePtr previousPtr;
  NodePtr currentPtr;

  newPtr = new Node(value);
  if(new!=NULL)
  {
    previousPtr=NULL;
    currentPtr=hol;
    while(currentPtr!=NULL&&value>currentPtr->get_data())
      {
        previousPtr=currentPtr;
        currentPtr=currentPtr->get_next();
      }
    if(previousPtr==NULL)
    {
      newPtr->set_next(hol);
      if(hol)
      {
        hol->set_prev(newPtr);
        hol=newPtr;
      }
    }
    else
    {
    previousPtr->set_next(newPtr);
    newPtr->set_prev(previousPtr);
    newPtr->set_next(currentPtr);
    if(currentPtr)
    {
      currentPtr->set_prev(newPtr);
    }
    }
    ++size;
  }
  else
  {
   cout<<value<<"not inserted."<<endl; 
  }
}

void LL::printListR()
{
  NodePtr currentPtr=hol;
  if(size==0)
  {
  cout<<"list is empty."<<endl;
  }
  else
  {
    cout<<"Reverse list:"<<endl;
    while(currentPtr->get_next()!=nullptr)
      {
        currentPtr=currentPtr->get_next();
      }
    for(int x=0; x<size; x++)
      {
        currentPtr->print();
        cout<<"->";
        currentPtr=currentPtr->get_prev();
      }
    puts("NULL\n");
  }
}

int LL::deletes_val(int value)
{
  if(isEmpty())
  {
    return'\0';
  }

  NodePtr currentPtr=hol;

  while(currentPtr!=nullptr&&currentPtr->get_data()!=value)
    {
      currentPtr=currentPtr->get_next();
    }

  if(currentptr==nullptr)
  {
    return'\0';
  }
  
  if(currentPtr->get_prev()!=nullptr)
  {
    currentPtr->get_prev()->set_next(currentPtr->get_next());
  }
  else
  {
    hol=currentPtr->get_next();
  }

  if(currentPtr->get_next()!=nullptr)
  {
    currentPtr->get_next()->set_prev(currentPtr->get_prev());
  }

  int deleted=currentPtr->get_data();
  delete currentPtr;
  --size;
  return deleted;
}
