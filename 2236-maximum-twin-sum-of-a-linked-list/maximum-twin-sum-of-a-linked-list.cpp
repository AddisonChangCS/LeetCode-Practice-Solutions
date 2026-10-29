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
    int pairSum(ListNode* head) {
        ListNode* mid=head;
        //reverse: O(N)
        for(ListNode* fast = head->next;
     fast != nullptr && fast->next != nullptr;
     fast = fast->next->next, mid = mid->next);
        ListNode *prev=nullptr, *cur=mid->next;
        while(cur!=nullptr){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        mid->next=prev;
        //two pointer twin sum
        int max=0;
        for(ListNode *first=head, *second=mid->next; second!=nullptr; first=first->next, second=second->next){
            int sum=first->val+second->val;
            if(max<sum) max=sum;
        }
        return max;
    }
};