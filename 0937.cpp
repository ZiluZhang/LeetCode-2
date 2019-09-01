// 运算符重载，要用static函数
// static里面调用的函数也要是static的
// stable_sort保序
class Solution {
public:
    static bool isDigit(string a) {
        for (char c: a) {
            if ((!isdigit(c)) && c != ' ') return false;
        }
        return true;
    }
    
    static bool mycompare(string a, string b) {
        string a1 = a.substr(0, a.find(" "));
        string a2 = a.substr(a.find(" ")+1);
        string b1 = b.substr(0, b.find(" "));
        string b2 = b.substr(b.find(" ")+1);
        cout << a1 << ',' << a2 << ',' << b1 << ',' << b2 << endl;
        bool adigit = isDigit(a2);
        bool bdigit = isDigit(b2);
        if (!adigit && !bdigit) {
            if (a2 == b2) return a1 < b1;
            return a2 < b2;
        } else if (!adigit) {
            return true;
        } else {
            return false;
        }
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), mycompare);
        return logs;
    }
};