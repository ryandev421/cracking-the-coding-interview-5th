#include <iostream>
#include <limits.h>
using namespace std;

class TreeNode
{
public:
	int value;
	TreeNode *left;
    TreeNode *right;

	TreeNode(int v, TreeNode *l, TreeNode *r) : value(v), left(l), right(r) {}
};

bool is_valid_value_in_range(TreeNode *head, int min_value, int max_value)
{
    if (head == NULL) {
        return true;
    }

    if (head->value <= min_value || head->value >= max_value) {
        return false;
    }

    return (is_valid_value_in_range(head->left, min_value, head->value) && is_valid_value_in_range(head->right, head->value, max_value));
}

bool is_bst(TreeNode * head)
{
    return is_valid_value_in_range(head, numeric_limits<int>::min(), numeric_limits<int>::max());
}

int main()
{
    TreeNode *head;
	head = new TreeNode(3, NULL, NULL);
	TreeNode *a = new TreeNode(1,NULL, NULL);
	TreeNode *b = new TreeNode(5,NULL, NULL);
	TreeNode *c = new TreeNode(4,NULL, NULL);
	TreeNode *d = new TreeNode(6,NULL, NULL);
    head->left = a;
    head->right = b;
    b->left = c;
    c->right = d;

    cout << is_bst(head);
    return 0;
}