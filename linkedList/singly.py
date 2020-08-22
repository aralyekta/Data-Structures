# Our methods are:
# Count, index, insert, remove, append, pop, print

class Node:
    def __init__(self, data):
        self.data = data
        self.ptr = None

class linkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def append(self, data):
        nodeToAppend = Node(data)
        if not self.head:
            self.head = nodeToAppend
            self.tail = nodeToAppend
        else:
            self.tail.ptr = nodeToAppend
            self.tail = nodeToAppend
        self.length += 1
    
    def print(self):
        ptrToIncrement = self.head
        if not ptrToIncrement:
            print("Linked list doesn't have any elements")
            return
        while ptrToIncrement:
            print(ptrToIncrement.data, end =" ")
            ptrToIncrement = ptrToIncrement.ptr
        print("")

    def pop(self):
        if not self.head:
            print("Linked list doesn't have any elements")
            return None
        if self.head is self.tail:
            valToReturn = self.head.data
            self.head = None
            self.tail = None
            return valToReturn
        ptrToIncrement = self.head
        valToReturn = self.tail.data
        while (ptrToIncrement.ptr is not self.tail):
            ptrToIncrement = ptrToIncrement.ptr
        self.tail = ptrToIncrement
        ptrToIncrement.ptr = None
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
        if index < 0: # Checks if index is valid
            print("Index must be 0 or positive.")
            return
        if not self.head: # Checks if the linked list is empty
            self.append(data)
            return
        if index == 0: # Case1: Insert at head
            nodeToAdd = Node(data)
            nodeToAdd.ptr = self.head
            self.head = nodeToAdd
            self.length += 1
        elif index < self.length: # Case2: Insert in the middle
            if self.head == self.tail: #Checks if the linked list has 1 element, if that is the case, append the element.
                self.append(data)
            else: # If the linked list is larger than one element, perform the insertion
                i = 1
                ptrToIncrement = self.head
                while i < index:
                    ptrToIncrement = ptrToIncrement.ptr
                    i += 1
                ptrSecond = ptrToIncrement.ptr
                nodeToAdd = Node(data)
                ptrToIncrement.ptr = nodeToAdd
                nodeToAdd.ptr = ptrSecond
                self.length += 1
        else: # If the index is bigger than the current length, append
            self.append(data)

test = linkedList()
for i in range(5):
    test.append(i)
