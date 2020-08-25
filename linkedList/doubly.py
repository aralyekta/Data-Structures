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

    def test(self): #Print both the linked list and its length for testing
        self.print()
        print(self.length)

    def print(self):
        if not self.head:
            print("The linked list doesn't have any elements")
            return
        ptrToIncrement = self.head
        while ptrToIncrement: #Print all nodes one by one
            print(ptrToIncrement.data, end = " ")
            ptrToIncrement = ptrToIncrement.next
        print("")

    def append(self, data):
        nodeToAppend = Node(data)
        if not self.head: #Check if linked list is empty. If it is, make an exception
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
        if self.length == 1: #Simply reduce its node's reference count to 0
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
        while ptrToIncrement: #Check all elements one by one
            if ptrToIncrement.data == data:
                counter += 1
            ptrToIncrement = ptrToIncrement.ptr
        return counter

    def index(self, data):
        i = 0
        ptrToIncrement = self.head
        while ptrToIncrement: #Check all elements one by one
            if ptrToIncrement.data == data:
                return i
            i += 1
            ptrToIncrement = ptrToIncrement.ptr
        return -1

    def insert(self, index, data):
        if index < 0: #Check for erroneous input
            print("Index must be 0 or positive")
            return
        elif self.length == 0: #If the linked list doesn't have any elements, simply append
            self.append(data)
            return
        elif index == 0: #Check if the insertion index is zero, that is, the beginning of the linked list
            nodeToAdd = Node(data)
            self.head.previous = nodeToAdd
            nodeToAdd.next = self.head
            self.head = nodeToAdd
            self.length += 1
            return
        elif index >= self.length: #Check for erroneous input
            self.append(data)
        else: #Insertion in the middle of the linked list. Note that we will be using an optimization to decide whether to go forward from the begginning or to go backward from the ending
            if index <= self.length//2: #The insertion index is in the first half, going forward from the beginning
                i = 1
                ptrToIncrement = self.head
                while i < index: #Move forward until reaching the index
                    ptrToIncrement = ptrToIncrement.next
                    i += 1
                ptrSecond = ptrToIncrement.next
                nodeToAdd = Node(data)
                ptrToIncrement.next = nodeToAdd
                nodeToAdd.previous = ptrToIncrement
                nodeToAdd.next = ptrSecond
                ptrSecond.previous = nodeToAdd
                self.length += 1
            else: #The insertion index is in the second half, going backward from the ending
                i = self.length-1
                ptrToDecrement = self.tail
                while i > index: #Move backward until reaching the index
                    ptrToDecrement = ptrToDecrement.previous
                    i -= 1
                ptrSecond = ptrToDecrement.previous
                nodeToAdd = Node(data)
                ptrToDecrement.previous = nodeToAdd
                nodeToAdd.next = ptrToDecrement
                ptrSecond.next = nodeToAdd
                nodeToAdd.previous = ptrSecond
                self.length += 1

    def remove(self, data):
        if self.length == 0: #Check if the linked list is valid for removal
            print("The linked list doesn't have any elements")
            return
        elif self.length == 1: #Check if the linked list has only 1 node
            if self.head.data == data:
                self.pop()
                return
            else:
                print("The value doesn't exist in the linked list")
                return
        else: #The case when the linked list has multiple nodes
            ptrToIncrement = self.head
            while ptrToIncrement and ptrToIncrement.data != data:
                ptrToIncrement = ptrToIncrement.next
            if not ptrToIncrement: #Case 1: The data doesn't exist in the linked list
                print("The value doesn't exist in the linked list")
            elif ptrToIncrement is self.head: #Case 2: The data is at the beginning of the linked list
                self.head = ptrToIncrement.next
                ptrToIncrement.next = None
                self.head.previous = None
                self.length -= 1
            elif ptrToIncrement is self.tail: #Case 3: The data is at the end of the linked list
                self.tail = ptrToIncrement.previous
                self.tail.next = None
                ptrToIncrement.previous = None
                self.length -= 1
            else: #Case 4: The data is in the middle of the linked list. Since we don't know its index, we should do a linear search
                ptr1 = ptrToIncrement.previous
                ptr2 = ptrToIncrement.next
                ptrToIncrement.next = None
                ptrToIncrement.previous = None
                ptr1.next = ptr2
                ptr2.previous = ptr1
                self.length -= 1
            return

    def delete(self, index):
        if index < 0: #Check for erroneous input
            print("Index should be 0 or positive")
        elif index == 0: #Case1: the removal index is 0, the beginning of the linked list
            self.remove(0)
        elif index >= self.length: #Check for erroneous input
            print("Index is out of bounds")
        elif index == self.length-1: #Case2: The removal index points to the last node of the linked list
            self.pop()
        else: #Case3: The removal index is in the middle of the linked list. Note that we will do an optimization to decide whether we will go forward from the beginning, or go backward from the end.
            if index < self.length//2: #The index is in the first half, we will go forward from the beginning 
                i = 0
                ptrToIncrement = self.head
                while i < index: #Move linearly since we don't have access to middle nodes
                    ptrToIncrement = ptrToIncrement.next
                    i += 1
                ptr1 = ptrToIncrement.previous
                ptr2 = ptrToIncrement.next
                ptrToIncrement.previous = None
                ptrToIncrement.next = None
                ptr1.next = ptr2
                ptr2.previous = ptr1
                self.length -= 1
            else: #The index is in the second half, we will go backward from the end.
                i = self.length-1
                ptrToDecrement = self.tail
                while i > index: #Move linearly since we don't have access to middle nodes
                    ptrToDecrement = ptrToDecrement.previous
                    i -= 1
                ptr1 = ptrToDecrement.previous
                ptr2 = ptrToDecrement.next
                ptrToDecrement.next = None
                ptrToDecrement.previous = None
                ptr1.next = ptr2
                ptr2.previous = ptr1
                self.length -= 1
