class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node -> next;
        swap( next -> val, node -> val );
        if ( next -> next == nullptr ) node -> next = nullptr;
        else node -> next = next -> next;
    }
};