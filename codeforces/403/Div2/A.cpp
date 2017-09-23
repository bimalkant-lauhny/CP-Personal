#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int cnt[100001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    fill(cnt, cnt+100001, 0); 

    int n;
    cin >> n;

    int lim = n << 1;
    int max_on_table = 0;
    int on_table = 0;
    int sock_no;
    for (int i=1; i<=lim; ++i) {
        cin >> sock_no;
        if (cnt[sock_no] == 0) {
            cnt[sock_no] = 1;
            ++on_table;
        } else {
            cnt[sock_no] = 0;
            --on_table;
        }
        max_on_table = max(on_table, max_on_table);
    }

    cout << max_on_table << endl;

    return 0;
}
