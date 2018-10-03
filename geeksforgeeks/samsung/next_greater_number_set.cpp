#include <bits/stdc++.h>
using namespace std;

bool getNextGreater(string &num) {
    int f = num.size() - 2;
    while(f >= 0 && num[f] >= num[f+1]) f--;
    if(f == -1)
        return false;
    int s = num.size() - 1;
    while(num[f] >= num[s]) s--;
    swap(num[f], num[s]);
    reverse(num.begin()+f+1, num.end());
    return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    string num;
	    cin >> num;
	    if(getNextGreater(num))
	        cout << num;
	    else
	        cout << "not possible";
	    cout  << endl;
	}
	return 0;
}
