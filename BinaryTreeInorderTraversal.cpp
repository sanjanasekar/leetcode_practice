/*
  Created By : Sanjana Sekar
  Created On: August 18, 2018
  Source: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
  
  Description
  
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
  
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversed_order;
        PopulateTraversal(traversed_order, root);  
        return traversed_order;
    }
    void PopulateTraversal(vector<int>& order, TreeNode* node){
        if(node){
            PopulateTraversal(order, node->left);
            order.push_back(node->val);
            PopulateTraversal(order, node->right);
        }
        
    }
};
