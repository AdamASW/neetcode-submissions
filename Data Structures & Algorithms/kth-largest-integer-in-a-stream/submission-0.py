import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        heap = []
        for num in nums:
            heapq.heappush(heap, num)
        self.heap = heap
        self.k = k

    def add(self, val: int) -> int:
        heapq.heappush(self.heap, val)
        while len(self.heap) > self.k:
            heapq.heappop(self.heap)
        return self.heap[0]