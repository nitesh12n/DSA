class MyCircularQueue:

    def __init__(self, k: int):
        self.queue = []
        self.k = k
        self.currSize = 0

    def enQueue(self, value: int) -> bool:
        if self.currSize < self.k:
            self.queue.append(value)
            self.currSize += 1
            return True
        
        return False

    def deQueue(self) -> bool:
        if self.currSize > 0:
            self.queue.pop(0)
            self.currSize -= 1
            return True
        
        return False

    def Front(self) -> int:
        if self.currSize > 0:
            return self.queue[0]
        
        return -1

    def Rear(self) -> int:
        if self.currSize > 0:
            return self.queue[self.currSize - 1]
        
        return -1
        
    def isEmpty(self) -> bool:
        return self.currSize == 0
        
    def isFull(self) -> bool:
        return self.currSize == self.k


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()