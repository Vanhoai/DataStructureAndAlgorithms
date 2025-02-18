#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    SETUP;

    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;

    int ans = a[0];
    for (int i = 1; i < n; i++) {
        ans = lcm(ans, a[i]);
    }

    cout << ans << endl;

    return 0;
}