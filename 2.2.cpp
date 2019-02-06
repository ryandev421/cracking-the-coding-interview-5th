#include <iostream>
#include <set>
using namespace std;

class Node
{
public:
	int value;
	Node *next;
	Node(int v, Node *n) : value(v), next(n) { }
};

Node* findKthNode(Node *head, int k)
{
	if (head == NULL) {
		return NULL;
	}
	Node *p1 = head;
	Node *p2 = head;
	for (int i = 0; i < k; i++) {
		if (p2 == NULL) {
			return NULL;
		} 
		p2 = p2->next;
	}
	while (p2 != NULL) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
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

	Node *kth_node = findKthNode(head, 3);

	cout << kth_node->value;

}