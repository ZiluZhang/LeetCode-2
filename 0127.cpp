class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> words;
        for (int i = 0; i < wordList.size(); i++) {
            words.insert(wordList[i]);
        }
        q.push(beginWord);
        int cnt = 0;
        while (!q.empty()) {
            cnt++;
            for (int k = q.size(); k > 0; k--) {
                string cur = q.front();
                q.pop();
                for (int i = 0; i < cur.size(); i++) {
                    string newWord = cur;
                    for (char a = 'a'; a <= 'z'; a++) {
                        newWord[i] = a;
                        if (words.find(newWord) != words.end()) {
                            if (newWord == endWord) return cnt+1;
                            q.push(newWord);
                            words.erase(newWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};