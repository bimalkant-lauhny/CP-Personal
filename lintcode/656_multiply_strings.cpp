class Solution {
public:
    /**
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return product of num1 and num2
     */
    
    void addStrings(string &s1, string &s2) {
        int carry = 0, val;
        int i=s1.size()-1, j=s2.size()-1;
        while(j>=0 && i>=0) {
            val = (s1[i] - '0') + (s2[j] - '0') + carry;
            carry = val / 10;
            val = val%10;
            s1[i] = val + '0';
            --i, --j;
        }
        
        while (carry) {
            val = (s1[i] - '0') + carry;
            carry = val / 10;
            val = val%10;
            s1[i] = val + '0';
            --i;
        }
    }
    
    string singleMultiply(string &num1, char c) {
        string mul = "";
        int carry = 0, val;
        for (int i=num1.size()-1; i>=0; --i) {
            val = (num1[i] - '0') * (c - '0') + carry;
            carry = val / 10;
            val = val%10;
            mul = (char)(val + '0') + mul;
        }
        if (carry) {
            mul = (char)(carry + '0') + mul;
        } 
        return mul;
    }
    
    string multiply(string &num1, string &num2) {
        if (num1 == "0" || num2 == "0")
            return string (1, '0');
        
        if (num1.size() < num2.size())
            swap(num1, num2);
            
        int m = num1.size(), n = num2.size();
        string res(n+m, '0');
        int e = 0;
        for (int i=n-1; i>=0; --i, ++e) {
            string s = singleMultiply(num1, num2[i]) + ((e>0)?string(e, '0'): "");
            addStrings(res, s);
        }
        
        if (res[0] == '0')
            res.erase(res.begin());
        return res; 
    }
};
