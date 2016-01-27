// Linked List test
// 12/13/15
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

struct node{
	int data;
	node* next;
	bool isEmpty;
	node()
	{
		isEmpty = true;
	}
};
struct bucket{
	node* head;
	node* tail;
	bool full;
	bucket()
	{
		head = NULL;
		tail = NULL;
		full = false;
	}
};
node* generateLinked(int range, int length);
void printLinked(node* list);
void bucketLoop(node*& start, int digit);
int main()
{
	// Tutorial:
	/*node* n;
	node* t;
	node* h;
	n = new node;
	n->data = 1;
	t = n;
	h = n;

	n = new node;
	n->data = 2;
	t->next = n;
	t = t->next;

	n = new node;
	n->data = 3;
	t->next = n;
	n = new node;
	t = t->next;
	n->data = 4;
	n->next = 0;*/

	// My Tests:
	/*
	srand(time(NULL));
	node* n;
	n = new node;
	n->data = 15;
	node* root = new node;
	root->next = n;
	cout << n->data << endl;
	node* t = new node;
	t = root;
	for (int i = 1; i < 15; i++)
	{
		t->data = rand()%100+1;
		node* gg = new node;
		t->next = gg;
		t = gg;
	}
	t->next = 0;
	node* c = root;
	while (c->next != 0)
	{
		cout << c->data << endl;
		c = c->next;
	}*/

	node* root2 = generateLinked(100, 500);
	printLinked(root2);
	bucketLoop(root2,1);
	printLinked(root2);
	return 1;
}
node* generateLinked(int range, int length)
{
	node* start = new node;
	node* iter = start;
	for (int i = 0; i < length; i++)
	{
		iter->data = rand() % (range-1) + 1;
		if (i != length - 1)
		{
			node* gg = new node;
			iter->next = gg;
			iter = gg;
		}
		else
		{
			iter->next = 0;
		}
	}
	return start;
}
void printLinked(node* list)
{
	node* c = list;
	int counter = 1;
	while (c != 0)
	{
		cout << setw(2) << c->data << " ";
		if (counter % 10 == 0)
			cout << endl;
		c = c->next;
		counter++;
	}
}
void bucketLoop(node*& start, int digit)
{
	bucket* buckets[10];
	for (int x = 0; x < 10; x++)
		buckets[x] = new bucket();
	node* root = start;
	while (root->next != 0)
	{
		int temp = root->data % int(pow(10, digit));
		if (buckets[temp]->full)
		{
			//cout << buckets[temp];
			buckets[temp]->tail->next = root;
			buckets[temp]->tail = root;
		}
		else
		{
			buckets[temp]->head = root;
			buckets[temp]->tail = root;
			buckets[temp]->full = true;
		}
		root = root->next;
	}
	node* iter = new node;
	node* begin = new node;
	for (int i = 0; i < 10; i++)
	{
		if (buckets[i] != NULL)
		{
			if (begin->isEmpty){
				begin = buckets[i]->head;
				begin->isEmpty = false;
			}	
			iter->next = buckets[i]->head;
			iter = buckets[i]->tail;
		}
	}
	start = begin;
}
