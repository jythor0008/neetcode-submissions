class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s)) + "#" + s
        return res

    def decode(self, s: str) -> List[str]:
        i = 0
        res = []
        while i < len(s):
            size = ""
            while i < len(s) and s[i] != '#':
                size += s[i]
                i+=1 
            
            size_int = int(size)
            i += 1 # skip the "#"

            res.append(s[i:i+size_int])
            i += size_int
        return res

            

