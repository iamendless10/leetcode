class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        mpp = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        res = []
        def backtrack(ind, path):
            if ind == len(digits):
                res.append("".join(path))
                return
            curr_digit = digits[ind]
            for letter in mpp[curr_digit]:
                path.append(letter)
                backtrack(ind + 1, path)
                path.pop()
        backtrack(0, [])
        return res
        