#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
	int value;
	TreeNode *left;
    TreeNode *right;

	TreeNode(int v, TreeNode *l, TreeNode *r) : value(v), left(l), right(r) {}
};

class LinkedListNode
{
public:
	int value;
	LinkedListNode *next;

	LinkedListNode(int v, LinkedListNode *n) : value(v), next(n) {}
};

void generate_list_by_depth(TreeNode *head, vector<LinkedListNode *> &depth_list, int depth)
{
    if (head == NULL) {
        return ;
    }
    if (depth_list.size() < depth + 1) {
        depth_list.push_back(NULL);
    }

    LinkedListNode *depth_new_head = new LinkedListNode(head->value, depth_list[depth]);
    depth_list[depth] = depth_new_head;

    if (head->left != NULL) {
        generate_list_by_depth(head->left, depth_list, depth + 1);
    }
    if (head->right != NULL) {
        generate_list_by_depth(head->right, depth_list, depth + 1);
    }
}

int main()
{
    TreeNode *head;
	head = new TreeNode(1, NULL, NULL);
	TreeNode *a = new TreeNode(2,NULL, NULL);
	TreeNode *b = new TreeNode(3,NULL, NULL);
	TreeNode *c = new TreeNode(4,NULL, NULL);
	TreeNode *d = new TreeNode(5,NULL, NULL);
    head->left = a;
    head->right = b;
    b->left = c;
    c->right = d;

    vector<LinkedListNode *> depth_list;
    generate_list_by_depth(head, depth_list, 0);

    for (int i = 0; i < depth_list.size(); i++) {
        cout << "DEPTH " << i << ": ";
        for (LinkedListNode *node = depth_list[i]; node != NULL; node = node->next) {
            cout << node->value << " ";
        }
        cout << endl;
    }
    return 0;
}