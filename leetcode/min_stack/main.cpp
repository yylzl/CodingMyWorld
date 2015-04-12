#include <iostream>
#include <cstdint>
#include <climits>
#include <string>
#include <stack>

using namespace std;

class MinStack {
    private:
        stack<int> s;
        stack<int> s_min;

    public:
        void push(int x) {
            if(s_min.empty() || x <= s_min.top())
            {
                s_min.push(x);
            }
            s.push(x);
        }

        void pop() {
            if(s.top()==s_min.top())
            {
                s_min.pop();
            }
            s.pop();
        }

        int top() {
            return s.top();
        }

        int getMin() {
            return s_min.top();
        }
};

int main(int argc, char *argv[])
{
    MinStack *s = new MinStack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(2);
    cout << s->top() << endl;
    cout << s->getMin() << endl;
    return 0;
}

