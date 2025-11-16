from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

    def add_child(self, child_node):
        self.children.append(child_node)

class GenTree:
    def __init__(self):
        self.root = None

    def insert(self, parent_data, new_data) -> bool:
        new_node = Node(new_data)

        if not self.root:
            self.root = new_node
            return True
        
        queue = deque([self.root])
        while queue:
            node = queue.popleft()
            if node.data == parent_data:
                node.add_child(new_node)
                return True
            for child in node.children:
                queue.append(child)
        return False
    
    def search(self, target) -> Node|None:
        if not self.root:
            return None
        
        queue = deque([self.root])
        while queue:
            node = queue.popleft()
            if node.data == target:
                return node
            else:
                for child in node.children:
                    queue.append(child)
        return None
    
    def delete(self, target) -> bool:
        if not self.root:
            return False
        
        # Only Root
        if self.root.data == target:
            if not self.root.children:
                self.root = None
            else:
                new_root = self.root.children[0]
                new_root.children.extend(self.root.children[1:])
                self.root = new_root
            return True
        
        # Not Only Root
        queue = deque([self.root])
        while queue:
            node = queue.popleft()
            for child in node.children:
                if child.data == target:
                    node.children.remove(child)
                    node.children.extend(child.children)
                    return True
                else:
                    queue.append(child)
        return False
    
    def traverse_breadth_first(self) -> list:
        if not self.root:
            return []
        
        result = []
        queue = deque([self.root])
        while queue:
            node = queue.popleft()
            result.append(node.data)
            for child in node.children:
                queue.append(child)
        return result
