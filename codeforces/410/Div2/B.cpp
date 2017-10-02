#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

string strs[51];


int str_dist(int b, int a) {

    if (!strs[a].compare(strs[b]))
        return 0;

    string temp = strs[b];
    for (int i=1; i<strs[a].size(); ++i) {
        rotate(temp.begin(), temp.begin()+1, temp.end());
        if (!strs[a].compare(temp))
            return i;
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i=0; i<n; ++i)
        cin >> strs[i];
    
    int min_dist = INT_MAX;
    int temp, cur_dist;
    for (int i=0; i<n; ++i) {
        cur_dist = 0;
        for (int j=0; j<n; ++j) {
            if (i == j)
               continue; 
            temp = str_dist(j, i);
            if (temp == -1){
                min_dist = -1;
                break;
            }
            cur_dist += temp;
        }
        if (cur_dist < min_dist)
            min_dist = cur_dist;
    }

    cout << min_dist << endl; 
    return 0;
}
