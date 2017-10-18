#include<iostream>
#include "Header.h";

using namespace std;



int main()
{
	array_list *list = create_array_list();
	fillArrayList(list);
	linkedList *linkList = createLinkedList();
	moveToLinkedList(list, linkList);
	cout << endl << endl << "List of items in linked list:\n";
	printItems(linkList);
	cout << endl << endl << "List of items in deck: \n";
	viewDeck(linkList);
	playGame(linkList);
	//printList(list);
	//cout << endl << endl;



	return 0;
}