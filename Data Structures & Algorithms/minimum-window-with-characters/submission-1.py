class Solution:
    def minWindow(self, s: str, t: str) -> str:
        hm_t = Counter(t)
        
        window = {}
        need = len(hm_t)
        have = 0
        l = 0
        res = [-1, -1] # start end
        minLen = float('inf')

        for r in range(len(s)):
            # insert the current char
            window[s[r]] = window.get(s[r], 0) + 1
            if s[r] in hm_t and hm_t[s[r]] == window[s[r]]:
                have += 1

            while have == need:
                # update only if we find a shorter answer
                if r - l + 1 < minLen:
                    minLen = r-l+1
                    res = [l, r+1]

                # Try to shrink the left window
                if s[l] in hm_t and window[s[l]] == hm_t[s[l]]:
                    have -= 1

                window[s[l]] -= 1
                l += 1

        return "" if minLen == float('inf') else s[res[0]: res[1]]

