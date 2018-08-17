/*
  Created by : Sanjana Sekar
  Created on : August 16, 2018
  Source     : https://leetcode.com/problems/merge-k-sorted-lists/description/
  
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        vector<int> all_nums;
        for(vector<ListNode*>::iterator itr = lists.begin(); itr!= lists.end(); ++itr){
            ListNode* head = (*itr);
            if(head == NULL)
                continue;
            else{
                while(head != NULL){
                    all_nums.push_back(head->val);
                    head = head->next;
                }                
            }
        }

        if(all_nums.empty()){
            return NULL;
        }
        else {
            sort(all_nums.begin(), all_nums.end());
            vector<int>::iterator itr = all_nums.begin();
            int value = (*itr);
            ListNode* head = new ListNode(value);
            ListNode* temp = head;
            for(itr = all_nums.begin(); itr!=all_nums.end(); ++itr){
                if(itr != all_nums.begin()){
                    temp->next = new ListNode((*itr));
                    temp = temp->next;
                }
            
            }
            return head;
        }
        
    }
};
