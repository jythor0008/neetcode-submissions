class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hm = {}
        for s in strs:
            key = "".join(sorted(s))
            if key in hm.keys():
                hm[key].append(s)
            else:
                hm[key] = [s]

        res = []
        for ls in hm.values():
            res.append(ls)

        return res