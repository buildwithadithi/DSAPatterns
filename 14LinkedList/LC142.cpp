#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        // Phase 1: Find whether slow and fast meet
        while (fast != nullptr && fast->next != nullptr)
        {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        // No cycle
        if (fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }

        // Phase 2: Find the starting point of the cycle
        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};