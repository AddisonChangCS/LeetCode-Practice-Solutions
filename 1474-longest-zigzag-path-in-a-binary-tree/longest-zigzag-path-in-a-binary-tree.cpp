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
#define RIGHT 0
#define LEFT 1
#define RESET 2 
class Solution {
public:
    //Time: O(N)
    //Space: O(height)
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        return ZigZag_DFS(root, RESET, 0);
    }
    int ZigZag_DFS(TreeNode* root, int prev_direction, int length){
        if(!root) return length-1;
        int right, left;
        switch(prev_direction){
            case RIGHT:
                right=ZigZag_DFS(root->right, RIGHT, 1);
                left=ZigZag_DFS(root->left, LEFT, length+1);
                break;
            case LEFT:
                right=ZigZag_DFS(root->right, RIGHT, length+1);
                left=ZigZag_DFS(root->left, LEFT, 1);
                break;
            case RESET:
                right=ZigZag_DFS(root->right, RIGHT, length+1);
                left=ZigZag_DFS(root->left, LEFT, length+1);
                break;
        }
        return (right>left)?right:left;
    }
};