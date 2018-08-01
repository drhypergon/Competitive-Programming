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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *previous = NULL;
        ListNode *next;
        
        while (head != NULL)
        {
            next = head->next;
            head->next = previous;
            
            previous = head;
            head = next;
        }
        return previous;
    }
};
