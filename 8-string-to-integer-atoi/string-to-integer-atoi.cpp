#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        return cc(i, s, 0, false, 1);
    }

private:
    int cc(int ind, string s, int res, bool started, int sign) {
        if (ind >= s.size()) return res * sign;

        char c = s[ind];

        if (!started && c == ' ') {
            return cc(ind + 1, s, res, false, sign);
        }

        if (!started && (c == '-' || c == '+')) {
            sign = (c == '-') ? -1 : 1;
            return cc(ind + 1, s, res, true, sign);
        }

        if (isdigit(c)) {
            if (res > (INT_MAX - (c - '0')) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            res = res * 10 + (c - '0');
            return cc(ind + 1, s, res, true, sign);
        }

        return res * sign;
    }
};
