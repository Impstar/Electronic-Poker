#include<iostream>
#include "Header.h";

using namespace std;



int main()
{
	array_list *list = create_array_list();
	fillArrayList(list);
	linkedList *linkList = createLinkedList();
	printList(list);



	return 0;
}