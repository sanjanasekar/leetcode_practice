/*
  Author: Sanjana Sekar
  Title: Sorted Linked List to Balanced Tree
  Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
  Created on : Jan 14 2018
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

  For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


  Example:

  Given the sorted linked list: [-10,-3,0,5,9],

  One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 
 Try to get the length of the list. Then keep recursing the list to construct the tree. 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBSTHelper(ListNode **head, int len){
        if(len == 0){
            return NULL;
        }
    
        else{
             TreeNode* left = sortedListToBSTHelper(head, len/2);
             TreeNode* root = new TreeNode((*head)->val);
             root->left = left;
             *head = (*head)->next;
             root->right = sortedListToBSTHelper(head, (len - len/2 -1));
             return root;
        }
    }
    TreeNode* sortedListToBST(ListNode* head) {
       int list_len = 0;
        ListNode* temp = head;
       while(temp){
           temp = temp->next;
           list_len++;
       }
        
      return sortedListToBSTHelper(&head, list_len);
    }
};
