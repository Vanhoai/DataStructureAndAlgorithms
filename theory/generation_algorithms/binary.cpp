#include <iostream>
using namespace std;

int n, ok, X[100];

void init() {
    for (int i = 1; i <= n; i++)
        X[i] = 0;
}

int check_final() {
    for (int i = 1; i <= n; i++)
        if (X[i] == 0)
            return 0;

    return 1;
}

void generate() {
    int i = n;
    while (i >= 1 && X[i] == 1) {
        X[i] = 0;
        i--;
    }

    if (i == 0)
        ok = 0;
    else
        X[i] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    init();
    ok = 1;

    while (ok) {
        for (int i = 1; i <= n; i++) {
            cout << X[i] << " ";
        }

        cout << endl;
        generate();
    }

    return 0;
}
