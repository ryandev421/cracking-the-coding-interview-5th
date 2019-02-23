#include <iostream>
using namespace std;

class Node
{
public:
	int value;
	Node *next;
	Node(int v, Node *n) : value(v), next(n) { }
};

class Stack
{
    private:
        Node *top;
        Node *min;

    public:
        void push (int item)
        {
            if (top == NULL) {
                top = new Node(item, NULL);
                min = new Node(item, NULL);
            } else {
                Node *top_node = new Node(item, top);
                top = top_node;
                if (item <= min->value) {
                    Node *min_node = new Node(item, min);
                    min = min_node;
                }
            }
        }
        int pop()
        {
            if (top != NULL) {
                int item = top->value;
                if (top->value == min->value) {
                    min = min->next;
                }
                top = top->next;
                
                return item;
            }
            return -1;
        }
        int get_min()
        {
            if (min != NULL) {
                return min->value;
            }
            return -1;
        }
};

int main()
{
    Stack *stack = new Stack();
    stack->push(4);
    cout << stack->get_min() << endl;
    stack->push(1);
    cout << stack->get_min() << endl;
    stack->pop();
    cout << stack->get_min() << endl;
    stack->push(5);
    cout << stack->get_min() << endl;
    stack->push(3);
    cout << stack->get_min() << endl;
    
    return 0;
}