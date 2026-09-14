class Solution:

    def encode(self, strs: List[str]) -> str:
        res = []
        for s in strs:
            res.append(str(len(s)))
            res.append("#")
            res.append(s)
        return "".join(res)

    def decode(self, s: str) -> List[str]:
        i = 0
        res = []
        while i < len(s):
            j = i
            while j < len(s) and s[j] != '#':
                j += 1

            # j = "#" at this moment
            length = int(s[i:j])
            
            i = j+1 # skip the "#", pointing to first char
            j = i + length 
            res.append(s[i:j])
            i = j
        return res

            

