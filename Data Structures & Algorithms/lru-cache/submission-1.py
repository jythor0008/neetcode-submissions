class LRUCache:
    class Node:
        def __init__(self, key=0, val=0, nxt=None, prv=None):
            self.key = key
            self.val = val
            self.next = nxt
            self.prev = prv

    def __init__(self, capacity: int):
        self.cap = capacity
        self.least = self.Node()
        self.most = self.Node()
        self.map = {}

        self.least.next = self.most
        self.most.prev = self.least

    def insert(self, key):
        node = self.map[key]
        
        node.next, node.prev = self.most, self.most.prev
        self.most.prev.next = node
        self.most.prev = node
        
    def remove(self, key):
        node = self.map[key]

        node.prev.next = node.next
        node.next.prev = node.prev

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1

        self.remove(key) # Remove from the list
        self.insert(key) # Add back into most freq used
        return self.map[key].val

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            # update the value
            self.map[key].val = value
            self.remove(key)
            self.insert(key)
        
        else:
            # remove least if max cap
            if len(self.map) == self.cap:
                removing = self.least.next.key
                self.remove(removing)
                self.map.pop(removing)
            
            self.map[key] = self.Node(key, value)
            self.insert(key)

        
