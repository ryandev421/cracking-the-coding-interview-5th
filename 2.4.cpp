#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *next;
	Node(int v, Node *n) : value(v), next(n) { }
};

Node* replaceList(Node *head, int x)
{
    Node *front_head = NULL, *front_tail = NULL;
    Node *back_head = NULL, *back_tail = NULL;

    while (head != NULL) {
        if (head->value < x) {
            if (front_head == NULL) {
                front_head = head;
                front_tail = head;
            } else {
                front_tail->next = head;
                front_tail = head;
            }
        } else {
            if (back_head == NULL) {
                back_head = head;
                back_tail = head;
            } else {
                back_tail->next = head;
                back_tail = head;
            }
        }
        head = head->next;
    }
    
    if (front_head != NULL && back_head != NULL) {
        front_tail->next = back_head;    
    } else if (front_head == NULL) {
        front_head = back_head;
    }

    if (back_tail != NULL) {
        back_tail->next = NULL;
    }

    return front_head;
}

int main()
{
    Node *head;
	head = new Node(4, NULL);
	
	Node *a = new Node(1,NULL);
	Node *b = new Node(2,NULL);
	Node *c = new Node(5,NULL);
	Node *d = new Node(3,NULL);
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;

	head = replaceList(head, 4);

	while(head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}

    return 0;
}