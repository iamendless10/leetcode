class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0 || n % 3 != 0 && n != 1) return false;

        if (n == 1) return true;

        return isPowerOfThree(n/3);
    }
};