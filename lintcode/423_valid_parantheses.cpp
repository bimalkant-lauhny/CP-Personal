class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isOrderedComplementary(char const &c1, char const &c2) {
        if (c1 == '(' && c2 == ')' || 
            c1 == '{' && c2 == '}' || 
            c1 == '[' && c2 == ']') {
            return true;
        } else {
            return false;
        }
    }
    
    bool isValidParentheses(string &s) {
        stack <int> myStack;
        
        myStack.push(0);
        
        for (int i=1; i<s.size(); ++i) {
            if (!myStack.empty() && 
                isOrderedComplementary(s[myStack.top()], s[i])) {
                myStack.pop();
            } else {
                myStack.push(i);
            }
        }
        
        return myStack.empty();
    }
};
