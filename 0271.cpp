class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto s : strs) {
            res += to_string(s.size()) + "/" + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            auto idx = s.find("/", i);
            int len = stoi(s.substr(i, idx-i));
            res.push_back(s.substr(idx+1, len));
            i = idx + len + 1;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));