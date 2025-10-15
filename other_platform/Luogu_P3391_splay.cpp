#include <bits/stdc++.h>
using namespace std;

struct Splay {
    Splay *ch[2], *f;
    int sz, val;
    bool rev;
    Splay(int v = 0) : f(nullptr), sz(1), val(v), rev(false) {
        ch[0] = ch[1] = nullptr;
    }

    void pushup() {
        sz = 1;
        if (ch[0]) sz += ch[0]->sz;
        if (ch[1]) sz += ch[1]->sz;
    }

    void pushdown() {
        if (rev) {
            rev = false;
            swap(ch[0], ch[1]);
            if (ch[0]) ch[0]->rev ^= 1;
            if (ch[1]) ch[1]->rev ^= 1;
        }
    }
} splay;

void splay_rotate(Splay* &x) {
    // cerr << "Rotating node with value: " << x->val << endl; // Debug statement
    Splay* p = x->f;
    p->pushdown();
    x->pushdown();
    
    short d = (p->ch[1] == x);
    p->ch[d] = x->ch[d ^ 1];
    if (p->ch[d]) p->ch[d]->f = p;
    
    Splay* g = p->f;
    if (g) g->ch[g->ch[1] == p] = x;
    x->f = g;
    
    x->ch[d ^ 1] = p;
    p->f = x;
    
    p->pushup();
    x->pushup();
}

void splay_splay(Splay* &root, Splay* x) {
    // cerr << "Splaying node with value: " << x->val << endl; // Debug statement
    Splay *root_f = root->f;
    while (x->f != root_f) {
        if (x->f->f == root_f) splay_rotate(x);
        else {
            if ((x->f->ch[0] == x) ^ (x->f->f->ch[0] == x->f)) splay_rotate(x);
            else splay_rotate(x->f);
            splay_rotate(x);
        }
    }
    root = x;
}

Splay* splay_find_kth(Splay* root, int k) {
    // cerr << "Finding " << k << "-th node" << endl; // Debug statement
    Splay* cur = root;
    while (true) {
        cur->pushdown();
        int left_sz = (cur->ch[0] ? cur->ch[0]->sz : 0);
        if (k <= left_sz) cur = cur->ch[0];
        else if (k == left_sz + 1) return cur;
        else {
            k -= left_sz + 1;
            cur = cur->ch[1];
        }
    }
}

// Output

void splay_inorder(Splay* root) {
    if (!root) return;
    root->pushdown();
    splay_inorder(root->ch[0]);
    if (root->val)
        cout << root->val << ' ';
    splay_inorder(root->ch[1]);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    Splay* root = new Splay(0);
    Splay* cur = root;
    for (int i = 1; i <= n + 1; ++i) {
        cur->ch[1] = new Splay(i % (n + 1));
        cur->ch[1]->f = cur;
        cur->pushup();
        cur = cur->ch[1];
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        Splay* L = splay_find_kth(root, l); // 1 idle node at the start
        Splay* R = splay_find_kth(root, r + 2);
        splay_splay(root, L);
        splay_splay(root->ch[1], R);
        Splay* T = root->ch[1]->ch[0];
        assert(T);
        T->rev ^= 1;
    }
    splay_inorder(root);
    return 0;
}