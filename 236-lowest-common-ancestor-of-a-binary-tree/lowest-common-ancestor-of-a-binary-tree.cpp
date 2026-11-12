/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //Time: O(N)
    //Space: O(H)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool p_mark=false, q_mark=false;
        TreeNode* lca=nullptr;
        DFS_with_mark(root, p, q, lca);
        return lca;
    }
    pair<bool, bool> DFS_with_mark(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& lca){
        if(!root) return{false, false};
        auto [right_p, right_q] = DFS_with_mark(root->right, p, q, lca);
        auto [left_p, left_q] = DFS_with_mark(root->left, p, q, lca);
        bool p_mark = (root == p) || right_p || left_p;
        bool q_mark = (root == q) || right_q || left_q;

        if (p_mark && q_mark && !lca) {
            lca = root;
        }

        return {p_mark, q_mark};
    }
};