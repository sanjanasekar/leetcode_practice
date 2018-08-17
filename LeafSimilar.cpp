/*
  Created By : Sanjana Sekar
  Created on : August 17, 2018
  Source     : https://leetcode.com/problems/leaf-similar-trees/description/
  
  Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

      3
    /   \
  5      1
 / \    / \
6   2  9   8
  /   \
 7     4

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:

Both of the given trees will have between 1 and 100 nodes.

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        vector<int> leafs1, leafs2;
        GetLeafs(root1,leaf1);
        GetLeafs(root2, leaf2);
        if(leaf1 == leaf2)
            return true;
        else
            return false;
        
        
    }
    void GetLeafs(TreeNode* root, vector<int>& leafs){
        if(root){
            if(root->left == NULL && root->right == NULL){
                leafs.push_back(root->val);
            }
            else{
                GetLeafs(root->left,leafs);
                GetLeafs(root->right, leafs);
            }
        }

    }
};
