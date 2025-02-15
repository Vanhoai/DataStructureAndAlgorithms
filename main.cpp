#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, parent[1001];
vector<int> adj[1001];
vector<int> leafs;
bool visited[1001];

void input() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    REP(i, 2, n) if (adj[i].size() == 1) leafs.PB(i);
    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

void path(int u, int v) {
    vector<int> p;
    while (u != v) {
        p.PB(v);
        v = parent[v];
    }

    p.PB(u);
    reverse(all(p));
    FOR(i, 0, sz(p)) cout << p[i] << " ";
    cout << endl;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();
        ms(visited, false);
        dfs(1);

        FOR(i, 0, sz(leafs)) path(1, leafs[i]);
        REP(i, 1, n) adj[i].clear();
        leafs.clear();
    }

    return 0;
}