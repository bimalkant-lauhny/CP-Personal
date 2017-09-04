#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int facts[13];

int get_fact(int n) {
    if (facts[n] == 0)
        facts[n] = n * get_fact(n-1);
    return facts[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(facts, facts+13, 0);
    facts[0] = facts[1] = 1;
    int a, b;
    cin >> a >> b;

    cout << get_fact(min(a, b)) << endl;
    return 0;
}
