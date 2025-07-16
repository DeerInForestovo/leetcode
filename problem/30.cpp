#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    int end = -1;
    int insert(const string& word, int index) {
        TrieNode* node = this;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        if (node->end == -1) node->end = index;
        return node->end;
    }
    int search(const string& word, int start, int length) {
        TrieNode* node = this;
        for (int i = start; i < start + length; ++i) {
            if (node->children.find(word[i]) == node->children.end()) {
                return -1;
            }
            node = node->children[word[i]];
        }
        return node->end;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_length = s.length(), words_count = words.size(), word_length = words[0].length();

        TrieNode root;
        vector<int> appearance(words_count, 0);
        int diff_word_count = 0;
        for (int i = 0; i < words_count; ++i) {
            int index = root.insert(words[i], i);
            ++appearance[index];
            if (index == i) ++diff_word_count;
        }
        
        vector<int> result;
        for (int i = 0; i < word_length; ++i) {
            vector<int> cur_appearance(words_count, 0);
            int cur_diff_word_count = 0;
            vector<int> indices(s_length / word_length + 1, -1);
            for (int j = i, l = -1, r = -1; j <= s_length - word_length; j += word_length) {
                int index = root.search(s, j, word_length);
                indices[++r] = index;
                while (l < r && (index == -1 || cur_appearance[index] >= appearance[index])) {
                    if (indices[++l] != -1) { // Always true
                        if (cur_appearance[indices[l]] == appearance[indices[l]]) --cur_diff_word_count;
                        --cur_appearance[indices[l]];
                    }
                }
                if (index != -1)
                    if (++cur_appearance[index] == appearance[index])
                        if (++cur_diff_word_count == diff_word_count)
                            result.push_back(j - (words_count - 1) * word_length);
            }
        }
        return result;
    }
};

#ifdef LEETCODE_LOCAL
int main() {
    Solution sol;
    // Add test cases here
    vector<string> words1 = {"foo", "bar"};
    vector<int> result1 = sol.findSubstring("barfoothefoobarman", words1);
    for (int index : result1) {
        cout << index << " ";
    }
    cout << endl;
    vector<string> words2 = {"word", "good", "best", "good"};
    vector<int> result2 = sol.findSubstring("wordgoodgoodgoodbestword", words2);
    for (int index : result2) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}
#endif