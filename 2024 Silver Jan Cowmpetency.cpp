#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int> scores, const vector<pair<int, int>>& pairs, int maxscore) { //assumes pairs vector is sorted, scores vector is 1-indexed
    vector<int> fail = { -1 };
    int n = scores.size() - 1;

    vector<int> original = scores;

    vector<int> greatercow(n + 1, -1);

    for (pair<int, int> k : pairs) {
        if (greatercow[k.first] != -1 && greatercow[k.first] != k.second) {
            return fail;
        }
        if (greatercow[k.first] == -1) {
            for (int l = k.first; l < k.second; l = l + 1) {
                greatercow[l] = k.second;
            }
        }
    }

    for (int k = 1; k <= n; k = k + 1) {
        if (scores[k] == 0) {
            scores[k] = 1;
        }
    }

    int smallmax, bigmax;
    smallmax = 0;
    bigmax = 0;

    for (int k = 1; k <= n; k = k + 1) {
        smallmax = max(smallmax, scores[k]);

        if (greatercow[k] == -1) {
            continue;
        }

        bigmax = smallmax;

        for (int l = k; l < greatercow[k]; l = l + 1) {
            bigmax = max(bigmax, scores[l]);
        }

        if (smallmax < bigmax) {
            for (int j = k; j >= 0; j = j - 1) {
                if (greatercow[j] != -1 && greatercow[j] < greatercow[k]) {
                    return fail;
                }
                if (original[j] != 0) {
                    continue;
                }
                scores[j] = bigmax;
                smallmax = bigmax;
                break;
            }
        }

        if (original[greatercow[k]] == 0) {
            scores[greatercow[k]] = bigmax + 1;
        }
        else {
            if (original[greatercow[k]] <= bigmax) {
                return fail;
            }
        }

        k = greatercow[k] - 1;
        continue;
    }

    for (int k : scores) {
        if (k > maxscore) {
            return fail;
        }
    }

    return scores;

}

int main() {

    int t;
    cin >> t;

    vector<vector<int>> ans;

    for (int k = 0; k < t; k = k + 1) {
        int n, q, c;
        cin >> n >> q >> c;
        vector<int> scores;
        scores.push_back(0);
        for (int l = 0; l < n; l = l + 1) {
            int a;
            cin >> a;
            scores.push_back(a);
        }
        vector<pair<int, int>> pairs;
        for (int l = 0; l < q; l = l + 1) {
            int a, b;
            cin >> a >> b;
            pairs.push_back(make_pair(a, b));
        }

        sort(pairs.begin(), pairs.end());

        ans.push_back(solve(scores, pairs, c));

    }

    for (int k = 0; k < ans.size(); k = k + 1) {
        for (int l = 0; l < ans[k].size(); l = l + 1) {
            if (ans[k][l] == 0) {
                continue;
            }
            cout << ans[k][l];
            if (l != ans[k].size() - 1) {
                cout << " ";
            }
        }
        if (k != ans.size() - 1) {
            cout << endl;
        }
    }

    return 0;
}