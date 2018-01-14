/*Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        if(temp == NULL)
            return NULL;
        else if((temp->next == NULL) && (n == 1)){
            return NULL;
        }
        else{
            int count = 1;
            while(temp->next != NULL){
                count++;
                temp = temp->next;  
            }
            if(n >= count)
                return head->next;
            else{
               int n_rem = count - n;
               temp = head;
               cout << n << count << endl;
               count = 1;
               cout << n_rem<<endl;
               while(temp->next != NULL){
                   if(count == n_rem){
                       if(temp->next->next != NULL){
                           ListNode* new_next = temp->next->next; 
                           new_next->val = temp->next->next->val;
                           cout << new_next->val;
                           temp->next = NULL;
                           temp->next = new_next;
                           return head;
                       }
                       else{
                           temp->next = NULL;
                           return head;
                       }
                       
                   }
                   else{
                           temp = temp->next;
                           count++;
                   }
                   
               }
            }
          return head;  
        }
        
    }
};
