#include <iostream>
#include <vector>

using namespace std;

struct query {
    int len;
    int type;
    string s1;
    string s2;
};

void solve(query q) {
    
    pair<int, int> t1;
    pair<int, int> t2;

    int n = q.len;
    int t = q.type;
    string a = q.s1;
    string b = q.s2;


    t1.first = a[0] - '0';
    t2.first = b[0] - '0';

    for (int k = 0; k < n - 1; k = k + 1) {
        t1.second += (a[k] != a[k + 1]);
        t2.second += (b[k] != b[k + 1]);
    }

    int minmoves;

    if (t1.second == 0 && t2.second == 0) {
        minmoves = 0;
    }
    else if (t1.first != t2.first && t1.second + t2.second == 1) {
        minmoves = 1;
    }
    else {
        minmoves = (t1.second + t2.second + (t1.first == t2.first)) + 1;
    }

    cout << minmoves << endl;

    if (t == 2 || t == 3) {
        if (t1.first == t2.first) {
            if (t1.second % 2 == t2.second % 2) {
                if (t1.second >= t2.second) {
                    cout << "1 2" << endl;
                    t1.second -= 1;
                }
                else {
                    cout << "2 1" << endl;
                    t2.second -= 1;
                }
            }
            if (t1.second % 2 != t2.second % 2) {
                if (t1.second % 2 == 0) {
                    for (int k = 0; k <= t1.second; k = k + 1) {
                        if (k % 2 == 0) {
                            cout << "1 3" << endl;
                        }
                        else {
                            cout << "1 2" << endl;
                        }
                    }
                    for (int k = 0; k < t2.second; k = k + 1) {
                        if (k % 2 == 0) {
                            cout << "2 1" << endl;
                        }
                        else {
                            cout << "2 3" << endl;
                        }
                    }
                    cout << "3 2" << endl;
                }
                else {
                    for (int k = 0; k <= t2.second; k = k + 1) {
                        if (k % 2 == 0) {
                            cout << "2 3" << endl;
                        }
                        else {
                            cout << "2 1" << endl;
                        }
                    }
                    for (int k = 0; k < t1.second; k = k + 1) {
                        if (k % 2 == 0) {
                            cout << "1 2" << endl;
                        }
                        else {
                            cout << "1 3" << endl;
                        }
                    }
                    cout << "3 1" << endl;
                }
            }
        }
        else {
            if (t1.second % 2 != t2.second % 2) {
                if (t1.second >= t2.second) {
                    cout << "1 2" << endl;
                    t1.second -= 1;
                }
                else {
                    cout << "2 1" << endl;
                    t2.second -= 1;
                }
            }
            if (t1.second % 2 == t2.second % 2) {
                if (t1.second != 0 || t2.second != 0) {
                    if (t1.second >= t2.second) {
                        cout << "1 3" << endl;
                        if (t1.second % 2 == 0) {
                            for (int k = 0; k < t2.second; k = k + 1) {
                                if (k % 2 == 0) {
                                    cout << "2 1" << endl;
                                }
                                else {
                                    cout << "2 3" << endl;
                                }
                            }
                            for (int k = 0; k < t1.second - 1; k = k + 1) {
                                if (k % 2 == 0) {
                                    cout << "1 2" << endl;
                                }
                                else {
                                    cout << "1 3" << endl;
                                }
                            }
                            cout << "3 1" << endl;
                        }
                        else {
                            for (int k = 0; k < t1.second - 1; k = k + 1) {
                                if (k % 2 == 0) {
                                    cout << "1 2" << endl;
                                }
                                else {
                                    cout << "1 3" << endl;
                                }
                            }
                            for (int k = 0; k < t2.second; k = k + 1) {
                                if (k % 2 == 0) {
                                    cout << "2 1" << endl;
                                }
                                else {
                                    cout << "2 3" << endl;
                                }
                            }
                            cout << "3 2" << endl;
                        }
                    }
                    else {
                        cout << "2 3" << endl;
                        if (t2.second % 2 == 0) {
                            for (int k = 0; k < t1.second; k = k + 1) {
                                if (k % 2 == 0) {
                                    cout << "1 2" << endl;
                                }
                                else {
                                    cout << "1 3" << endl;
                                }
                            }
                            for (int k = 0; k < t2.second - 1; k = k + 1) {
                                if (k % 2 == 0) {
                                    cout << "2 1" << endl;
                                }
                                else {
                                    cout << "2 3" << endl;
                                }
                            }
                            cout << "3 2" << endl;
                        }
                        else {
                            for (int k = 0; k < t2.second - 1; k = k + 1) {
                                if (k % 2 == 0) {
                                    cout << "2 1" << endl;
                                }
                                else {
                                    cout << "2 3" << endl;
                                }
                            }
                            for (int k = 0; k < t1.second; k = k + 1) {
                                if (k % 2 == 0) {
                                    cout << "1 2" << endl;
                                }
                                else {
                                    cout << "1 3" << endl;
                                }
                            }
                            cout << "3 1" << endl;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    pair<int, int> t1, t2;

    int tt;
    cin >> tt;

    vector<query> ins;

    query q;
    for (int k = 0; k < tt; k = k + 1) {
        int n, t;
        cin >> n >> t;

        string a, b;
        cin >> a >> b;
        q.len = n;
        q.type = t;
        q.s1 = a;
        q.s2 = b;

        ins.push_back(q);
    }

    for (query q : ins) {
        solve(q);
    }

    return 0;
}