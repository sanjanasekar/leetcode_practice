/*

  Created By : Sanjana Sekar
  Created On : August 17, 2018
  Source     : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
  
  Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

  A node is deepest if it has the largest depth possible among any node in the entire tree.

  The subtree of a node is that node, plus the set of all descendants of that node.

  Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

 

  Example 1:

  Input: [3,5,1,6,2,0,8,null,null,7,4]
  Output: [2,7,4]
  
  We return the node with value 2, colored in yellow in the diagram.
  The nodes colored in blue are the deepest nodes of the tree.
  The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
  The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
  Both the input and output have TreeNode type.

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return FindLevelsAndSubRoot(root).second;    
    }
    pair<int, TreeNode*> FindLevelsAndSubRoot(TreeNode* root){
        if(!root)
            return {0, NULL};
        else if (root){
            pair<int, TreeNode*> leftLevel = FindLevelsAndSubRoot(root->left);
            pair<int, TreeNode*> rightLevel = FindLevelsAndSubRoot(root->right);
            int llen = leftLevel.first;
            int rlen = rightLevel.first;
            if (llen > rlen)
                return {llen + 1, leftLevel.second};
            else if (llen < rlen)
                return {rlen + 1, rightLevel.second};
            else
                return {llen + 1, root};
        }
      }
};
