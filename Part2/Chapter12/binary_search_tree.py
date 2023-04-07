class Node:
    def __init__(self, value):
        self.value = value
        self.left: 'Node' = None
        self.right: 'Node' = None

class BinarySearchTree:
    def __init__(self) -> None:
        self.root: Node = None

    def preorder_traversal(self, node: Node) -> None:
        if node == None:
            return
            
        print(node.value)
        self.preorder_traversal(node.left)
        self.preorder_traversal(node.right)

    def inorder_traversal(self, node: Node) -> None:
        if node == None:
            return

        self.inorder_traversal(node.left)
        print(node.value)
        self.inorder_traversal(node.right)

    def postorder_traversal(self, node: Node) -> None:
        if node == None:
            return
            
        self.postorder_traversal(node.left)
        self.postorder_traversal(node.right)
        print(node.value)
        
    def insert(self, value: int) -> None:
        if not self.root:
            self.root = Node(value)
            return

        prev = None
        current = self.root
        while current != None:
            prev = current
            if current.value < value:
                current = current.right
            else:
                current = current.left

        if prev.value < value:
            prev.right = Node(value)
        else:
            prev.left = Node(value)

    def search(self, node: Node, key: int) -> Node:
        if node == None or node.value == key:
            return node
        
        if key < node.value:
            return self.search(node.left, key)
        else:
            return self.search(node.right, key)

    def search_iterative(self, node: Node, key: int) -> Node:
        while node != None and key != node.value:
            if key < node.value:
                node = node.left
            else:
                node = node.right

        return node

    def min(self, node: Node) -> Node:
        while node.left is not None:
            node = node.left
        
        return node

    def max(self, node: Node) -> Node:
        while node.right is not None:
            node = node.right

        return node

    def tree_successor(self, node: Node) -> Node:
        pass

    def minValueNode(self, node: Node) -> Node:
        current = node

        while current.left is not None:
            current = current.left

        return current

    def deleteNode(self, root, key):
        if root is None:
            return root
            
        if key < root.key:
            root.left = self.deleteNode(root.left, key)
        elif key > root.key:
            root.right = self.deleteNode(root.right, key)
        else:
            # Node with only one child ( left or right, regardless )
            if root.left is None:
                temp = root.right
                root = None
                return temp
            elif root.right is None:
                temp = root.left
                root = None
                return temp

            # Node with two children
            # Get the smallest node from the right subtree
            # Replace the contents

            temp = self.minValueNode(root.right)
            root.key = temp.key

            # Delete the smlleast node from the right subtree
            root.right = self.deleteNode(root.right, temp.key)

        return root