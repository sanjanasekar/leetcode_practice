/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

*/


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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum;
        if(root == NULL){
            return 0;
        }
        else{
            if(root->left !=NULL && root->left->left == NULL && root->left->right == NULL){
                return (root->left->val + sumOfLeftLeaves(root->right));
            }
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
            
        }
        
    }
};
