from collections import deque
class Node:
    left: "Node | None"
    right: "Node | None"
    value: object

    def __init__(self, key):
        self.value = key
        self.left = None
        self.right = None

class BinTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        new_node = Node(value)

        if self.root is None:
            self.root = new_node
            return
        
        queue = deque([self.root])
        while queue:
            current = queue.popleft()
            if current.left is None:
                current.left = new_node
                return
            else:
                queue.append(current.left)
            
            if current.right is None:
                current.right = new_node
                return
            else:
                queue.append(current.right)


    def search(self, value) -> Node|None:
        if self.root is None:
            return None
        
        queue = deque([self.root])
        while queue:
            current = queue.popleft()
            if current.value == value:
                return current
            
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        return None