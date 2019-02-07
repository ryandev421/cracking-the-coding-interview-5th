#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *next;
	Node(int v, Node *n) : value(v), next(n) { }
};

void removeNode(Node *node)
{
    if (node == NULL || node->next == NULL) {
        return ;
    }

    Node *next = node->next;
    node->value = next->value;
    node->next = next->next;
}

int main()
{
    Node *head;
	head = new Node(1, NULL);
	
	Node *a = new Node(2,NULL);
	Node *b = new Node(3,NULL);
	Node *c = new Node(4,NULL);
	Node *d = new Node(5,NULL);
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;

	removeNode(c);

	while(head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}

    return 0;
}