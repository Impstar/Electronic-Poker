#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include <cstdlib>
#include <algorithm>

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
	const int INIT_CAP = 5;
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

void printKeptEntry(card arr)
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
	cout << " of " << arr.suite << " (kept) " << endl;
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
		printEntry(temp->data);
		temp = temp->next;
	}
}

void printItemsInHand(linkedList *hand)
{
	cout << "Your hand contains:\n";
	node *temp = hand->headptr;
	cout << "A: ";
	printEntry(temp->data);
	temp = temp->next;
	cout << "B: ";
	printEntry(temp->data);
	temp = temp->next;
	cout << "C: ";
	printEntry(temp->data);
	temp = temp->next;
	cout << "D: ";
	printEntry(temp->data);
	temp = temp->next;
	cout << "E: ";
	printEntry(temp->data);
}

void printKeptHand(linkedList *hand, int kept)
{
	cout << "Your hand contains:\n";
	node *temp = hand->headptr;
	cout << "A: ";
	if (kept > 0)
		printKeptEntry(temp->data);
	else
		printEntry(temp->data);
	temp = temp->next;
	cout << "B: ";
	if (kept > 1)
		printKeptEntry(temp->data);
	else
		printEntry(temp->data);
	temp = temp->next;
	cout << "C: ";
	if (kept > 2)
		printKeptEntry(temp->data);
	else
		printEntry(temp->data);
	temp = temp->next;
	cout << "D: ";
	if (kept > 3)
		printKeptEntry(temp->data);
	else
		printEntry(temp->data);
	temp = temp->next;
	cout << "E: ";
	if (kept > 4)
		printKeptEntry(temp->data);
	else
		printEntry(temp->data);
	temp = temp->next;
}

void fill_Linked_List(linkedList *list)
{
	card info;
	for (int i = 0; i < 13; i++)
	{
		info.value = i + 2;
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

void insertionSort(card arr[], int n)
{
	int j;
	card key;
	for (int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j].value > key.value)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

void viewDeck(linkedList *linList)
{
	printItems(linList);
}

node* getItemSearch(linkedList *list, card search)
{
	node *temp = list->headptr;
	while (temp->next != nullptr)
	{
		if (temp->data.value == search.value && temp->data.suite == search.suite)
			return temp;
		else
			temp = temp->next;
	}
	return nullptr;
}

//node getItemFromIndex(linkedList *list, int index)
//{
//
//}

node* get_item(linkedList* list, int index)
{
	node* n = list->headptr;
	while (index > 0)
	{
		n = n->next;
		--index;
	}
	return n;
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
	if (list->count == 0) //if there are no more cards in deck
	{
		fill_Linked_List(list);
		if (_hand->headptr != nullptr) //if the hand contains cards
		{
			node *temp = _hand->headptr;
			while (temp != nullptr) //while temp's next isn't the last card in your hand
			{
				if (temp == getItemSearch(list, temp->data)) //if card in hand is found in deck, delete that card in deck
				{
					node *n = getItemSearch(list, temp->data); //PROBLEM: I need the node before n somehow so I can delete n
					temp = n->next;
					delete n;
				}
				else
					temp = temp->next;
			}
		}
	}
	add_last(_hand, getItemRandom(list, randIndex));
}

void discardFromHand(linkedList *_hand, linkedList *list, bool arr[5]) //discards cards from hand and draws new ones
{
	int removeCounter = 0;
	int index = 0;

	for (int i = 0; i < 5; i++)
	{
		if (arr[i] == false)
		{
			if (removeCounter == i) //if removecounter = the number being checked, the number being checked is the new first
			{
				node *temp = _hand->headptr;
				_hand->headptr = temp->next;
				temp = nullptr;
				delete temp;
				removeCounter++;
			}
			else //the number being checked isn't first
			{
				index = i;
				node *temp = _hand->headptr;
				while (index - removeCounter > 1)
				{
					temp = temp->next;
					--index;
				}
				node *n = temp->next;
				temp->next = n->next;
				n = nullptr;
				delete n;
				removeCounter++;
			}
		}
	}
	for (int i = 0; i < removeCounter; i++)
	{
		drawCard(list, _hand);
	}
}

int checkHand(linkedList *_hand)
{
	node *temp = _hand->headptr;
	card arr[5] = { 0 };
	int i = 0;
	bool straight = false;
	bool royal = false;
	bool flush = false;
	bool pair = false;
	bool twoPair = false;
	bool three = false;
	bool four = false;
	int counter = 0;
	while (temp != nullptr) //adds hand to card array
	{
		arr[i] = temp->data;
		temp = temp->next;
		i++;
	}

	insertionSort(arr, 5); //sorts card array by value

	for (int i = 0; arr[i].value + 1 == arr[i+1].value && i < 4; i++) //is straight?
	{
		counter++;
	}
	if (counter >= 5)
		straight = true;

	counter = 0;
	for (int i = 0; arr[i].suite == arr[i + 1].suite && i < 4; i++) //is flush?
	{
		counter++;
	}
	if (counter >= 5)
		flush == true;
	
	if (arr[0].value == 10) //is royal straight flush?
		if (arr[1].value == Jack)
			if (arr[2].value == Queen)
				if (arr[3].value == King)
					if (arr[4].value == Ace)
						royal = true;
	
	counter = 1;
	int counterArr[5] = { 0 };
	for (int i = 0; i < 4; i++) //grabs duplicates and shoves the number of duplciates into a separate array
	{
		if (arr[i].value == arr[i + 1].value)
		{
			int j = i;
			while (arr[j].value = arr[j + 1].value)
			{
				counter++;
				j++;
			}
			counterArr[i] = counter;
			i += counter - 1;
			counter = 1;
		}
	}

	int l = 0;
	for (int i = 0; i < 5; i++) //how many duplicates?
	{
		if (counterArr[i] == 4)
			four = true;
		if (counterArr[i] == 3)
			three = true;
		if (counterArr[i] == 2 && pair == true)
			twoPair = true;
		else if (counterArr[i] == 2)
			pair = true;

	}

	//checks for royal straight flush
	if (royal == true && straight == true && flush == true)
	{
		cout << "\nYou received a ROYAL FLUSH!!! You are either absurdly hilariously lucky, or you're cheating.  " <<
			"Probably the latter.  Take $800... you cheater.";
		return 800;
	}

	//checks for straight flush
	if (straight == true && flush == true)
	{
		cout << "\nYou received a straight flush!  Have you tried out some arcades?  You'd make a killin with that luck." <<
			"  You gain $50.";
		return 50;
	}

	//checks for 4 of a kind
	if (four == true)
	{
		cout << "\nYou received a 4 of a kind!  You're on your way to becoming a champion!  That's $25 to you!";
		return 25;
	}

	//checks for full house
	if (three == true && pair == true)
	{
		cout << "\nYou received a full house!  Pretty damn good, you're becoming a natural.  You get $9.";
		return 9;
	}

	//checks for flush
	if (flush == true)
	{
		cout << "\nYou received a flush!  You don't see this kind of hand every day!  You gain $6.";
		return 6;
	}

	//checks for straight
	if (straight == true)
	{
		cout << "\nYou received a straight!  Good job!  You get $4.";
		return 4;
	}

	//checks for 3 of a kind
	if (three == true)
	{
		cout << "\nYou got 3 of a kind!  An above average achievement!  You get $3";
		return 3;
	}

	//checks for 1 or 2 pair
	if (twoPair == true)
	{
		cout << "\nYou got two-pair. Well, better than nothing I guess.  $2 to you.";
		return 2;
	}

	if (pair == true)
	{
		cout << "\nYou got two of a kind.  Yeee... I guess you get $1.";
		return 1;
	}

	return 0; //causes stack around var arr was corrupted

}

void swapper(linkedList *hand, linkedList *deck)
{
	char input;
	node *temp = nullptr; //grabs from hand
	node *temp2 = nullptr; //grabs from deck
	card swapee;
	cout << "Enter the letter of the card in hand: ";
	cin >> input;
	input = tolower(input);
	while (!cin.good() || input < 'a' || input > 'e') //if input is invalid
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nInvalid input.  Please insert valid character.\n";
		return;
	}
	if (input == 'a') //search for selected item in hand.
		temp = get_item(hand, 0);
	else if (input == 'b')
		temp = get_item(hand, 1);
	else if (input == 'c')
		temp = get_item(hand, 2);
	else if (input == 'd')
		temp = get_item(hand, 3);
	else if (input == 'e')
		temp = get_item(hand, 4);

	int inpt;

	cout << "\nEnter the value of the card in the deck you want to swap for: ";
	cin >> inpt;
	if (!cin.good() || inpt < 2 || inpt > 14)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nInvalid input.  Please input integer between 2 and 14.";
		return;
	}
	cout << "\nEnte the suite (c, d, h, s) of the card to swap for: ";
	cin >> input;
	if (!cin.good() || (input != 'c' && input != 'd' && input != 'h' && input != 's'))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nInvalid input.  Please input valid character.\n";
		return;
	}
	swapee.value = inpt;
	if (input == 'c')
		swapee.suite = "Clubs";
	else if (input == 'd')
		swapee.suite = "Diamonds";
	else if (input == 'h')
		swapee.suite = "Hearts";
	else if (input == 's')
		swapee.suite = "Spades";
	temp2 = getItemSearch(deck, swapee);
	node *temp3 = new node; //temp node
	temp3->data = temp->data;
	temp->data = temp2->data;
	temp2->data = temp3->data;

}

void playGame(linkedList *linList)
{
	int currentCash = 10;
	bool sameRound = true;
	linkedList *hand = createLinkedList();
	while (currentCash > 0)
	{
		cout << "\nYou have $" << currentCash << endl;
		cout << "You pay an ante of $1 and now have $" << --currentCash << endl;

		//discards current hand for next
		node *n = new node;
		node *temp = new node;
		n = hand->headptr;
		while (n != nullptr)
		{
			temp = n->next;
			n = nullptr;
			delete n;
			n = temp;
		}
		hand->headptr = nullptr;
		hand->count = 0;
		while (hand->count < 5)
		{
			drawCard(linList, hand);
		}
		sameRound = true;
		while (sameRound) //while it's the same round
		{
			printItemsInHand(hand);
			cout << "\nThe deck contains " << linList->count << " cards in it.\n";
			cout << "\nOPTIONS...\n- Type the letters for the cards you wish to keep. (i.e., \"acd\")" <<
				"\n- Type \"deck\" to view the cards remaining in the deck." <<
				"\n- Type \"none\" to discard all cards in your hand." <<
				"\n- Type \"all\" to keep all cards in your hand." <<
				"\n- Type \"exit\" to exit the game." <<
				"\n- Type \"swap\" to CHEAT and swap a card in your hand with one in the deck.\n\n" <<
				"YOUR CHOICE: ";

			string input;
			bool isValid = false;
			bool validCards[5] = { false };
			while (!isValid) //while the entry isn't valid, keep looping
			{
				isValid = true;
				cin >> input;
				if (input == "deck")
				{
					printItems(linList);
				}
				else if (input == "none")
				{
					for (int i = 0; i < 5; i++)
					{
						validCards[i] = false;
					}
					discardFromHand(hand, linList, validCards);
					currentCash += checkHand(hand);
					printKeptHand(hand, 0);
					if (checkHand(hand) == 0)
					{
						cout << "\nSorry, your hand did not contain any matches.\n";
					}
					sameRound = false;
				}
				else if (input == "all")
				{
					for (int i = 0; i < 5; i++)
					{
						validCards[i] = true;
					}
					discardFromHand(hand, linList, validCards);
					currentCash += checkHand(hand);
					printKeptHand(hand, 5);
					if (checkHand(hand) == 0)
					{
						cout << "\nSorry, your hand did not contain any matches.\n";
					}
					sameRound = false;
				}
				else if (input == "exit")
				{
					return;
				}
				else if (input == "swap")
				{
					swapper(hand, linList);
				}
				else
				{
					if (input.size() > 5) //if input is greater than 5 characters
					{
						cout << "Invalid input: try again\n";
						isValid = false;
					}
					for (int i = 0; i < input.size(); i++) //makes input lowercase
					{
						input[i] = tolower(input[i]);
						if (input[i] < 'a' || input[i] > 'e') //if a character is out of abcde range, make error
						{
							cout << "Invalid input: try again\n";
							isValid = false;
							break;
						}
					}
					if (isValid) //the input is completely valid
					{
						for (int i = 0; i < input.size(); i++) //calculates what cards to discard
						{
							if (input[i] == 'a')
								validCards[0] = true;
							if (input[i] == 'b')
								validCards[1] = true;
							if (input[i] == 'c')
								validCards[2] = true;
							if (input[i] == 'd')
								validCards[3] = true;
							if (input[i] == 'e')
								validCards[4] = true;
						}
						discardFromHand(hand, linList, validCards);
						currentCash += checkHand(hand);
						printKeptHand(hand, input.size());
						if (checkHand(hand) == 0)
						{
							cout << "\nSorry, your hand did not contain any matches.\n";
						}
						sameRound = false;
					}

				}
			}

			cout << "\n-------------------------------------\n\n";
		}
	}

}