#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

#ifndef COUNTSELFORDEREDLIST_H
#define COUNTSELFORDEREDLIST_H

template <typename E>
class CountSelfOrderedList : public SelfOrderedListADT<E> {
public:

	//Default constructor
	CountSelfOrderedList() { numOfCompares = 0; }

	//Function to find an element
	bool find(const E& it) {
		int found = 0;
		//Move to start
		list.moveToStart();
		//Loop through the elements 
		for (int i = 0; i < list.length(); i++)
		{
			numOfCompares++;

			//If there is a duplicate
			if (list.getValue() == it)
			{
				found = 1; //Duplicate is found
				break;
			}
			//Move to the next element
			list.next();
		}

		//If found
		if (found == 1)
		{
			//Get the current times accessed
			int temp = list.getTimesAccessed();

			//Set the times accessed
			list.setTimesAccessed(temp + 1);

			//Then reorder
			reorder();
			return true;
		}
		//Else if not found
		else
		{
			list.moveToEnd();
			list.insert(it);
			list.setTimesAccessed(0);
			return true;
		}
		return false;
	}

	//Function to add
	void add(const E& it) { list.append(it); }

	//Function to print
	void printlist() const {
		cout << "\nThe number of compares is: " << getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		cout << "\t"; list.print();
		cout << endl << endl << "My list size is: " << size();
		cout << endl;
	}

	//Function to print with parameters
	void printlist(int n) const {
		cout << "Count Heuristic:\n";
		cout << "The number of compares: " << getCompares() << "\tSize of list: " << size();
		list.print(n);
		cout << endl << endl;
	}

	//Function to get the number of compares 
	int getCompares() const { return numOfCompares; }
	
	//Function to get the size of the list 
	int size() const { return list.length(); }

	//Function to reorder the items
	void reorder() {
		//Get the number of times accessed
		int toSwap = list.getTimesAccessed();
		//Move back 
		list.prev();
		//Get number of accessed to the prev element
		int prev = list.getTimesAccessed();
		//While loop to swap elements
		while (toSwap > prev)
		{
			//Move to the next 
			list.next();

			//Remove the item
			E temp = list.remove();

			//Set times accessed for the prev element
			list.setTimesAccessed(prev);

			list.prev();

			//Insert the temp item
			list.insert(temp);

			//Set times accessed with the toSwap element
			list.setTimesAccessed(toSwap);

			list.next();
			list.setTimesAccessed(prev);

			list.prev();
			list.prev();
			prev = list.getTimesAccessed();
		}
	}

	//Destructor
	~CountSelfOrderedList() {}

private:
	//Constructor with parameters
	CountSelfOrderedList(const CountSelfOrderedList&) {}
	
	LList<E> list;
	int numOfCompares;
};

#endif
