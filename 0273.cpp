class Solution {
public:
    string one2nine(int num) {
        switch(num) {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
        }
        return "";
    }
    string ten2twenty(int num) {
        switch(num) {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";
        }
        return "";
    }
    string tens(int num) {
        switch(num) {
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";
        }
        return "";
    }
    string twoDigits(int num) {
        if (num == 0) return "";
        else if (num < 10) return one2nine(num);
        else if (num < 20) return ten2twenty(num);
        else {
            int a = num / 10;
            int b = num % 10;
            if (b == 0) return tens(a);
            else return tens(a) + ' ' + one2nine(b);
        }
    }
    string threeDigits(int num) {
        int a = num / 100;
        int b = num % 100;
        if (a != 0 && b != 0) return one2nine(a) + " Hundred " + twoDigits(b);
        else if (a == 0) return twoDigits(b);
        else if (b == 0) return one2nine(a) + " Hundred";
        else return "";
    }
    
    string numberToWords(int num) {
        // at most 10 digits
        if (num == 0) return "Zero";
        
        int billion = num / 1000000000;
        int million = (num - billion * 1000000000) / 1000000;
        int thousand = (num - billion * 1000000000 - million * 1000000) / 1000;
        int rest = num - billion * 1000000000 - million * 1000000 - thousand * 1000;
        string res = "";
        if (billion != 0) res += threeDigits(billion) + " Billion";
        if (million != 0) {
            if (res.length() != 0) res += " ";
            res += threeDigits(million) + " Million";
        }
        if (thousand != 0) {
            if (res.length() != 0) res += " ";
            res += threeDigits(thousand) + " Thousand";
        }
        if (rest != 0) {
            if (res.length() != 0) res += " ";
            res += threeDigits(rest);
        }
        return res;
    }
};