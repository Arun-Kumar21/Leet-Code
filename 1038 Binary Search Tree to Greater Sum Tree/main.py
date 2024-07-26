class TreeNode:
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right

class Solution:
    sum = 0

    def inverse_in_order(self, root: TreeNode):
        if root == None :
            return
        
        self.inverse_in_order(root.right)
        root.val += self.sum
        self.sum = root.val
        self.inverse_in_order(root.left)
        

    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.inverse_in_order(root)
        return root