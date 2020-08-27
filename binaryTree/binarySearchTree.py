class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def isLeaf(self):
        if not self.left and not self.right:
            return 1
        else:
            return 0

def inOrder(node, level = 0):
    if node:
        inOrder(node.left, level+1)
        print(node.data, end = " ")
        inOrder(node.right, level+1)
    if level == 0:
        print("")

def insert(node, data):
    if not node:
        node = Node(data)
    else:
        if data < node.data:
            if node.left:
                insert(node.left, data)
            else:
                node.left = Node(data)
        elif data > node.data:
            if node.right:
                insert(node.right, data)
            else:
                node.right = Node(data)



tree = Node(40)
insert(tree, 10)
insert(tree, 20)
insert(tree, 50)
insert(tree, 60)
insert(tree, 35)
inOrder(tree)

