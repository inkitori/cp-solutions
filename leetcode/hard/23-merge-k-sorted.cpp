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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int N = 10001;
        vector<int> sums(N*2);
        
        int ret = true;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* cur = lists[i];
            while (cur != nullptr)
            {
                ret = false;
                sums[(cur->val) + N]++;
                cur = cur->next;
            }
        }
        
        
        int start = true;
        ListNode* head = nullptr;
        ListNode** cur = &head;        
        for (int i = 0; i < sums.size(); i++)
        {
            if (sums[i] > 0)
            {
                if (start) 
                {
                    *cur = new ListNode(i-N);
                    sums[i]--;
                    start = false;
                }
                for (int j = 0; j < sums[i]; j++)
                {
                    (*cur)->next = new ListNode(i-N);
                    cur = &(*cur)->next;
                }
                
            }
                        
        }
        return head;
        
    }
};