#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
2
2
3

output:
21 12
321 312 231 213 132 123

 */

int n, ok, g[100];

void init() { REP(i, 1, n) g[i] = n - i + 1; }

void gen() {
    int i = n - 1;
    while (i >= 1 && g[i] < g[i + 1])
        i--;

    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (g[i] < g[j])
            j--;

        swap(g[i], g[j]);
        reverse(g + i + 1, g + n + 1);
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        init();

        ok = 1;
        while (ok) {
            REP(i, 1, n) cout << g[i];
            cout << " ";

            gen();
        }

        cout << endl;
    }

    return 0;
}