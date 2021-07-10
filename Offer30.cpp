#include <stack>
#include <cassert>

using std::stack;

class MinStack {
    stack<int> sData;
    stack<int> sMin;
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        sData.push(x);

        if (sData.size() ==0 || x < sMin.top())
            sMin.push(x);
        else
            sMin.push(sMin.top());
    }

    void pop() {
        assert(sData.size() >0 && sMin.size() >0);

        sMin.pop();
        sMin.pop();
    }

    int top() {
        assert(sData.size() >0);

        return sData.top();
    }

    int min() {
        assert(sMin.size() >0);

        return sMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
