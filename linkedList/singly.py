# Our methods are:
# Count, index, insert, remove, append, pop, print, delete

class Node: #The class for a node of the linked list
    def __init__(self, data):
        self.data = data
        self.ptr = None

class linkedList: #The class for the linked list
    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def append(self, data):
        nodeToAppend = Node(data)
        if not self.head: #Check if linked list is empty
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
        if self.head is self.tail: #Check if the linked list has only one node
            valToReturn = self.head.data
            self.head = None
            self.tail = None
            return valToReturn
        #If not, do the regular pop operation
        ptrToIncrement = self.head
        valToReturn = self.tail.data
        while (ptrToIncrement.ptr is not self.tail): #Find the (n-1)th node
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
            if self.head == self.tail: #Checks if the linked list has only 1 node, if that is the case, append the node.
                self.append(data)
            else: # If the linked list is larger than one node, perform the regular insertion
                i = 1
                ptrToIncrement = self.head
                while i < index: #Find the (index-1)th node
                    ptrToIncrement = ptrToIncrement.ptr
                    i += 1
                ptrSecond = ptrToIncrement.ptr
                nodeToAdd = Node(data)
                ptrToIncrement.ptr = nodeToAdd
                nodeToAdd.ptr = ptrSecond
                self.length += 1
        else: # If the index is bigger than the current length, append
            self.append(data)
    
    def remove(self, data):
        if self.length == 0: #Case1: No nodes
            print("Linked list doesn't have any elements")
            return
        if self.length == 1: #Case2: 1 node
            if data == self.head.data:
                self.pop()
                return
            else:
                print("The element doesn't exist in the linked list")
                return
        else: #Case3: More than 1 node
            ptrToIncrement = self.head
            if ptrToIncrement.data == data: #Check if the node to be removed is at the 0th index
                self.head = self.head.ptr
                self.length -= 1
                return
            while ptrToIncrement.ptr and ptrToIncrement.ptr.data != data: #Find the node which comes before the node to be removed
                ptrToIncrement = ptrToIncrement.ptr
            if ptrToIncrement is self.tail: #If this is the case, the loop above ended without matching any values
                print("The element doesn't exist in the linked list")
                return
            elif ptrToIncrement.ptr is self.tail: #If this is the case, the node to be removed is at the end
                self.pop()
                return
            else: #All other cases
                ptrToIncrement.ptr = ptrToIncrement.ptr.ptr
                self.length -= 1
                return
    
    def delete(self, index):
        if index < 0: #Check for erroneous input
            print("Index should be 0 or positive")
            return
        elif index == 0: #Delete the first node
            self.head = self.head.ptr
            self.length -= 1
            return
        elif index == self.length-1: #Delete the last node
            self.pop()
            return
        elif index >= self.length: #Check for erroneous input
            print("Index is out of bounds")
            return
        else: #Delete a node in the middle
            counter = 1
            ptrToIncrement = self.head
            while counter < index:
                ptrToIncrement = ptrToIncrement.ptr
                counter += 1
            ptrToIncrement.ptr = ptrToIncrement.ptr.ptr
            self.length -= 1
