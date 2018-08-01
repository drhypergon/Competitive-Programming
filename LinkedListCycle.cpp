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
    bool hasCycle(ListNode *head) 
    {
        ListNode *fast = head;
        
        while (head != NULL)
        {
            if (head->next != NULL)
            {
                head = head->next;
            }
            if (fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
            }
            else
            {
                return false;
            }
            
            if (head == fast)
            {
                return true;
            }
        }
        return false;
    }
};
