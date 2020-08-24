# Our methods are:
# Count, index, insert, remove, append, pop, print, delete

class Node: #The class for a node of the linked list
    def __init__(self, data):
        self.data = data
        self.next = None
        self.previous = None

class linkedList: #The class for the linked list
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def test(self):
        self.print()
        print(self.length)

    def print(self):
        if not self.head:
            print("The linked list doesn't have any elements")
            return
        ptrToIncrement = self.head
        while ptrToIncrement:
            print(ptrToIncrement.data, end = " ")
            ptrToIncrement = ptrToIncrement.next
        print("")

    def append(self, data):
        nodeToAppend = Node(data)
        if not self.head: #Check if linked list is empty
            self.head = nodeToAppend
            self.tail = nodeToAppend
        else: #If the linked list already has elements, do the regular append
            self.tail.next = nodeToAppend
            nodeToAppend.previous = self.tail
            self.tail = nodeToAppend
        self.length += 1

    def pop(self):
        if not self.head:
            print("The linked list doesn't have any elements")
        valToReturn = self.tail.data
        if self.length == 1:
           self.head = None
           self.tail = None
        else:
            self.tail = self.tail.previous
            self.tail.next.previous = None
            self.tail.next = None
        self.length -= 1
        return valToReturn

    def count(self, data):
        counter = 0
        ptrToIncrement = self.head
        while ptrToIncrement:
            if ptrToIncrement.data == data:
                counter += 1
            ptrToIncrement = ptrToIncrement.ptr
        return counter

    def index(self, data):
        i = 0
        ptrToIncrement = self.head
        while ptrToIncrement:
            if ptrToIncrement.data == data:
                return i
            i += 1
            ptrToIncrement = ptrToIncrement.ptr
        return -1

    def insert(self, index, data):
        if index < 0:
            print("Index must be 0 or positive")
            return
        if self.length == 0:
            self.append(data)
            return
        if index == 0:
            nodeToAdd = Node(data)
            self.head.previous = nodeToAdd
            nodeToAdd.next = self.head
            self.head = nodeToAdd
            self.length += 1
            return
        elif index >= self.length:
            self.append(data)
        else:
            if index <= self.length//2: #Forward
                print("Going forward")
                i = 1
                ptrToIncrement = self.head
                while i < index:
                    ptrToIncrement = ptrToIncrement.next
                    i += 1
                ptrSecond = ptrToIncrement.next
                nodeToAdd = Node(data)
                ptrToIncrement.next = nodeToAdd
                nodeToAdd.previous = ptrToIncrement
                nodeToAdd.next = ptrSecond
                ptrSecond.previous = nodeToAdd
                self.length += 1
            else: #Backward
                print("Going backward")
                i = self.length-1
                ptrToDecrement = self.tail
                while i > index:
                    ptrToDecrement = ptrToDecrement.previous
                    i -= 1
                ptrSecond = ptrToDecrement.previous
                nodeToAdd = Node(data)
                ptrToDecrement.previous = nodeToAdd
                nodeToAdd.next = ptrToDecrement
                ptrSecond.next = nodeToAdd
                nodeToAdd.previous = ptrSecond
                self.length += 1


test1 = linkedList()
test2 = linkedList()
test2.append(-20)
test1.append(0)
test1.append(10)
test1.append(0)
test1.append(-10)
test1.append(20)
