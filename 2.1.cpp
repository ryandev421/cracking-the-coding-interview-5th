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

void removeDuplicatedValue(Node *head)
{
	set<int> found_set;

	Node *current = head;
	Node *before;
	while(current != NULL) {
		if (found_set.find(current->value) != found_set.end()) {
			before->next = current->next;
		} else {
			found_set.insert(current->value);
			before = current;
		}
		current = current->next;
	}
}

int main()
{
	Node *head;
	head = new Node(3, NULL);
	
	Node *a = new Node(2,NULL);
	Node *b = new Node(1,NULL);
	Node *c = new Node(3,NULL);
	Node *d = new Node(3,NULL);
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = d;

	removeDuplicatedValue(head);

	while(head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}

}