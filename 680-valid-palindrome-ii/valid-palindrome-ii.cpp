class Solution {
private:
    int cc(string s, int left, int right){
        while(left < right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while(left < right){
            if(s[left] != s[right]){
                return cc(s,left + 1, right) || cc(s,left,right - 1);
            }
            left++;
            right--;
        }
        return true;
        
    }
};