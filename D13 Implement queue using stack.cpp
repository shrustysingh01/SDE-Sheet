/*
Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
* void push(int x) Pushes element x to the back of the queue.
* int pop() Removes the element from the front of the queue and returns it.
* int peek() Returns the element at the front of the queue.
* boolean empty() Returns true if the queue is empty, false otherwise.
*/

/*
Time: O(1) for push, O(n) worst for pop, O(1) amortized for pop
Space: O(1)
*/

class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    int first;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            first = x;
        }
        s1.push(x);
    }
    
    int pop() {
        int s = s1.size();
        for(int i = 0 ; i < s ; i++){
            s2.push(s1.top());
            s1.pop();
        }
        
        int x = s2.top();
        
        s2.pop();
        if(!s2.empty()){
            first = s2.top();
        }
        else{
            first = -1;
        }
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
        return x;
    }
    
    int peek() {
        return first;
    }
    
    bool empty() {
        return s1.empty();
    }
};