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
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> leaf1, leaf2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        DFS(root1, leaf1);
        DFS(root2, leaf2);
        return (leaf1==leaf2);
    }
    void DFS(TreeNode* root, vector<int>& v){
        if(root->left) DFS(root->left, v);
        if(root->right) DFS(root->right, v);
        if(!root->left && !root->right){
            v.push_back(root->val);
            return;
        }
    }
};