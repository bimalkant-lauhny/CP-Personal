#include <bits/stdc++.h>
using namespace std;

auto allIntervals(pair <int, int> &i1, pair <int, int> &i2) {
	vector< pair<int, int> > v;

	if (i2.second <= i1.first || i2.first >= i1.second) {
		// i2 does not overlap with i1
		v.push_back(i1);
		v.push_back(i2);
	} else {
		// overlapping
		if (i2.first < i1.first) {
			v.push_back(make_pair(i2.first, i1.first));
			if (i2.second < i1.second) {
				v.push_back(make_pair(i1.first, i2.second));
				v.push_back(make_pair(i2.second, i1.second));
			} else if (i2.second == i1.second){
				v.push_back(i1);
			} else {
				v.push_back(i1);
				v.push_back(make_pair(i1.second, i2.second));
			}
		} else if (i2.first == i1.first){
			if (i2.second < i1.second) {
				v.push_back(i2);
				v.push_back(make_pair(i2.second, i1.second));
			} else if (i2.second == i1.second) {
				v.push_back(i2);	
			} else {
				v.push_back(i1);
				v.push_back(make_pair(i1.second, i2.second));
			}
		} else {
			v.push_back(make_pair(i1.first, i2.first));
			if (i2.second < i1.second) {
				v.push_back(i2);	
				v.push_back(make_pair(i2.second, i1.second));
			} else if (i2.second == i1.second) {
				v.push_back(i2);	
			} else {
				v.push_back(make_pair(i2.first, i1.second));
				v.push_back(make_pair(i1.second, i2.second));
			}
		}
	}

	return v;
}

int main() {
	pair <int, int> i1, i2;
	cin >> i1.first >> i1.second;
	cin >> i2.first >> i2.second;
	vector < pair <int, int> > v = allIntervals(i1, i2);
	for (auto const& i: v) {
		cout << "("	<< i.first << ", " << i.second << "), ";
	}
	cout << endl;
}