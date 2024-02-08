//  https://leetcode.com/problems/word-ladder/?envType=study-plan&id=graph-i



class Solution {
public:
    int BFS(string beginWord, string endWord, unordered_set<string>& wordSet, unordered_map<string, int>& ans) {
        queue<string>q;
        q.push(beginWord);
        ans[beginWord] = 1;
        while (!q.empty()) {
            string node = q.front();
            if (node == endWord)break;
            q.pop();
            for (int i = 0;i < node.size();i++) {
                for (char j = 'a';j <= 'z';j++) {
                    string neigh = node;
                    neigh[i] = j;
                    if (wordSet.find(neigh) != wordSet.end()
                        && ans.find(neigh) == ans.end()) {
                        q.push(neigh);
                        ans[neigh] = ans[node] + 1;
                    }
                }
            }
        }
        return ans[endWord];
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int>ans;
        unordered_set<string>wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        return BFS(beginWord, endWord, wordSet, ans);
    }
};
