#include <iostream>
#include <stack>
using namespace std;

class SortedStack
{
    private:
        stack<int> m_stack;

    public:
        void push(int item)
        {
            stack<int> tmp;
            while (!m_stack.empty() && m_stack.top() > item) {
                tmp.push(m_stack.top());
                m_stack.pop();
            }
            m_stack.push(item);
            while (!tmp.empty()) {
                m_stack.push(tmp.top());
                tmp.pop();
            }
        }
        void pop()
        {
            m_stack.pop();
        }
        int top()
        {
            return m_stack.top();
        }
};

int main()
{
    SortedStack stack;
    stack.push(4);
    cout << stack.top() << endl;
    stack.push(1);
    cout << stack.top() << endl;
    stack.push(5);
    cout << stack.top() << endl;
    stack.push(2);
    cout << stack.top() << endl;
    stack.push(7);
    cout << stack.top() << endl;
    return 0;
}