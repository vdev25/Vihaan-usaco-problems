#include <iostream>
#include <vector>
#include <stack>

#define ll long long

using namespace std;

ll forwardpass(vector<int> heights) {

	int n = heights.size();

	stack<pair<int, int>> passable;

	ll total = 0;

	passable.push(make_pair(heights[0], 0));

	for (int k = 1; k < n; k = k + 1) {
		pair<int, int> current = make_pair(heights[k], k);
		if (heights[k] < passable.top().first) {
			passable.push(current);
		}
		else {
			while (!passable.empty()) {
				if (heights[k] < passable.top().first) {
					passable.push(current);
					break;
				}
				pair<int, int> lastcow = passable.top();
				passable.pop();
				total += (k - lastcow.second) + 1;
			}
			if (passable.empty()) {
				passable.push(current);
			}
		}
	}

	return total;

}

int main() {
	int n;
	cin >> n;
	vector<int> heights(n, 0);

	for (int k = 0; k < n; k = k + 1) {
		int l;
		cin >> l;
		heights[k] = l;
	}
	
	ll total = 0;
	total += forwardpass(heights);

	vector<int> heights2(n, 0);

	for (int k = 0; k < n; k = k + 1) {
		heights2[(n - 1) - k] = heights[k];
	}

	total += forwardpass(heights2);

	cout << total;

	return 0;
}
