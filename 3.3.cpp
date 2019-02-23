#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class SetOfStacks
{
    private:
        static const int max_item_count = 3;
        vector<stack<int> > set_of_stacks;

    public:
        void push(int item)
        {
            if (set_of_stacks.size() == 0 || set_of_stacks.back().size() == max_item_count) {
                stack<int> s;
                s.push(item);
                set_of_stacks.push_back(s);
            } else {
                set_of_stacks.back().push(item);
            }
        }
        void pop()
        {
            stack<int> s = set_of_stacks.back();
            s.pop();
            if (s.size() == 0) {
                set_of_stacks.pop_back();
            }
        }
        int top()
        {
            return set_of_stacks.back().top();
        }
        
};

int main()
{
    SetOfStacks stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
}