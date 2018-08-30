class Solution {
public:
    /**
     * @param s: a string
     * @return: return a list of integers
     */
    vector<int> findPermutation(string &s) {
        int n = s.size() + 1;
        vector <int> perm;
        
        stack <int> st;
        
        for (int i=0; i<s.size(); ++i) {
            st.push(i+1);
            if (s[i] == 'I') {
                while (!st.empty()) {
                    perm.push_back(st.top());
                    st.pop();
                }
            }
        }
        
        st.push(n);
        while (!st.empty()) {
            perm.push_back(st.top());
            st.pop();
        }
        
        return perm;
    }
};
