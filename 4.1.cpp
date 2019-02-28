#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *left;
    Node *right;
    int height;

	Node(int v, Node *l, Node *r) : value(v), left(l), right(r) {
        height = 0;
    }
};

bool is_balanced_binary_tree(Node *head)
{
    if (head == NULL) {
        return false;
    }
    if (head->left != NULL && !is_balanced_binary_tree(head->left)) {
        return false;
    }
    if (head->right != NULL && !is_balanced_binary_tree(head->right)) {
        return false;
    }
    int left_height = (head->left != NULL) ? head->left->height : 0;
    int right_height = (head->right != NULL) ? head->right->height : 0;
    head->height = max(left_height, right_height) + 1;
    
    return (abs(left_height - right_height) <= 1);
}

int main()
{
    Node *head;
	head = new Node(1, NULL, NULL);
	Node *a = new Node(2,NULL, NULL);
	Node *b = new Node(3,NULL, NULL);
	Node *c = new Node(4,NULL, NULL);
	Node *d = new Node(5,NULL, NULL);
    head->left = a;
    head->right = b;
    b->left = c;
    c->right = d;

    cout << is_balanced_binary_tree(head);
    return 0;
}