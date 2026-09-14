class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # bucket sort, assign them to buckets of frequencies
        n = len(nums)
        bucket = [[] for i in range(n+1)]

        count = Counter(nums)

        for key, val in count.items():
            bucket[val].append(key)

        # iterate through the bucket from back, return top k
        res = [num for b in reversed(bucket) for num in b]
        return res[:k]


        

