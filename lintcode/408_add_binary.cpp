class Solution {
public:
    /**
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        if (a.size() < b.size()) {
            swap(a, b);
        }
        
        while(a.size() > b.size()) {
            b = '0' + b;
        }
        
        string res(a.size(), ' ');
        
        int carry = 0;
        for (int i=res.size()-1; i>=0; --i) {
            if (a[i] == '0' && b[i] == '0') {
                if (carry == 1) {
                    res[i] = '1';
                } else {
                    res[i] = '0';
                }
                carry = 0;
            } else if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')) {
                if (carry == 1) {
                    res[i] = '0';
                } else {
                    res[i] = '1';
                }
            } else if ((a[i] == '1' && b[i] == '1') || (a[i] == '1' && b[i] == '1')) {
                if (carry == 1) {
                    res[i] = '1';
                } else {
                    res[i] = '0';
                }
                carry = 1;
            }
        }
        
        if (carry == 1) {
            res = '1' + res;
        }
        
        return res;
    }
};
