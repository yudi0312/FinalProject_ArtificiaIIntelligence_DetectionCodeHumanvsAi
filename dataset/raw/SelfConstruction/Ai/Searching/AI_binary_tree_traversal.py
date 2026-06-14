class TreeNode:
    """A single node in a binary tree."""
    def __init__(self, value):
        self.value = value
        self.left = None   # Left child
        self.right = None  # Right child
 
 
def inorder_traversal(node, result=None):
    """Left → Root → Right (produces sorted output for a BST)."""
    if result is None:
        result = []
    if node:
        inorder_traversal(node.left, result)
        result.append(node.value)
        inorder_traversal(node.right, result)
    return result
 
 
def preorder_traversal(node, result=None):
    """Root → Left → Right (useful for copying/serialising a tree)."""
    if result is None:
        result = []
    if node:
        result.append(node.value)
        preorder_traversal(node.left, result)
        preorder_traversal(node.right, result)
    return result
 
 
def postorder_traversal(node, result=None):
    """Left → Right → Root (useful for deleting a tree)."""
    if result is None:
        result = []
    if node:
        postorder_traversal(node.left, result)
        postorder_traversal(node.right, result)
        result.append(node.value)
    return result
 
 
if __name__ == "__main__":
    #        4
    #       / \
    #      2   6
    #     / \ / \
    #    1  3 5  7
    root = TreeNode(4)
    root.left = TreeNode(2);  root.right = TreeNode(6)
    root.left.left = TreeNode(1);  root.left.right = TreeNode(3)
    root.right.left = TreeNode(5); root.right.right = TreeNode(7)
 
    print(f"[Tree] In-order:   {inorder_traversal(root)}")    # [1,2,3,4,5,6,7]
    print(f"[Tree] Pre-order:  {preorder_traversal(root)}")   # [4,2,1,3,6,5,7]
    print(f"[Tree] Post-order: {postorder_traversal(root)}")  # [1,3,2,5,7,6,4]
