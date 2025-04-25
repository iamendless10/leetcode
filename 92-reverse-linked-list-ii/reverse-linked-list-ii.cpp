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
        if (!head || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* con = &dummy;
      
        for (int i = 1; i < left; i++) {
            con = con->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = con->next;
        ListNode* tail = curr;
        
        for (int i = left; i <= right; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        
        con->next = prev;     
        tail->next = curr;     
        
        return dummy.next;
    }
};