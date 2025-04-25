class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        minlen = min(len(s) for s in strs)

        ref = strs[0]

        for i in range(minlen):
            char = ref[i]

            for s in strs:
                if char != s[i]:
                    return ref[:i]
        return ref[:minlen]

        