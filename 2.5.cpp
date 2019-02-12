#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *next;
	Node(int v, Node *n) : value(v), next(n) { }
};

Node* sum(Node *aNum, Node *bNum)
{
    int condition = 0;
    Node *head = NULL;
    Node *prev_node = NULL;
    Node *node = NULL;

    while (aNum != NULL || bNum != NULL || condition != 0) {
        int aNum_value = (aNum != NULL) ? aNum->value : 0;
        int bNum_value = (bNum != NULL) ? bNum->value : 0;
        int sum = aNum_value + bNum_value + condition;

        node = new Node(sum%10, NULL);
        condition = sum/10;

        if (head != NULL) {
            prev_node->next = node;
            prev_node = node;
        } else {
            head = node;
            prev_node = node;
        }

        if (aNum != NULL) {
            aNum = aNum->next;
        }
        if (bNum != NULL) {
            bNum = bNum->next;
        }
    }

    return head;
}

int main()
{
    Node *aHead, *bHead;
	aHead = new Node(7, NULL);
	Node *a = new Node(1,NULL);
	Node *b = new Node(6,NULL);
    aHead->next = a;
	a->next = b;
	

    bHead = new Node(5, NULL);
	Node *c = new Node(9,NULL);
	Node *d = new Node(2,NULL);
    bHead->next = c;
    c-> next = d;

	Node *head = sum(aHead, bHead);

	while(head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}

    return 0;
}