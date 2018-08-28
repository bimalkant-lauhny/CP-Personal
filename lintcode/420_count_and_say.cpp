class Solution {
public:
    /**
     * @param n: the nth
     * @return: the nth sequence
     */
    string countAndSay(int n) {
        string res = "1", cur;
        for (int i=2; i<=n; ++i) {
            cur = "";
            int l = res.size();
            int cnt = 1;
            for (int j=l-2; j>=0; --j) {
                if(res[j] == res[j+1]) {
                    ++cnt;
                } else {
                    cur = to_string(cnt) + res[j+1] + cur;
                    cnt = 1;
                }
            }
            cur = to_string(cnt) + res[0] + cur;
            res = cur;
        }
        return res;
    }
};
