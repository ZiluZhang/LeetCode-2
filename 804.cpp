class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> morse;
        for (string word: words) {
            string m = "";
            for (char c: word) {
                m += dict[c-'a'];
            }
            morse.insert(m);
        }
        return morse.size();
    }
};