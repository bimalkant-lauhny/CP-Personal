#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int min_flicks(string ms, string ss) {
    int m_cnt[10], s_cnt[10];
    fill(m_cnt, m_cnt+10, 0);
    fill(s_cnt, s_cnt+10, 0);

    int len = ss.size();

    for (int i=0; i<len; ++i) {
        ++m_cnt[ms[i] - '0'];
        ++s_cnt[ss[i] - '0'];
    }

    int flicks = 0;
    for (int i=0; i<10; ++i) {
        while (s_cnt[i]--) {
            int j=i;
            while (j<10) {
                if (m_cnt[j]){
                    --m_cnt[j];
                    break;
                }
                ++j;
            }
            if (j >= 10)
                ++flicks;
        }
    }
    return flicks;
}

int max_flicks(string ms, string ss) {
    int m_cnt[10], s_cnt[10];
    fill(m_cnt, m_cnt+10, 0);
    fill(s_cnt, s_cnt+10, 0);

    int len = ss.size();

    for (int i=0; i<len; ++i) {
        ++m_cnt[ms[i] - '0'];
        ++s_cnt[ss[i] - '0'];
    }

    int flicks = 0;
    for (int i=0; i<10; ++i) {
        while(s_cnt[i]--) {
            int j = i+1;  
            while (j<10) {
                if (m_cnt[j]) {
                    --m_cnt[j];
                    ++flicks;
                    break;
                } 
                ++j;
            }
        }
    }

    return flicks;
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;

    string mcc, scc;
    cin >> scc;
    cin >> mcc;
    
    cout << min_flicks(mcc, scc) << endl;
    cout << max_flicks(mcc, scc) << endl;

    return 0;
}
