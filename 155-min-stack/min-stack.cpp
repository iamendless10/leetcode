#include <vector>

class MinStack {
public:
    int curr;
    std::vector<int> stack;     
    std::vector<int> minStack;    
    int topi;
    
    MinStack() {
        topi = -1;
        curr = INT_MAX;
    }
    
    void push(int val) {
        topi++;
        stack.push_back(val); 
        
        if (val <= curr) {
            curr = val;
            minStack.push_back(val); 
        }
    }
    
    void pop() {
        if (topi == -1) {
            return;
        }
        
        if (stack[topi] == curr) {
            minStack.pop_back(); 
            curr = (minStack.empty()) ? INT_MAX : minStack.back();
        }
        
        stack.pop_back(); 
        topi--;
    }
    
    int top() {
        return stack[topi];
    }
    
    int getMin() {
        return curr;
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
