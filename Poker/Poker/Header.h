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
	int count = 0;
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
	list->count++;
	if (list->headptr->next == nullptr)
	{
		list->tailptr = list->headptr;
	}
}

void add_last(linkedList *list, card info)
{
	if (list->headptr == nullptr)
	{
		add_first(list, info);
		return;
	}
	list->count++;
	node *temp = list->headptr;
	while (temp->next != nullptr)
		temp = temp->next;

	node *temp2 = new node;
	temp2->data = info;
	temp->next = temp2;
	temp2->next = nullptr;
	//node *temp = new node;
	//temp->data = info;
	//temp->prev = list->tailptr;
	//list->tailptr = temp;
}


void printEntry(card arr)
{
	if (arr.value == 11)
		cout << "Jack";
	else if (arr.value == 12)
		cout << "Queen";
	else if (arr.value == 13)
		cout << "King";
	else if (arr.value == 14)
		cout << "Ace";
	else
		cout << arr.value;
	cout << " of " << arr.suite << endl;
}

//void printList(array_list *arr)
//{
//	for (int i = 0; i < arr->count; i++)
//	{
//		cout << arr[i].array->value << " of " << arr[i].array->suite << endl;
//	}
//}

void printItems(linkedList *list)
{
	node *temp = list->headptr;
	while (temp != nullptr)
	{
		printEntry(temp->data);
		//cout << temp->data.value << " of " << temp->data.suite << endl;
		temp = temp->next;
	}
}

//void fillArrayList(array_list *arr) //fills the array list 
//{
//	int j = 2;
//	for (int i = 0; i < 13; i++)
//	{
//		arr->array[i].value = j;
//		arr->array[i].suite = "Hearts";
//		j++;
//		arr->count++;
//	}
//	cout << endl;
//	j = 2;
//	for (int i = 13; i < 26; i++)
//	{
//		arr->array[i].value = j;
//		arr->array[i].suite = "Diamonds";
//		j++;
//		arr->count++;
//	}
//	j = 2;
//	for (int i = 26; i < 39; i++)
//	{
//		arr->array[i].value = j;
//		arr->array[i].suite = "Clubs";
//		j++;
//		arr->count++;
//	}
//	j = 2;
//	for (int i = 39; i < 52; i++)
//	{
//		arr->array[i].value = j;
//		arr->array[i].suite = "Spades";
//		j++;
//		arr->count++;
//	}
//	for (int i = 0; i < arr->count; i++)
//	{
//		cout << arr->array[i].value << " of " << arr->array[i].suite << endl;
//	}
//}

void fill_Linked_List(linkedList *list)
{
	card info;
	for (int i = 0; i < 13; i++)
	{
		info.value = i + 1;
		info.suite = "Hearts";
		add_last(list, info);
		info.suite = "Diamonds";
		add_last(list, info);
		info.suite = "Clubs";
		add_last(list, info);
		info.suite = "Spades";
		add_last(list, info);
	}
}

//void remove_item(array_list *list, int index)
//{
//	if (index < 0 || index >= list->count)
//	{
//		cout << "Error!" << endl;
//		return;
//	}
//	for (int i = index; i < list->count - 1; i++)
//		list->array[i] = list->array[i + 1];
//}

//void randomlyAllocate(array_list *arr, linkedList *linList)
//{
//	srand((unsigned)time(NULL));
//	int randIndex;
//	while (arr->count > 0)
//	{
//		randIndex = rand() % arr->count;
//		add_last(linList, arr->array[randIndex]);
//		remove_item(arr, randIndex);
//		arr->count--;
//	}
//}

//void moveToLinkedList(array_list *arr, linkedList *linList)
//{
//	for (int i = 0; i < arr->count; i++)
//	{
//		add_last(linList, arr->array[i]);
//	}
//}

void insertionSort(array_list *arr)
{
	int key, j;
	for (int i = 1; i < arr->count; i++)
	{
		key = arr->array[i].value;
		j = i - 1;
		while (j >= 0 && arr->array[j].value > key)
		{
			arr->array[j + 1].value = arr->array[j].value;
			j = j - 1;
		}
		arr->array[j + 1].value = key;
	}
}

void viewDeck(linkedList *linList)
{
	printItems(linList);
}

node getItemSearch(linkedList *list, card search)
{
	node *temp = list->headptr;
	while (temp->next != nullptr)
	{
		if (temp->data.value == search.value && temp->data.suite == search.suite)
			return *temp;
		else
			temp = temp->next;
	}
}

card getItemRandom(linkedList *list, int num)
{
	node *temp = list->headptr;
	while (num > 1)
	{
		temp = temp->next;
		num--;
	}
	--list->count;
	node *temp2 = temp->next;
	node *n = temp->next;
	temp->next = n->next;
	n = nullptr;
	delete n;
	return temp2->data;
}

void drawCard(linkedList *list, linkedList *_hand)
{
	srand((unsigned)time(NULL));
	int randIndex = rand() % list->count;
	//if (list->count == 0) //if there are no more cards in deck
	//{
	//	fill_Linked_List(list);
	//	if (_hand->headptr != nullptr) //if the hand contains cards
	//	{
	//		node *temp = _hand->headptr;
	//		while (temp->next != nullptr) //while temp's next isn't the last card in your hand
	//		{
	//			if (*temp->next == getItemSearch(list, temp->data)) //if card in hand is found in deck, delete that card in deck
	//			{
	//				node *n = temp->next;
	//				temp->next = n->next;
	//				delete n;
	//			}
	//			else
	//				temp = temp->next;
	//		}
	//	}
	//}
	add_last(_hand, getItemRandom(list, randIndex));
}

void playGame(linkedList *linList)
{
	int currentCash = 10;
	linkedList *hand = createLinkedList();
	while (currentCash > 0)
	{
		cout << "\nYou have $" << currentCash << endl;
		cout << "You pay an ante of $1 and now have $" << --currentCash << endl;

		while (hand->count < 5)
		{
			drawCard(linList, hand);
		}
		printItems(hand);
		cout << endl << endl;
		printItems(linList);
	}

}