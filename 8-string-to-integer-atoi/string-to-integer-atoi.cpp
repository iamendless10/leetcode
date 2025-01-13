class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        return cc(index, s, 0, 1, false);
    }

    
private:
    int cc(int ind, const string& s, long res, int sign, bool started){
        if (ind >= s.size()) return static_cast<int>(res * sign);

        char c = s[ind];

        
        if (!started && isspace(c)) {
            return cc(ind + 1, s, res, sign, started);
        }


        if (!started && (c == '-' || c == '+')) {
            sign = (c == '-') ? -1 : 1;
            return cc(ind + 1, s, res, sign, true);
        }
        
        if (isdigit(c)) {
            res = res * 10 + (c - '0');
           
            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
            return cc(ind + 1, s, res, sign, true);
        }

        return static_cast<int>(res * sign);

    }
};