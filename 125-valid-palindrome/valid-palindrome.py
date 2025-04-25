class Solution:
    def isPalindrome(self, s: str) -> bool:
        cleaned = ''.join(c.lower() for c in s if c.isalnum())
        return cleaned == cleaned[::-1]
        