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
    //Time = O(n)
    //Space = O(height)
    int goodNodes(TreeNode* root) {
        return DFS_with_max_parent(root, root->val);
    }
    int DFS_with_max_parent(TreeNode* root, int max_parent){
        if(!root) return 0;
        int good_count=0;
        if(max_parent <= root->val)//good node
        {
            max_parent=root->val;
            good_count++;
        }
        int right=DFS_with_max_parent(root->right, max_parent);
        int left=DFS_with_max_parent(root->left, max_parent);
        return good_count + right + left;
    }
};