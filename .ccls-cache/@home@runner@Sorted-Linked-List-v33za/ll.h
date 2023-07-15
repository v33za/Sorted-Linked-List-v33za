#include <iomanip>
#include <iostream>

using namespace std;

#include "node.h"

class LL {
  NodePtr hol; // head of linked list
  int size;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(int value);
  void printList();
  ~LL();

  void insert_value(int value);
  void printListR();
  int deletes_dou(int value);

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

// insert a new value into the list in sorted order
void LL::insert(int value) {
  NodePtr newPtr;      // pointer to new node
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list

  newPtr = new Node(value); // create node & put value in

  if (newPtr != NULL) { // is space available
    previousPtr = NULL;
    currentPtr = hol;
    // loop to find the correct location in the list
    while (currentPtr != NULL && value > currentPtr->get_data()) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
    }                                      // end while

    // insert new node at beginning of list
    if (previousPtr == NULL) {
      newPtr->set_next(hol);
      hol = newPtr;
    } // end if
    else {
      // insert new node between previousPtr and currentPtr
      previousPtr->set_next(newPtr);
      newPtr->set_next(currentPtr);
    } // end else
    ++size;
  } // end if
  else {
    cout << value << " not inserted. No memory available." << endl;
  } // end else
} // end function insert

// delete a list element
int LL::deletes(int value) {
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list
  NodePtr tempPtr;     // temporary node pointer

  // delete first node
  if (value == hol->get_data()) {
    tempPtr = hol;         // hold onto node being removed
    hol = hol->get_next(); // de-thread the node
    size--;

    delete tempPtr; // free the de-threaded node

    return value;
  } // end if
  else {
    previousPtr = hol;
    currentPtr = hol->get_next();

    // loop to find the correct location in the list
    while (currentPtr != NULL && currentPtr->get_data() != value) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
      if (currentPtr == hol)
        currentPtr = NULL;
    } // end while

    // delete node make at currentPtr
    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      previousPtr->set_next(currentPtr->get_next());
      currentPtr = currentPtr->get_next();

      delete tempPtr;
      size--;
      return value;
    } // end if
  }   // end else

  return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int LL::isEmpty() { return hol == NULL; } // end function isEmpty


void LL::printList() 
{
  NodePtr currentPtr;
  currentPtr = hol;
  
  if (size == 0) 
  {
    cout << "List is empty." << endl;
  }
  else 
  {
    cout << "The list is:" << endl;
    int i;
    for (i = 0; i < size; i++) {
      currentPtr->print();
      cout << "  ->";
      currentPtr = currentPtr->get_next();
    } 

    puts("NULL\n");
  } 
} 

void LL::insert_value(int value) {
  NodePtr newPtr;      
  NodePtr previousPtr; 
  NodePtr currentPtr;  

  newPtr = new Node(value); 

  if (newPtr != NULL) { 
    previousPtr = NULL;
    currentPtr = hol;
    
    while (currentPtr != NULL && value > currentPtr->get_data()) 
    {
      previousPtr = currentPtr;            
      currentPtr = currentPtr->get_next(); 

    } 
    if (previousPtr == NULL) 
    {
      newPtr->set_next(hol);
      if (hol)
        hol->set_prev(newPtr);
      hol = newPtr;

    }
    else 
    {
      // insert new node between previousPtr and currentPtr
      previousPtr->set_next(newPtr);
      newPtr->set_prev(previousPtr);
      newPtr->set_next(currentPtr);
      if (currentPtr)
        currentPtr->set_prev(newPtr);
    } // end else
    ++size;
  } // end if
  else 
  {
    cout << value << " not inserted. No memory available." << endl;
  } // end else
} // end function insert

void LL::printListR() {
  NodePtr currentptr = hol;

  if (size == 0) 
  {
    cout << "List is empty." << endl;
  } 
  else 
  {
    cout << "The reverse list is:" << endl;
    while (currentptr->get_next() != nullptr) 
    {
      currentptr = currentptr->get_next();
    }
    for (int i = 0; i < size; i++) 
    {
      currentptr->print();
      cout << "  ->";
      currentptr = currentptr->get_prev();
    }
    puts(" NULL\n");
  }
}

int LL::deletes_dou(int value) 
{
  if (isEmpty()) 
  {
    return '\0';
  }

  NodePtr currentptr = hol;

  while (currentptr != nullptr && currentptr->get_data() != value) 
  {
    currentptr = currentptr->get_next();
  } // loop until getting the position

  if (currentptr == nullptr) 
  {
    return '\0';
  }

  if (currentptr->get_prev() != nullptr) 
  {
    currentptr->get_prev()->set_next(
        currentptr->get_next());
  } else {
    hol = currentptr->get_next(); 
  }

  if (currentptr->get_next() != nullptr)
    currentptr->get_next()->set_prev(currentptr->get_prev()); 
    int deletedValue = currentptr->get_data(); 
  delete currentptr;
  --size;
  return deletedValue;
}