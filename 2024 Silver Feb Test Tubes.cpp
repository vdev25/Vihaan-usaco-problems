#include <iostream>
#include <vector>

using namespace std;

int main() {
    pair<int, int> t1, t2;

    int n, t;
    cin >> n >> t;

    string a, b;
    cin >> a >> b;

    t1.first = a[0] - '0';
    t2.first = b[0] - '0';

    for (int k = 0; k < n - 1; k = k + 1) {
        t1.second += (a[k] != a[k + 1]);
        t2.second += (b[k] != b[k + 1]);
    }

    //cout << t1.first << " " << t1.second << " " << t2.first << " " << t2.second << endl;

    int minmoves;

    if (t1.first == 0 && t2.first == 0) {
        minmoves = 1;
    }
    else {
        minmoves = (t1.second + t2.second + (t1.first == t2.first)) + 1;
    }

    cout << minmoves << endl;

    if (t == 2 || t == 3) {
        if (t1.first == t2.first) {
            if (t1.second % 2 != t2.second % 2) {
                
            } else {
                
            }
        }
    }

    

    return 0;
}