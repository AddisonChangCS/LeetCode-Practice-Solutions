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
    //Time: O(N)
    //Space: O(W)
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> nodes;
        //max_sum, level
        pair<int, int> max_sum(root->val, 1); 
        nodes.push(root);
        for(int i=1;!nodes.empty();i++){
            int level_size=nodes.size();
            int cur_sum=0;
            for(int j=0; j<level_size; j++){
                TreeNode* cur=nodes.front();
                nodes.pop();
                cur_sum+=cur->val;
                if(cur->right) nodes.push(cur->right);
                if(cur->left) nodes.push(cur->left);
            }
            if(cur_sum>max_sum.first) max_sum={cur_sum, i};
        }
        return max_sum.second;
    }
};