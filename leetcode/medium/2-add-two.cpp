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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
    
    ListNode* add(ListNode* l1, ListNode* l2, int c) {
        int sum;
        ListNode *carryNode = new ListNode(c);
        
        if (l1 == nullptr && l2 == nullptr && c == 0) return nullptr;
        if (l1 == nullptr && l2 == nullptr && c == 1) return carryNode;

        else if (l1 == nullptr) sum = l2->val + c;
        else if (l2 == nullptr) sum = l1->val + c;
        else sum = l1->val + l2->val + c;    
        
        int carry = 0;
    
        if (sum > 9) {
            sum -= 10;
            carry = 1; 
        }
        
        ListNode *headPtr = new ListNode(sum);
        
        if (l1 == nullptr) headPtr->next = add(nullptr, l2->next, carry);
        else if (l2 == nullptr) headPtr->next = add(l1->next, nullptr, carry);
        else headPtr->next = add(l1->next, l2->next, carry);

        return headPtr;
    }
};