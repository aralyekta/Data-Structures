from singly import linkedList
from singly import Node

# We will be using singly linked lists for stack, all of the methods can be found in the linked list folder */

# All of the methods included in the singly.py file can be used here
# append, pop, count, index, contains, clear, peekfirst, peeklast, remove, insert, delete, print

class stack(linkedList):
    def push(self, data):
        self.append(data)

    def peek(self):
        return self.peekLast()
