// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder:

    def __init__(self):
        self.p1=[]
        self.p2=[]
    def addNum(self, num: int) -> None:
        print(num)
        if len(self.p1)==0 or num < -self.p1[0]:
            if len(self.p1) > len(self.p2):
                x=-heapq.heappop(self.p1)
                heapq.heappush(self.p2, x)
            heapq.heappush(self.p1,-num)
        elif len(self.p2)==0 or num > self.p2[0]:
            if len(self.p2) >= len(self.p1):
                x=heapq.heappop(self.p2)
                heapq.heappush(self.p1, -x)
            heapq.heappush(self.p2, num)
        else:
            if len(self.p1)<=len(self.p2):
                heapq.heappush(self.p1, -num)
            else:
                heapq.heappush(self.p2, num)
                

    def findMedian(self) -> float:
        if len(self.p1)==len(self.p2):
            return (-self.p1[0]+self.p2[0])/2
        else:
            return -self.p1[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()