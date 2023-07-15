#ifndef cir_h
#define cir_h
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
  int take_size();
  int take_hool();
  ~LL();

  void insert_value(int value);
  void printListR();
  int deletes_val(int value);

  //for circular
  void insert_c(int value);
  int deletes_c(int value);
  void printListR_c();

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

void LL::insert_c(int value)
{
  NodePtr newPtr=new Node(value);
  if(newPtr!=nullptr)
  {
    if(hol==nullptr)
    {
      hol=newPtr;
      newPtr->set_next(newPtr);
      newPtr->set_prev(newPtr);
    }
    else
    {
      NodePtr currentPtr=hol;
      while(currentPtr->get_next()!=hol&&value>currentPtr->get_next()->get_data())
        {
          currentPtr=currentPtr->get_next();
        }
      newPtr->set_next(currentPtr->get_next());
      currentPtr->get_next()->set_prev(newPtr);
      newPtr->set_prev(currentPtr);
      currentPtr->set_next(newPtr);
      if(value<hol->get_data())
      {
        hol=newPtr;
      }
    }
    size++;
  }
  else
  {
    cout<<value<<"not inserted."<<endl;
  }
}

int LL::deletes_c(int value)
{
  NodePtr currentPtr=hol;
  NodePtr tempPtr=nullptr;

  if(currentPtr==nullptr)
  {
    return '\0';
  }
  else
  {
    if(value==hol->get_data())
    {
      tempPtr=hol;
      hol=hol->get_next();
    }
    if(hol!=nullptr)
    {
      hol->set_prev(currentPtr->get_prev());
      currentPtr->get_prev()->set_next(hol);
    }
    else
    {
     hol=nullptr; 
    }
    --size;
    delete tempPtr;
    return value;
  
  else
  {
  currentPtr=hol->get_next();

  while(currentPtr!=hol)
    {
      if(value==currentPtr->get_data())
      {
        tempPtr=currentPtr;
        currentPtr->get_prev()->set_next(currentPtr->get_next());
        currentPtr->get_next()->set_prev(currentPtr->get_prev());
        size--;

        delete tempPtr;
        return value;
      }
      currentPtr=currentPtr->get_next();
    }
  }
  }
  return '\0';
}

void LL::printListR_c()
{
  if(size==0||hol==nullptr)
  {
    cout<<"List empty"<<endl;
    return;
  }
  else
  {
    cout<<"reverse list:"<<endl;
    NodePtr currentPtr=hol->get_prev();

    for(int x=0; x<size; x++)
      {
        currentPtr->print();
        cout<<"->";
        currentPtr=currentPtr->get_prev();
      }
    cout<<"NULL"<<endl;
  }
}

int LL::take_size()
{
  return size;
}

NodePtr LL::take_hool()
{
  return hol;
}
|#endif