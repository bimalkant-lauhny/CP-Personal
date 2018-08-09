class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        if (source == nullptr || target == nullptr) {
            return -1;     
        }
        
        int slen = strlen(source), tlen = strlen(target);
        
        // construct trans array        
        vector <int> trans(tlen); 
        int j = 0, i = 1;
        while (i < tlen) {
            if (target[i] == target[j]) {
                trans[i] = j+1;
                ++i;
                ++j;
            } else {
                if (j == 0) {
                    trans[i] = 0;
                    ++i;
                } else {
                    j = trans[j-1];
                }
            }
        }
        
        // use KMP to search 
        i=0, j=0;
        while (i<slen && j<tlen) {
            if (source[i] == target[j]) {
                ++i;
                ++j;
            } else {
                if (j==0) {
                    ++i;    
                } else {
                    j = trans[j-1];
                } 
            } 
        } 
        
        // check if string matched 
        if (j == tlen) {
            return i - tlen;
        } else {
            return -1;    
        }
    }
};
