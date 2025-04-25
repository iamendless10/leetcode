class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        total = 0
        prev = 0
        for i in reversed(s):
            if roman[i] < prev:
                total -= roman[i]
                prev = roman[i]
            else:
                total += roman[i]
                prev = roman[i]
        return total

        