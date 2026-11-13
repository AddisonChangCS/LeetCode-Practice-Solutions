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
    //Time: O(logN) (average)
    //Space: O(H)
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur=root;
        while(cur){
            if(val==cur->val) return cur;
            else if(val>cur->val) cur=cur->right;
            else cur=cur->left;
        }
        return nullptr;
    }
};