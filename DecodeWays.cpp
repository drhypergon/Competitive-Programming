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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *present = head;
        ListNode *next;
        ListNode *returned = head;
        while (present != NULL)
        {
            next = present->next;
            if (next != NULL && next->val == present->val)
            {
                present->next = next->next; 
            }
            else
            {
                present = present->next;
            }
        }
        return returned;
    }
};
