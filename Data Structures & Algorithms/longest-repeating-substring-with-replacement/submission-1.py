class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        res = 0
        hm = {}
        maj = 0
        for r, c in enumerate(s):
            hm[c] = hm.get(c, 0) + 1
            maj = max(maj, hm[c])
            while r - l + 1 - maj > k:
                hm[s[l]] -= 1
                l += 1

            res = max(res, r - l + 1)
        return res

