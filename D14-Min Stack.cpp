
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
* MinStack() initializes the stack object.
* void push(val) pushes the element val onto the stack.
* void pop() removes the element on the top of the stack.
* int top() gets the top element of the stack.
* int getMin() retrieves the minimum element in the stack.
*/

/*
Time: O(1)
Space: O(n)
Stack with Pair.

only stack 

*/

class MinStack {
    stack<pair<int, int>> st;
public:
    /** initialize your data structure here. */
    MinStack() {
        // do nothing
    }
    
    void push(int val) {
        int mn;
        
        if (st.empty())
            mn = val;
        else
            mn = min(st.top().second, val);
        
        st.push({ val, mn });
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

class MinStack {
public:
    long long mini = INT_MAX;
    stack<long long>st;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long value = val;
         if(st.empty()){
             mini = value;
             st.push(value);
         }
        else{
            if(value < mini){
                long long ele = 2*value*1LL -mini;
                mini = value;
                st.push(ele);
            }
            else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        if(st.top() < mini){
            long long ele = st.top();
            mini = 2*mini -ele;
        }
        st.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        if(st.top() < mini)
            return mini;
        return st.top();
    }
    
    int getMin() {
        if(!st.empty())
          return mini;
        
        return -1;
    }
};
