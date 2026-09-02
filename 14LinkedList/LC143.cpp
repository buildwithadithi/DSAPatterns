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

class Solution {
public:

    ListNode* reverse(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {

        if (!head || !head->next) {
            return;
        }

        ListNode* s = head;
        ListNode* f = head;
        ListNode* hp;

        // Find middle
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }

        // Second half
        hp = s->next;

        // Separate the two halves
        s->next = nullptr;

        // Reverse second half
        hp = reverse(hp);

        // Merge
        ListNode* temp1 = head;
        ListNode* temp2 = hp;
        ListNode* t1next;

        while (temp1 && temp2) {

            t1next = temp1->next;

            temp1->next = temp2;
            temp2 = temp2->next;

            temp1->next->next = t1next;

            temp1 = t1next;
        }
    }
};