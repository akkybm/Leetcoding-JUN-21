/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        if(left == right)
        {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        ListNode* next;
        int count =1;
        
        while(curr)
        {
            next = curr->next;
            
            if(count == left)
            {
                ListNode* temp = curr;
                ListNode* tempprev = NULL;
                ListNode* tempnext;
                
                while(temp && count != right)
                {
                    tempnext = temp->next;
                    temp->next = tempprev;
                    tempprev = temp;
                    temp = tempnext;
                    count++;
                }
                
                curr->next = temp->next;
                temp->next = tempprev;
                prev->next = temp;
                
            }
            else
            {
                prev = curr;
                curr = next;
                count++;
            }
        }
        return dummy->next;
    }
};
