#include<iostream>
#include "Header.h";

using namespace std;



int main()
{
	linkedList *linkList = createLinkedList();
	fill_Linked_List(linkList);
	cout << endl << endl << "List of items in linked list:\n";
	//printItems(linkList);
	cout << endl << endl << "List of items in deck: \n";
	viewDeck(linkList);
	playGame(linkList);
	//cout << endl << endl;



	return 0;
}