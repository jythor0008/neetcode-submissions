class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        len_s2 = len(s2)
        len_s1 = len(s1)
        if len_s1 > len_s2: 
            return False

        counter_s1 = Counter(s1)
        counter_s2 = Counter(s2[: len_s1])
        if counter_s1 == counter_s2:
            return True

        l = 0
        for i in range(len_s1, len_s2):
            counter_s2[s2[l]] -= 1
            counter_s2[s2[i]] += 1
            l += 1
            if counter_s2 == counter_s1:
                return True

        return False
        
