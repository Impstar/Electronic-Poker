#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include <cstdlib>

using namespace std;

//srand((unsigned)time(NULL));

struct card
{
	int value;
	string suite;
};

struct array_list
{
	card *array;
	int capacity;
	int count;
};

array_list* create_array_list()
{
	const int INIT_CAP = 52;
	array_list* list = new array_list;
	list->array = new card[INIT_CAP];
	list->capacity = INIT_CAP;
	list->count = 0;
	return list;
}

struct node
{
	card data;
	node *next;
	node *prev;
};

struct linkedList
{
	node *headptr;
	node *tailptr;
};

linkedList *createLinkedList()
{
	linkedList *list = new linkedList;
	list->headptr = nullptr;
	list->tailptr = nullptr;
	return list;
}

enum Royals
{
	Jack = 11,
	Queen = 12,
	King = 13,
	Ace = 14
};

void add_first(linkedList *list, card info)
{
	node *temp = new node;
	temp->data = info;
	temp->next = list->headptr;
	list->headptr = temp;
}

void add_last(linkedList *list, card info)
{
	if (list->headptr == nullptr)
	{
		add_first(list, info);
	}

	node *temp = new node;
	temp->data = info;
	temp->prev = list->tailptr;
	list->tailptr = temp;
}


void printEntry(card *arr)
{
	if (arr->value == 11)
		cout << "Jack";
	else if (arr->value == 12)
		cout << "Queen";
	else if (arr->value == 13)
		cout << "King";
	else if (arr->value == 14)
		cout << "Ace";
	else
		cout << arr->value;
	cout << " of " << arr->suite;
}

void printList(array_list *arr)
{
	for (int i = 0; i < arr->count; i++)
	{
		cout << arr[i].array->value << " of " << arr[i].array->suite << endl;
	}
}

void printItems(linkedList *list)
{
	node *temp = list->headptr;
	while (temp != nullptr)
	{
		cout << temp->data.value << " of " << temp->data.suite << endl;
	}
}

void fillArrayList(array_list *arr) //fills the array list 
{
	int j = 2;
	for (int i = 0; i < 13; i++)
	{
		arr->array[i].value = j;
		arr->array[i].suite = "Hearts";
		j++;
		arr->count++;
	}
	cout << endl;
	j = 2;
	for (int i = 13; i < 26; i++)
	{
		arr->array[i].value = j;
		arr->array[i].suite = "Diamonds";
		j++;
		arr->count++;
	}
	j = 2;
	for (int i = 26; i < 39; i++)
	{
		arr->array[i].value = j;
		arr->array[i].suite = "Clubs";
		j++;
		arr->count++;
	}
	j = 2;
	for (int i = 39; i < 52; i++)
	{
		arr->array[i].value = j;
		arr->array[i].suite = "Spades";
		j++;
		arr->count++;
	}
	for (int i = 0; i < arr->count; i++)
	{
		cout << arr->array[i].value << " of " << arr->array[i].suite << endl;
	}
}

void remove_item(array_list *list, int index)
{
	if (index < 0 || index >= list->count)
	{
		cout << "Error!" << endl;
		return;
	}
	for (int i = index; i < list->count - 1; i++)
		list->array[i] = list->array[i + 1];
}

void randomlyAllocate(array_list *arr, linkedList *linList)
{
	if (arr->count == 0)
		return;
	srand((unsigned)time(NULL));
	int randIndex = rand() % arr->count;
	add_last(linList, arr->array[randIndex]);
	remove_item(arr, randIndex);
	arr->count--;
	randomlyAllocate(arr, linList);
}

