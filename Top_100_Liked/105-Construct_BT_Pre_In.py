'''
Info: 给出二叉树的前序遍历和中序遍历构造二叉树
Key: 第一次用python写，简洁是简洁，但代码不清晰，而且无论是时间效率
     空间效率都很低
'''

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if inorder:
            r_index = inorder.index(preorder[0])
            root = TreeNode(inorder[r_index])
            root.left = self.buildTree(preorder[1:r_index+1], inorder[0:r_index])
            root.right = self.buildTree(preorder[r_index+1:], inorder[r_index+1:])
        