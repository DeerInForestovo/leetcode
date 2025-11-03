#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2000000 + 10;
const int MaxC = 26;
int n;
string s;
struct SAM {
    struct node {
        int len, fail, occ;
        vector<int> to;
        node() {
            len = fail = occ = 0;
            to.resize(MaxC, 0);
        }
    };
    int cnt, last;
    vector<node> nodes;
    SAM() {
        cnt = last = 0;
        nodes.resize(MaxN);
        nodes[0].fail = -1;
    }
    void insert(int c) {
        int cur = ++cnt, p, q, clone;
        nodes[cur].len = nodes[last].len + 1;
        nodes[cur].occ = 1;
        for (p = last; p != -1 && nodes[p].to[c] == 0; p = nodes[p].fail) {
            nodes[p].to[c] = cur;
        }
        if (p == -1) {
            nodes[cur].fail = 0;
        } else {
            q = nodes[p].to[c];
            if (nodes[p].len + 1 == nodes[q].len) {
                nodes[cur].fail = q;
            } else {
                clone = ++cnt;
                nodes[clone].to = nodes[q].to;
                nodes[clone].fail = nodes[q].fail;
                nodes[clone].len = nodes[p].len + 1;
                nodes[clone].occ = 0;
                nodes[q].fail = nodes[cur].fail = clone;
                while (p != -1 && nodes[p].to[c] == q) {
                    nodes[p].to[c] = clone;
                    p = nodes[p].fail;
                }
            }
        }
        last = cur;
    }
} sam;
int main() {
    cin >> s;
    n = s.length();
    for (auto c: s)
        sam.insert(c - 'a');
    vector<int> cnt(n + 1, 0);
    vector<int> ord(sam.cnt + 1, 0);
    for (int i = 1; i <= sam.cnt; ++i)
        ++cnt[sam.nodes[i].len];
    for (int i = 1; i <= n; ++i)
        cnt[i] += cnt[i-1];
    for (int i = 1; i <= sam.cnt; ++i)
        ord[cnt[sam.nodes[i].len]--] = i;
    long long maxans = 1;
    for (int i = sam.cnt; i; --i) {
        int v = ord[i], fail = sam.nodes[v].fail;
        if (fail != -1)
            sam.nodes[fail].occ += sam.nodes[v].occ;
        if (sam.nodes[v].occ != 1)
            maxans = max(maxans, 1ll * sam.nodes[v].occ * sam.nodes[v].len);
    }
    cout << maxans << endl;
    return 0;
}