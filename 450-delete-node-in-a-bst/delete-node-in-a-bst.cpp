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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode dummy(0);
        dummy.left = root;
        auto [parent, target]=findTargetParent(&dummy, root, key);
        if(!target) return root;
        deleteTarget(parent, target);
        return dummy.left;
    }
    void deleteTarget(TreeNode* parent, TreeNode* target){
        if(!target->left && !target->right){
            if(target==parent->right) parent->right=nullptr;
            else parent->left=nullptr;
        }
        else if(!target->left){
            if(target==parent->right) parent->right=target->right;
            else parent->left=target->right;
        }
        else if(!target->right){
            if(target==parent->right) parent->right=target->left;
            else parent->left=target->left;
        }
        else{
            auto [parent, pred]=findPredecessor(target);
            target->val=pred->val;
            deleteTarget(parent, pred);
        }
    }
    pair<TreeNode*, TreeNode*> findTargetParent(TreeNode* parent, TreeNode* root, int key){
        if(!root) return {nullptr, nullptr};
        if(key==root->val) return {parent, root};
        else if(key>root->val) return findTargetParent(root, root->right, key);
        else return findTargetParent(root, root->left, key);
    }
    pair<TreeNode*, TreeNode*>  findPredecessor(TreeNode* root){
        TreeNode *cur=root->left, *parent=root; 
        while(cur->right){
            parent=cur;
            cur=cur->right;
        }
        return {parent, cur};
    }
};