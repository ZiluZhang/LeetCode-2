// str.erase()
// std::remove()
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string email: emails) {
            int idx = email.find_first_of('@');
            string localName = email.substr(0, idx);
            string domainName = email.substr(idx);
            localName.erase(remove(localName.begin(), localName.end(), '.'), localName.end());
            int idx2 = localName.find_first_of('+');
            localName = localName.substr(0, idx2);
            // cout << localName << endl;
            s.insert(localName + domainName);
        }
        return s.size();
    }
};