class Solution:
    def addBinary(self, a: str, b: str) -> str:
        sumi = (int(a,2) + int(b,2))
        return bin(sumi)[2:]
        