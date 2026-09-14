class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hm = defaultdict(list)
        for s in strs:
            key = "".join(sorted(s))
            hm[key].append(s)

        res = []
        for item in hm.values():
            res.append(item)

        return res