#ifndef LLIST_H
#define	LLIST_H

#include "book.h"
#include "link.h"
#include "list.h"

// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete LList template class

// First, get the declaration for the base list class
#include "list.h"

// This is the declaration for LList. It is split into two parts
// because it is too big to fit on one book page
// Linked list implementation
template <typename E> class LList: public List<E> {
private:
  Link<E>* head;       // Pointer to list header
  Link<E>* tail;       // Pointer to last element
  Link<E>* curr;       // Access to current element
  int cnt;    	       // Size of list
  int accessed;

  void init() {        // Intialization helper method
    curr = tail = head = new Link<E>;
    cnt = 0;
  }

  void removeall() {   // Return link nodes to free store
    while(head != NULL) {
      curr = head;
      head = head->next;
      delete curr;
    }
  }

public:
  LList() { init(); }    // Constructor
  ~LList() { removeall(); }                   // Destructor

  void clear() { removeall(); init(); }       // Clear list

  // Insert "it" at current position
  void insert(const E& it) {
    curr->next = new Link<E>(it, curr->next);  
    if (tail == curr) tail = curr->next;  // New tail
    cnt++;
  }

  void append(const E& it) { // Append "it" to list
      tail = tail->next = new Link<E>(it, NULL);
      tail->setAccessed(0);
      head->setAccessed(0);
      cnt++;
  }

  // Remove and return current element
  E remove() {
    E it = curr->next->element;      // Remember value
    Link<E>* ltemp = curr->next;     // Remember link node
    if (tail == curr->next) tail = curr; // Reset tail
    curr->next = curr->next->next;   // Remove from list
    delete ltemp;                    // Reclaim space
    cnt--;			     // Decrement the count
    return it;
  }

  void moveToStart() // Place curr at list start
    { curr = head; }

  void moveToEnd()   // Place curr at list end
    { curr = tail; }

  // Move curr one step left; no change if already at front
  void prev() {
    if (curr == head) return;       // No previous element
    Link<E>* temp = head;
    // March down list until we find the previous element
    while (temp->next!=curr) temp=temp->next;
    curr = temp;
  }

  // Move curr one step right; no change if already at end
  void next()
    { if (curr != tail) curr = curr->next; }

  int length() const  { return cnt; } // Return length

  // Return the position of the current element
  int currPos() const {
    Link<E>* temp = head;
    int i;
    for (i=0; curr != temp; i++)
      temp = temp->next;
    return i;
  }

  // Move down list to "pos" position
  void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
    curr = head;
    for(int i=0; i<pos; i++) curr = curr->next;
  }

  const E& getValue() const { // Return current element
    Assert(curr->next != NULL, "No value");
    return curr->next->element;
  }

  //Function to set the number of accesses for an item
  void setTimesAccessed(int n) { curr->setAccessed(n); }

  //Return the current number of accesses for a link
  int getTimesAccessed() const { return curr->getAccessed(); }

  //Return the tail value from the list
  E tailValue() { return tail->element; }

  //Return the front value from the list
  E frontValue() { return head->next->element; }

  //Function to print the list
  void print() const {
	  //Temp pointer to head next
	  Link<E>* temp = head->next;

	  //Temp pointer to head
	  Link<E>* temp2 = head;
	  cout << endl;

	  //Loop to go through and print all items in the list
	  for (int i = 0; i < cnt; i++)
	  {
		  //Display the element and the number of accesses
		  cout << " " << temp->element << "-" << temp2->getAccessed();
		  temp = temp->next;
		  temp2 = temp2->next;
	  }
  }

  //Same as above, but the loop is for a specific number as specified by n
  void print(int n) const {
	  Link<E>* temp = head->next;
	  Link<E>* temp2 = head;
	  cout << endl;
	  for (int i = 0; i < n; i++)
	  {
		  cout << " " << temp->element << "-" << temp2->getAccessed();
		  temp = temp->next;
		  temp2 = temp2->next;
	  }
  }
};

#endif