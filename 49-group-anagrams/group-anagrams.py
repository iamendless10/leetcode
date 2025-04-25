class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        from collections import defaultdict

        anagrams = defaultdict(list)

        for word in strs:
            key = tuple(sorted(word))
            anagrams[key].append(word)

        return list(anagrams.values())
        