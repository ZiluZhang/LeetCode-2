class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> ops;
        for (int i = 0; i < indexes.size(); i++) {
            ops.push_back({indexes[i], i});
        }
        sort(ops.rbegin(), ops.rend());
        for (auto op : ops) {
            int i = op.first;
            string source = sources[op.second];
            string target = targets[op.second];
            if (S.substr(i, source.size()) == source) {
                S = S.substr(0, i) + target + S.substr(i + source.size());
            }
        }
        return S;
    }
};