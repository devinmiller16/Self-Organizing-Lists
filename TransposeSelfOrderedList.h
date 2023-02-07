#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

#ifndef TRANSPOSESELFORDEREDLIST_H
#define TRANSPOSESELFORDEREDLIST_H

template <typename E>
class TransposeSelfOrderedList : public SelfOrderedListADT<E> {
public:

	//Default Constructor
	TransposeSelfOrderedList() { numOfCompares = 0; }

	//Function to find an element in the list
	bool find(const E& it) {
		int found = 0;
		list.moveToStart();

		//For loop to find duplicates
		for (int i = 0; i < list.length(); i++)
		{
			numOfCompares++;
			//If there is a duplicate found
			if (list.getValue() == it)
			{
				found = 1;
				break;
			}
			list.next();
		}
		//If there is a duplicate found increment the amount of times accessed and call the reorder function
		if (found == 1)
		{
			//current number of item accesses
			int temp = list.getTimesAccessed();

			//number of item accesses
			list.setTimesAccessed(temp + 1);

			reorder();
			return true;
		}
		//else add the element to the end of the list and set the number of accesses to zero
		else
		{
			list.moveToEnd();
			list.insert(it);
			list.setTimesAccessed(0);
			return true;
		}
		return false;
	}

	//Function to add to the list
	void add(const E& it) { list.append(it); }

	//Function to reorder the elements
	void reorder() {
		//Get the first value
		E frontVal = list.frontValue();

		//Get the last value
		E endValue = list.tailValue();

		//If the value matches the front value stop
		if (list.getValue() == frontVal) { return; }

		//If the value matches the end value
		if (list.getValue() == endValue)
		{
			//Get the number for the end value
			int endValue = list.getTimesAccessed();

			//Move back one value in the list
			list.prev();

			//Get the number for the previous element
			int prevValue = list.getTimesAccessed();

			//Remove the previous element
			E temp = list.remove();

			//Set the correct access value
			list.setTimesAccessed(prevValue);

			//Move to the end of the list
			list.moveToEnd();

			//Insert the removed value
			list.insert(temp);

			//Set the number of accesses
			list.setTimesAccessed(prevValue);

			//Move back in the list
			list.prev();

			//Set the correct number of accesses
			list.setTimesAccessed(endValue);
			return;
		}

		//Get the number for the item to be swapped
		int toSwap = list.getTimesAccessed();

		//Move back one element
		list.prev();

		//Get the number of accesses for the previous item
		int prev = list.getTimesAccessed();

		//move to the next item
		list.next();

		//Get the number of accesses for the current item
		int curr = list.getTimesAccessed();

		//Move to the next item
		list.next();

		//get the times accessed for the next item
		int next = list.getTimesAccessed();

		//Move back
		list.prev();

		//Remove the element
		E temp = list.remove();

		//Set the number of times accessed
		list.setTimesAccessed(next);

		//Move back
		list.prev();

		//Get the number of accesses
		prev = list.getTimesAccessed();

		//Insert the temp value
		list.insert(temp);

		//Set the number of times accessed
		list.setTimesAccessed(toSwap);

		//Move to the next element
		list.next();

		list.setTimesAccessed(prev);
	}

	//Function to print the list
	void printlist() const {
		cout << "\nThe number of compares is: " << getCompares() << endl;
		cout << "My final list structure with frequencies is:" << endl;
		cout << "\t"; list.print();
		cout << endl << endl << "My list size is: " << size();
		cout << endl;
	}

	//Function to print a specified number of items from the list
	void printlist(int n) const {
		cout << "Transpose Heuristic:\n";
		cout << "The number of compares: " << getCompares() << "\tSize of list: " << size();
		list.print(n);
		cout << endl << endl;
	}

	//Function to return the number of compares
	int getCompares() const { return numOfCompares; }

	//Function to return the size of the list
	int size() const { return list.length(); }

	//Destructor
	~TransposeSelfOrderedList() {}

private:
	//Constructor with parameters
	TransposeSelfOrderedList(const TransposeSelfOrderedList&) {}

	LList<E> list;
	int numOfCompares;
};

#endif
