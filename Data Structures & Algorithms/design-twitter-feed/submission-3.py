class Twitter:

    def __init__(self):
        self.following = defaultdict(set)
        self.posts = defaultdict(list)
        self.postId = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.posts[userId].append((self.postId, tweetId))
        self.postId += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        minheap = []
        self.following[userId].add(userId)
        # Loop through every following and their posts, insert into a minheap of size 10
        for user in self.following[userId]:
            for prio, post in self.posts[user]:
                heapq.heappush(minheap, (prio, post))
                if len(minheap) > 10:
                    heapq.heappop(minheap)
        
        res = sorted(minheap, reverse=True)
        return [post for _, post in res]
        


    def follow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].add(followeeId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.following[followerId]:
            self.following[followerId].remove(followeeId)
        
