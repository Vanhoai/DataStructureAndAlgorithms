#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int k;
        string s;
        cin >> k >> s;

        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;

        priority_queue<int> q;
        for (auto it : mp)
            q.push(it.second);

        int i = 0;
        while (!q.empty() && i++ < k) {
            int top = q.top();
            q.pop();
            top--;

            if (top > 0)
                q.push(top);
        }

        int res = 0;
        while (!q.empty()) {
            int top = q.top();
            q.pop();
            res += pow(top, 2);
        }

        cout << res << endl;
    }

    return 0;
}
