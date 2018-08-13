/*
* Created by: Sanjana Sekar
* Created on: Aug 12, 2018
* source: https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/783/
* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        else{
            int sum = (l1->val + l2->val);
            int carry = (sum > 9) ? (sum / 10) : 0;
            sum = sum % 10;
            ListNode* result = new ListNode(sum);
            ListNode* temp = result;
            l1 = l1->next;
            l2 = l2->next;
            while(l1 != NULL && l2 != NULL){
                sum = (l1->val + l2->val) + carry;
                carry = (sum > 9) ? (sum / 10) : 0;
                sum = sum % 10;
                temp->next = new ListNode (sum);
                temp = temp->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            if(l1){
                while(l1){
                    sum = l1->val + carry;
                    carry = (sum > 9) ? (sum / 10) : 0;
                    sum = sum % 10;
                    temp->next = new ListNode (sum); 
                    temp = temp->next;
                    l1 = l1->next;
                }

            }
            else if(l2)
            {
                while(l2){
                    sum = l2->val + carry;
                    carry = (sum > 9) ? (sum / 10) : 0;
                    sum = sum % 10;
                    temp->next = new ListNode (sum); 
                    temp = temp->next;
                    l2 = l2->next;
                }
            }
            if(carry > 0){
                temp->next = new ListNode(carry);
            }
            return result;
        }
        
    }
};
