/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
* Open brackets must be closed by the same type of brackets.
* Open brackets must be closed in the correct order.
*/

/*
Time: O(n)
Space: O(n)
Stack.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else if(!st.empty()){
                if(st.top() == '{' && s[i] == '}')
                    st.pop();
                else if(st.top() == '[' && s[i] == ']')
                    st.pop();
                else if(st.top() == '(' && s[i] == ')')
                    st.pop();
                else 
                    return false;
            }
            else{
                return false;
            }
        }
        
        return st.empty();
    }
};