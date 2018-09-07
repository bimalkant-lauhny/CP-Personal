class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string &A, string &B) {
        if (A.size() != B.size())
            return false;
            
        vector <int> cnt(256, 0);
        
        for (int i=0; i<A.size(); ++i) {
            ++cnt[A[i]];
        }
        
        for (int i=0 ;i<B.size(); ++i) {
            --cnt[B[i]];
        }
        
        for (int i=0; i<256; ++i) {
            if (cnt[i] != 0)
                return false;
        }
        
        return true;
    }
};
