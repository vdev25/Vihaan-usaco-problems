#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int len, n;
    cin >> len >> n;

    int maxv = (1 << len);

    vector<int> teams(n, 0);

    for (int k = 0; k < n; k = k + 1) {
        string s;
        cin >> s;

        int i = 0;

        for (int l = 0; l < len; l = l + 1) {
            i += (s[l] - 'G');
            i *= 2;
        }

        i /= 2;

        teams[k] = i;
    }

    //for (int k : teams) {
    //    cout << k << endl;
    //}

    vector<int> dists(maxv, 100);

    queue<int> q;

    for (int k : teams) {
        dists[k] = 0;
        q.push(k);
    }

    while (q.size() != 0) {
        int k = q.front();
        q.pop();

        for (int l = 0; l < len; l = l + 1) {
            if (dists[(k ^ (1 << l))] == 100) {
                dists[(k ^ (1 << l))] = dists[k] + 1;
                q.push(k ^ (1 << l));
            }
        }
    }

    for (int k : teams) {
        cout << (len - (dists[(maxv - 1) - k])) << endl;
    }
}