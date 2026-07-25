#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll solve(ll a, ll b) {
	vector<ll> alist, blist;

	alist.push_back(a);
	blist.push_back(b);

	while (a != 1) {
		if (a % 2 == 0) {
			a = a / 2;
		}
		else {
			a = a + 1;
		}
		alist.push_back(a);
	}

	while (b != 1) {
		if (b % 2 == 0) {
			b = b / 2;
		}
		else {
			b = b - 1;
		}
		blist.push_back(b);
	}

	ll minmoves = 1e16;

	for (int k = 0; k < alist.size(); k = k + 1) {
		for (int l = 0; l < blist.size(); l = l + 1) {
			if (alist[k] < blist[l]) {
				minmoves = min(minmoves, (k + l + blist[l] - alist[k]));
			}
		}
	}

	if (minmoves == 1e16) {
		minmoves = 0;
	}

	return minmoves;
}

int main() {

	int n;
	cin >> n;

	vector<ll> ans;

	for (int k = 0; k < n; k = k + 1) {
		int a, b;
		cin >> a >> b;
		ans.push_back(solve(a, b));
	}

	for (ll k : ans) {
		cout << k << endl;
	}

	return 0;
}
