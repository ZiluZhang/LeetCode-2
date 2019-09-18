class Solution {
public:
    
    void printVector(vector<string>& v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        
        unordered_set<string> curWords;
        vector<string> path = {beginWord};
        queue<vector<string>> q;
        q.push(path);
        
        while (!q.empty() && res.size() == 0) {
            for (int k = q.size(); k > 0; k--) {
                path = q.front();
                // printVector(path);
                q.pop();
                string prev = path.back();
                for (int i = 0; i < prev.size(); i++) {
                    string newWord = prev;
                    for (char a = 'a'; a <= 'z'; a++) {
                        newWord[i] = a;
                        if (dict.count(newWord)) {
                            // cout << newWord << endl;
                            path.push_back(newWord);
                            curWords.insert(newWord);
                            q.push(path);
                            if (newWord == endWord) {
                                res.push_back(path);
                            }
                            path.pop_back();
                        }
                    }
                }
            }
            for (string w: curWords) {
                dict.erase(w);
            }
            curWords.clear();
        }
        return res;
    }
};