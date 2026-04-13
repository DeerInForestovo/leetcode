#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MAXN = 100005;
    static const enum {
        PUT, CALC, CLEAR
    };
    vector<int> adj[MAXN];
    int sz[MAXN], son[MAXN], dep[MAXN], group[MAXN];
    long long cnt[MAXN], sum_dep[MAXN];
    long long total_cost;

    void dfs_size(int u, int fa, int d) {
        sz[u] = 1;
        dep[u] = d;
        son[u] = -1;
        for (int v : adj[u]) {
            if (v == fa) continue;
            dfs_size(v, u, d + 1);
            sz[u] += sz[v];
            if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
        }
    }

    void node_update(int u, int fa, int root, int op) {
        int c = group[u];
        if (op == CLEAR) {
            cnt[c] = sum_dep[c] = 0;
        } else if (op == PUT) {
            cnt[c]++;
            sum_dep[c] += dep[u];
        } else if (op == CALC) {
            total_cost += sum_dep[c] + cnt[c] * dep[u] - 2 * cnt[c] * dep[root];
        }
    }

    void update(int u, int fa, int root, int op) {
        node_update(u, fa, root, op);
        for (int v : adj[u])
            if (v != fa) update(v, u, root, op);
    }

    void dfs_solve(int u, int fa, bool keep) {
        for (int v : adj[u])
            if (v != fa && v != son[u])
                dfs_solve(v, u, false);

        if (son[u] != -1)
            dfs_solve(son[u], u, true);
        
        node_update(u, fa, u, CALC);
        node_update(u, fa, u, PUT);

        for (int v : adj[u])
            if (v != fa && v != son[u]) {
                update(v, u, u, CALC);
                update(v, u, u, PUT);
            }

        if (!keep) update(u, fa, u, CLEAR);
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& g_in) {
        memset(cnt, 0, sizeof(cnt));
        memset(sum_dep, 0, sizeof(sum_dep));
        for (int i = 0; i < n; ++i) {
            group[i] = g_in[i];
        }
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs_size(0, -1, 0);
        total_cost = 0;
        dfs_solve(0, -1, true);
        return total_cost;
    }
};