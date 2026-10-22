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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode *odd=head, *even=head->next;
        ListNode *odd_cur=odd, *even_cur=even;
        bool is_odd=true;
        for(ListNode* cur_ptr=even->next; cur_ptr!=nullptr; cur_ptr=cur_ptr->next)
        {
            if(is_odd)
            {
                odd_cur->next=cur_ptr;
                odd_cur=odd_cur->next;
                is_odd=false;
            }
            else
            {
                even_cur->next=cur_ptr;
                even_cur=even_cur->next;
                is_odd=true;
            }
        }
        head=odd;
        odd_cur->next=even;
        even_cur->next=nullptr;
        return head;
    }
};