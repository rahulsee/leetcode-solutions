// https://leetcode.com/problems/design-hit-counter

class HitCounter:

    def __init__(self):
        self.de=collections.deque([])
        
    def hit(self, timestamp: int) -> None:
        self.de.append(timestamp)    

    def getHits(self, timestamp: int) -> int:
        while len(self.de)>0:
            if timestamp-self.de[0] >= 300:
                self.de.popleft()
            else:
                break
        return len(self.de)

# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)