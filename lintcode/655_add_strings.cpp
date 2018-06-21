class Solution {
public:
    /**
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        int carry = 0;
        
        while(num1.size() < num2.size()) {
            num1 = "0" + num1;
        }
        
        while(num2.size() < num1.size()) {
            num2 = "0" + num2;
        }
        
        int pos = num1.size() - 1;
        
        string result = "";
        while(pos>=0) {
            int dig1 = static_cast<int>(num1[pos]) - static_cast<int>('0');
            int dig2 = static_cast<int>(num2[pos]) - static_cast<int>('0');
            
            int digSum = carry + dig1 + dig2;
            carry = 0;
            
            if (digSum > 9) {
                carry = 1;
                digSum -= 10;
            }
            
            result = static_cast<char>(digSum + static_cast<int>('0')) + result; 
            --pos;
        }
        
        if (carry == 1) {
            result = "1" + result;
        }
        
        return result;
    }
};
