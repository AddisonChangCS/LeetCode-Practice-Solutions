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
    //Time: O(N)
    //Space: O(1)
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr) return nullptr;
        ListNode* slow_ptr=head;
        for (ListNode *fast_ptr=head; fast_ptr->next!=nullptr;)
        {
            if(fast_ptr->next!=nullptr) fast_ptr=fast_ptr->next;
            if(fast_ptr->next!=nullptr) fast_ptr=fast_ptr->next;
            if(fast_ptr->next!=nullptr) slow_ptr=slow_ptr->next;   
        }
        ListNode* target=slow_ptr->next;
        slow_ptr->next=target->next;
        delete target;
        return head;
    }
};