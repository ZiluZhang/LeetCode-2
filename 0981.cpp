class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<string>> v;
    unordered_map<string, vector<int>> t;    
    TimeMap() {
        // v.clear();
        // t.clear();
    }
    
    void set(string key, string value, int timestamp) {
        v[key].push_back(value);
        t[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if (!v.count(key)) return "";
        // auto vs = v[key];
        // auto ts = t[key];
        if (t[key].size() == 0) return "";
        if (timestamp < t[key][0]) return "";
        int left = 0, right = t[key].size()-1;
        int idx = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (t[key][mid] <= timestamp) {
                idx = max(idx, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return v[key][idx];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */