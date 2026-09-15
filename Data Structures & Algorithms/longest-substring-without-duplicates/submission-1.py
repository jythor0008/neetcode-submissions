class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        set_ = set()
        res = 0
        for i, c in enumerate(s):
            while c in set_:
                set_.remove(s[l])
                l += 1

            set_.add(c)
            res = max(res, i-l+1)
        return res