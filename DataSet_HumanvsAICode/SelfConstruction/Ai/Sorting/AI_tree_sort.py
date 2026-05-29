class TreeNode:
    """A helper node class representing points inside a Binary Search Tree."""
    def __init__(self, key: int):
        self.val = key
        self.left = None
        self.right = None

def insert_node(root: TreeNode, key: int) -> TreeNode:
    """Helper function to insert a new node with given key in BST."""
    if root is None:
        return TreeNode(key)
    if key < root.val:
        root.left = insert_node(root.left, key)
    else:
        root.right = insert_node(root.right, key)
    return root

def inorder_traversal(root: TreeNode, sorted_list: list):
    """Helper function to perform in-order traversal and extract items."""
    if root:
        inorder_traversal(root.left, sorted_list)
        sorted_list.append(root.val)
        inorder_traversal(root.right, sorted_list)

def tree_sort(arr: list) -> list:
    """Sorts a list using a Binary Search Tree mapping representation."""
    if not arr:
        return arr
        
    root = None
    # Build the binary search tree
    for item in arr:
        root = insert_node(root, item)
        
    # Re-populate list using an in-order traversal sequence
    sorted_list = []
    inorder_traversal(root, sorted_list)
    return sorted_list

# Example Usage
if __name__ == "__main__":
    sample_data = [54, 23, 89, 12, 6, 45, 71]
    print("Original array:", sample_data)
    sorted_data = tree_sort(sample_data.copy())
    print("Tree Sorted array:", sorted_data)