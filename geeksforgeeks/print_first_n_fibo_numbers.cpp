#include <bits/stdc++.h>
using namespace std;
long long fibomem[101];
long long fibo(int n){
	if (!fibomem[n])
		fibomem[n] = fibo(n-1) + fibo(n-2);
	return fibomem[n];
}

int main() {
	int t;
	cin >> t;
	fill(fibomem, fibomem+102, 0);
	fibomem[1] = fibomem[2] = 1;
	fibo(100);
	while(t--) {
		int n;
		cin >> n;
		for (int i=1; i<=n; ++i)
			cout << fibomem[i] << " ";
		cout << endl;
	}
	return 0;
}
