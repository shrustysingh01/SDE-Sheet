
/*
Implement a last-in-first-out (LIFO) stack using only two queues. 
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
Implement the MyStack class:
* void push(int x) Pushes element x to the top of the stack.
* int pop() Removes the element on the top of the stack and returns it.
* int top() Returns the element on the top of the stack.
* boolean empty() Returns true if the stack is empty, false otherwise.
*/

/*
Time: O(n) for push, O(1) for pop
Space: O(1)
*/

class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    int last;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        last = x;
    }
    
    int pop() {
        if(q1.empty())
            return -1;
       int ele = last;
       int s = q1.size();
        for(int i = 0 ; i < s-1 ;i++){
            int x = q1.front();
            q1.pop();
            q1.push(x);
            last = x;
        }
        q1.pop();
        return ele;
    }
    
    int top() {
       return last;
    }
    
    bool empty() {
        return q1.empty();
    }

};
