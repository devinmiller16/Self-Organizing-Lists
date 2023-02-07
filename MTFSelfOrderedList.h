#include "SelfOrderedListADT.h"
#include "llist.h"
#include <iostream>

using namespace std;

#ifndef MTFSELFORDEREDLIST_H
#define MTFSELFORDEREDLIST_H

template <typename E>
class MTFSelfOrderedList : public SelfOrderedListADT<E> {
public:

	//Defualt Constructor 
	MTFSelfOrderedList() { numOfCompares = 0; };

	//Function to find a value in the list
	bool find(const E& it) {
		//Variable to determine whether code proceeds or not
		int found = 0;
		//Move the list to the start
		list.moveToStart();
		//Loop to determine if there are duplicate values in the list or not
		for (int i = 0; i < list.length(); i++)
		{
			//Increment the number of compares
			numOfCompares++;
			//If a duplicate is found set the found variable to one and break out of the loop
			if (list.getValue() == it)
			{
				found = 1;
				break;
			}
			//Advance the list
			list.next();
		}
		//If found equals one then increment the number of accesses for the current item
		if (found == 1)
		{
			//Get the current number of accesses
			int temp = list.getTimesAccessed();

			//Set the new number of accesses
			list.setTimesAccessed(temp + 1);

			//Call the reorder function
			reorder();
			return true;
		}
		//Otherwise add the item to the end of the list
		else
		{
			list.moveToEnd();
			list.insert(it);
			return true;
		}
		return false;
	}

	//Function to call the list append function and pass it the element
	void add(const E& it) { list.append(it); }

	//Function to reorder the elements by moving them to the front when they are accessed
	void reorder() {

		//Get the number of accesses for the item to be swapped
		int toSwap = list.getTimesAccessed();

		//Advance the list
		list.next();

		//Get the number of accesses for the next item
		int next = list.getTimesAccessed();

		//Go back to the item to be swapped
		list.prev();

		//Remove the item
		E temp = list.remove();

		//Correct the number of accesses
		list.setTimesAccessed(next);

		//Move the list to the start
		list.moveToStart();

		//Get the number of accesses for the front item
		int front = list.getTimesAccessed();

		//Insert the removed item
		list.insert(temp);

		//Set the correct number of accesses for the new item
		list.setTimesAccessed(toSwap);

		//Advance the list and set the correct number of accesses for the item
		list.next();
		list.setTimesAccessed(front);
	}

	//Function to print the list
	void printlist() const {
		cout << "\nThe number of compares is: " << getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		cout << "\t"; list.print();
		cout << endl << endl << "My list size is: " << size();
		cout << endl;
	}

	//Function to print a specified number of items in the list
	void printlist(int n) const {
		cout << "Move-to-front Heuristic:\n";
		cout << "The number of compares: " << getCompares() << "\tSize of list: " << size();
		list.print(n);
		cout << endl << endl;
	}

	//Function to return the number of compares
	int getCompares() const { return numOfCompares; }

	//Function to return the list size
	int size() const { return list.length(); }

	//Destructor
	~MTFSelfOrderedList() {};

private:
	//Constructor with parameters
	MTFSelfOrderedList(const MTFSelfOrderedList&) {}
	
	LList<E> list;
	int numOfCompares;
};

#endif
