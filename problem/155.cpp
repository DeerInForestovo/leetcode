#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class MinStack {
public:
    stack<pair<int, int>> stk;

    MinStack() {
        stk.push({INT_MAX, INT_MAX});
    }
    
    void push(int val) {
        stk.push({val, min(val, stk.top().second)});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    
    return 0;
}
#endif