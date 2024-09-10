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
    // Function to calculate the greatest common divisor of two numbers using Euclidean algorithm
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* current = head;
        while (current->next) {
            int val1 = current->val;
            int val2 = current->next->val;
            int commonDivisor = gcd(val1, val2);

            ListNode* newNode = new ListNode(commonDivisor);
            newNode->next = current->next;
            current->next = newNode;

            current = newNode->next;
        }

        return head;
    }
};
