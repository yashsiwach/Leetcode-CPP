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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       std::unordered_set<int> v;
        
       
        ListNode* current = head;
        while (current != nullptr) {
            v.insert(current->val);
            current = current->next;
        }
        
       
        for (const auto& it : nums) {
            v.erase(it);
        }

    
        ListNode dummy;  
        ListNode* new_head = &dummy;

        current = head;
        while (current != nullptr) {
            if (v.find(current->val) != v.end()) {
                new_head->next = new ListNode(current->val);
                new_head = new_head->next;
            }
            current = current->next;
        }

        return dummy.next;
    }
};