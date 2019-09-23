class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char c: tasks) cnt[c-'A']++;
        sort(cnt.begin(), cnt.end());
        int max_val = cnt[25]-1, idle_slots = max_val * n;
        for (int i = 24; i >= 0 && cnt[i] > 0; i--) {
            idle_slots -= min(max_val, cnt[i]);
        }
        return max(idle_slots + tasks.size(), tasks.size());
    }
};