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
    ListNode* rotateRight(ListNode* head, int k) {
        if ( head == nullptr ) return head;
        int size = 1;
        ListNode* tail = head;
        ListNode* ptr = head;
        ListNode* pre = nullptr;
        while ( tail -> next != nullptr ) {
            ++size;
            tail = tail -> next;
        } 
        if ( k % size == 0 ) return head;
        int step = size - ( k % size );
        cout << size;
        while ( step-- ){
            pre = ptr;
            if ( ptr == nullptr ) ptr = head;
            else ptr = ptr -> next;
        }
        tail -> next = head;
        pre -> next = nullptr;
        return ptr;
    }
};