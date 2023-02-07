//<Devin_Miller_SelfOrganizingLists> -- Implementation of three self-organizing lists: count, move-to-front, and transpose
//CSIS 215-<D02>
//<Citations if necessary> 
//Used for algorithm help http://www.cs.ucf.edu/courses/cop3530/sum2005/selforg.pdf 
//Used for more algorithm help https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/SelfOrg.html

#include <iostream>
#include <string>
#include <fstream>
#include "CountSelfOrderedList.h"
#include "MTFSelfOrderedList.h"
#include "TransposeSelfOrderedList.h"

using namespace std;

void PauseScreen(); //Used to pause screen output

int main()
{
	cout << "Devin Miller - Programming Assignment 4" << endl << endl;

	cout << "\tTEST 1:" << endl << endl;
	cout << "My starting list structure for all heuristics is: \n";
	cout << "\tA-0 B-0 C-0 D-0 E-0 F-0 G-0 H-0" << endl << endl;

	cout << "\tCount Heuristic:";
	CountSelfOrderedList<char> count;
	//Add function to build a list in the following order: A B C D E F G H
	count.add('A');
	count.add('B');
	count.add('C');
	count.add('D');
	count.add('E');
	count.add('F');
	count.add('G');
	count.add('H');
	//Find function to input the following characters: F D F G E G F A D F G E H I 
	count.find('F');
	count.find('D');
	count.find('F');
	count.find('G');
	count.find('E');
	count.find('G');
	count.find('F');
	count.find('A');
	count.find('D');
	count.find('F');
	count.find('G');
	count.find('E');
	count.find('H');
	count.find('I');
	count.printlist();
	cout << endl << endl;

	cout << "\tMove-to-front heuristic:";
	MTFSelfOrderedList<char> MTF;
	//Add function to build a list in the following order: A B C D E F G H
	MTF.add('A');
	MTF.add('B');
	MTF.add('C');
	MTF.add('D');
	MTF.add('E');
	MTF.add('F');
	MTF.add('G');
	MTF.add('H');
	//Find function to input the following characters: F D F G E G F A D F G E H I 
	MTF.find('F');
	MTF.find('D');
	MTF.find('F');
	MTF.find('G');
	MTF.find('E');
	MTF.find('G');
	MTF.find('F');
	MTF.find('A');
	MTF.find('D');
	MTF.find('F');
	MTF.find('G');
	MTF.find('E');
	MTF.find('H');
	MTF.find('I');
	//Prints the list
	MTF.printlist();
	cout << endl << endl;

	cout << "\tTranspose heuristic:";
	TransposeSelfOrderedList<char> transpose;
	//Add function to build a list in the following order: A B C D E F G H
	transpose.add('A');
	transpose.add('B');
	transpose.add('C');
	transpose.add('D');
	transpose.add('E');
	transpose.add('F');
	transpose.add('G');
	transpose.add('H');
	//Find function to input the following characters: F D F G E G F A D F G E H I 
	transpose.find('F');
	transpose.find('D');
	transpose.find('F');
	transpose.find('G');
	transpose.find('E');
	transpose.find('G');
	transpose.find('F');
	transpose.find('A');
	transpose.find('D');
	transpose.find('F');
	transpose.find('G');
	transpose.find('E');
	transpose.find('H');
	transpose.find('I');
	//Prints the list
	transpose.printlist();

	cout << "\n\n\n\tTEST 2:\n\n\n";

	// open file
	fstream input;
	input.open("test.txt");

	CountSelfOrderedList<string> countSOL;
	MTFSelfOrderedList<string> mtfSOL;
	TransposeSelfOrderedList<string> transposeSOL;

	string word;

	//Opens file and creates list
	while (input >> word)
	{
		countSOL.find(word);
		mtfSOL.find(word);
		transposeSOL.find(word);
	}

	// count print
	countSOL.printlist(10);

	// move-to-front print
	mtfSOL.printlist(10);

	// transpose print
	transposeSOL.printlist(10);

	//Closes file
	input.close();
	
	PauseScreen();
	return 0;
}

//Used to pause the screen wherever desired
void PauseScreen() {
	char ch;
	cout << "\nPress the Enter key to continue ... ";
	cin.get(ch);
}