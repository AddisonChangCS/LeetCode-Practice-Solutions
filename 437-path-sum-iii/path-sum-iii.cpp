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
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<long, int> path_prefix;
    //Time: O(n)
    //Space: O(n)
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        path_prefix[0]++;
        return DFS(root, targetSum, 0);
    }
    int DFS(TreeNode* root, int targetSum, long prefix){
        if(!root) return 0;
        path_prefix[prefix+root->val]++;
        int right=DFS(root->right, targetSum, prefix+root->val);
        int left=DFS(root->left, targetSum, prefix+root->val);
        path_prefix[prefix+root->val]--;
        return path_prefix[prefix+root->val - targetSum] + right + left;
    }
};