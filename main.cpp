#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Bellman Ford
 *
 * d[i] = INF(i: 1 -> n)
 * d[s] = 0
 * Loop n - 1 th
 *      Loop all edge in graph
 *      Relaxation
 */

struct Edge {
    int u;
    int v;
    int w;
};

int n, m, d[1001];
vector<Edge> edges;

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.PB((Edge) {u, v, w});
    }
}

void bellman_ford(int s) {
    ms(d, INF);
    d[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int k = 0; k < m; k++) {
            Edge tmp = edges[k];
            int u = tmp.u, v = tmp.v, w = tmp.w;
            if (d[u] < INF)
                d[v] = min(d[v], d[u] + w);
        }
    }

    REP(i, 1, n) cout << d[i] << " ";
}

int main() {
    SETUP;

    input();
    bellman_ford(1);

    return 0;
}