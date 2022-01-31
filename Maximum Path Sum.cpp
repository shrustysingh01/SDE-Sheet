/*
A path in a binary tree is a sequence of nodes 
where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any path.
*/

/*
Time: O(n)
Space: O(h)
DFS + DP.
If root is nullptr return 0
Find the left and right subtree max sum and do a max with 0, to skip negative values
Now update res with the max of res and sum of left + right + root val
Helper function should return the max sum either from left or right subtree including the root
*/

int findMaxPathSum(TreeNode* root, int& res) {
    if (!root)
        return 0;
    
    int l = max(0, findMaxPathSum(root -> left, res));
    int r = max(0, findMaxPathSum(root -> right, res));
    
    res = max(res, l + r + root -> val);
    
    return max(l, r) + root -> val;
}

int maxPathSum(TreeNode* root) {
    int res = root -> val;
    
    findMaxPathSum(root, res);
    
    return res;
}