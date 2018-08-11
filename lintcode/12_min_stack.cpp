class MinStack {
    stack <int> stk, minStk;
public:
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        stk.push(number);
        if (minStk.empty() || ( number <= minStk.top())) {
            minStk.push(number);
        }
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int number = stk.top();
        stk.pop();
        if (number == minStk.top())
            minStk.pop();
        return number;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
        return minStk.top();
    }
};
