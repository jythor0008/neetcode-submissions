class Twitter:

    def __init__(self):
        self.following = defaultdict(set)
        self.posts = defaultdict(list)
        self.postId = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.posts[userId].append((self.postId, tweetId))
        self.postId += 1

    def getNewsFeed(self, userId: int) -> List[int]:
        self.following[userId].add(userId)

        maxheap = []

        # Put the newest tweet from every followed user into the heap
        for user in self.following[userId]:
            if self.posts[user]:
                index = len(self.posts[user]) - 1
                priority, tweetId = self.posts[user][index]

                heapq.heappush(
                    maxheap,
                    (-priority, tweetId, user, index)
                )

        result = []

        while maxheap and len(result) < 10:
            priority, tweetId, user, index = heapq.heappop(maxheap)

            result.append(tweetId)

            # Move to the next newest tweet from this user
            if index > 0:
                next_priority, next_tweetId = self.posts[user][index - 1]

                heapq.heappush(
                    maxheap,
                    (-next_priority, next_tweetId, user, index - 1)
                )

        return result        


    def follow(self, followerId: int, followeeId: int) -> None:
        self.following[followerId].add(followeeId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.following[followerId]:
            self.following[followerId].remove(followeeId)
        
