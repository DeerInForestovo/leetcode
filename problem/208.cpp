#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class Trie {
public:
    vector<unordered_map<char, int>> ch;
    vector<bool> end;
    int rt, cnt;

    Trie() {
        cnt = -1;
        rt = new_node();
    }

    int new_node() {
        ch.push_back(unordered_map<char, int>());
        end.push_back(false);
        return ++cnt;
    }
    
    void insert(string word) {
        int nod = rt, sz = word.length();
        for (int i = 0; i < sz; ++i) {
            char c = word[i];
            if (ch[nod][c] == 0) {
                ch[nod][c] = new_node();
            }
            nod = ch[nod][c];
        }
        end[nod] = true;
    }
    
    bool search(string word) {
        int nod = rt, sz = word.length();
        for (int i = 0; i < sz; ++i) {
            char c = word[i];
            if (ch[nod][c] == 0) {
                return false;
            }
            nod = ch[nod][c];
        }
        return end[nod];
    }
    
    bool startsWith(string prefix) {
        int nod = rt, sz = prefix.length();
        for (int i = 0; i < sz; ++i) {
            char c = prefix[i];
            if (ch[nod][c] == 0) {
                return false;
            }
            nod = ch[nod][c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif