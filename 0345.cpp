class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (i < j) {
            while (i < s.size() && !v.count(s[i])) i++;
            while (j >= 0 && !v.count(s[j])) j--;
            if (i >= j || i >= s.size() || j < 0) return s;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};