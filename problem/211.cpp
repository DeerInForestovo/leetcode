#include <bits/stdc++.h>
using namespace std;

/*
To Copilot:
- Use ++variable instead of variable++ for any variable if possible.
- Omit {} if the body of a loop or conditional is a single statement.
*/

class WordDictionary {
public:
    vector<unordered_map<char, int>> ch;
    vector<bool> end;
    int rt, cnt;

    int new_node() {
        ch.push_back(unordered_map<char, int>());
        end.push_back(false);
        return ++cnt;
    }
    
    void addWord(string word) {
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
    
    WordDictionary() {
        cnt = -1;
        rt = new_node();
    }
    
    bool search(string word) {
        return _search(rt, 0, word.length(), word);
    }

    bool _search(int nod, int pos, int sz, const string &word) {
        if (pos == sz) return end[nod];
        if (word[pos] == '.') {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (ch[nod][c])
                    if (_search(ch[nod][c], pos + 1, sz, word))
                        return true;
            }
            return false;
        } else if (ch[nod][word[pos]]) {
            return _search(ch[nod][word[pos]], pos + 1, sz, word);
        } else {
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here

    return 0;
}
#endif