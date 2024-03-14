class Node:
    def __init__(self, value=0, nextNode=None, prevNode=None):
        self.val = value
        self.nextNode = nextNode
        self.prevNode = prevNode

class MyCircularDeque:

    def __init__(self, k: int):
        self.head = None
        self.currSize = 0
        self.k = k
        self.front = None
        self.rear = None

    def insertFront(self, value: int) -> bool:
        if self.currSize == self.k:
            return False
        
        newNode = Node(value)
        if not self.front and not self.rear:
            self.front = newNode
            self.rear = newNode
        else:  
            newNode.nextNode = self.front
            self.front.prevNode = newNode
            self.front = newNode
            
        self.currSize += 1
        return True
        
    def insertLast(self, value: int) -> bool:
        if self.currSize == self.k:
            return False
        
        newNode = Node(value)
        if not self.front and not self.rear:
            self.front = newNode
            self.rear = newNode
        else:
            self.rear.nextNode = newNode
            newNode.prevNode = self.rear
            self.rear = newNode
            
        self.currSize += 1
        return True

    def deleteFront(self) -> bool:
        if self.currSize == 0:
            return False
        
        if self.front == self.rear:
            self.front = None
            self.rear = None
            self.currSize = 0
            return True
        
        nextNodeInList = self.front.nextNode
        self.front.nextNode = None
        nextNodeInList.prevNode = None
        self.front = nextNodeInList
        self.currSize -= 1
        
        return True
        
        
    def deleteLast(self) -> bool:
        if self.currSize == 0:
            return False
        
        if self.front == self.rear:
            self.front = None
            self.rear = None
            self.currSize = 0
            return True
        
        prevNodeInList = self.rear.prevNode
        self.rear.prevNode = None
        prevNodeInList.nextNode = None
        self.rear = prevNodeInList
        self.currSize -= 1
        
        return True
    
    def getFront(self) -> int:
        if self.currSize == 0:
            return -1
        
        return self.front.val

    def getRear(self) -> int:
        if self.currSize == 0:
            return -1
        
        return self.rear.val

    def isEmpty(self) -> bool:
        return self.currSize == 0

    def isFull(self) -> bool:
        return self.currSize == self.k


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()