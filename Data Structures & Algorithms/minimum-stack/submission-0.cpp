class MinStack {
public:
    stack<int> stack_elements;
    stack<int> stack_min;

    MinStack() {
    }
    
    void push(int val) {
        int top_stack_min;
        int value_to_push;
        if (!stack_elements.empty()) {
            top_stack_min = stack_min.top();
            value_to_push = min(val, top_stack_min);
        } else {
            value_to_push = val;
        }
        stack_elements.push(val);
        stack_min.push(value_to_push);
    }
    
    void pop() {
        stack_elements.pop();
        stack_min.pop();
    }
    
    int top() {
        int top = stack_elements.top();
        return top;
    }
    
    int getMin() {
        int min = stack_min.top();
        return min;
    }
};