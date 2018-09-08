class Solution {
public:
    /**
     * @param version1: the first given number
     * @param version2: the second given number
     * @return: the result of comparing
     */
    int compareVersion(string &version1, string &version2) {
        int v1 = 0, v2 = 0, i=0, j=0;
        while (i<version1.size() || j<version2.size()) {
            while(i<version1.size() && version1[i] != '.') {
                v1 = v1 * 10 + (version1[i] - '0');
                ++i;
            }
            
            while(j<version2.size() && version2[j] != '.') {
                v2 = v2 * 10 + (version2[j] - '0');
                ++j;
            }
            
            if (v1 > v2)
                return 1;
            else if (v2 > v1)
                return -1;
            else {
                v1 = v2 = 0;
                ++i;
                ++j;
            }
        }
        
        return 0;
    }
};
