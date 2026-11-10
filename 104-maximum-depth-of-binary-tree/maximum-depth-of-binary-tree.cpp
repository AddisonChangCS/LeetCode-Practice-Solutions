/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Time: O(n)
    //Space: O(n)
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int right_depth=maxDepth(root->right);
        int left_depth=maxDepth(root->left);
        return (right_depth > left_depth) ? right_depth+1 : left_depth+1;
    }
};