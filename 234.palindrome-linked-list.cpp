#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // p,s : 快慢 pointer
        // p,q,r : 反轉 linked-list
        ListNode *p = head, *s = head;
        ListNode *q = nullptr, *r;

        while (s != nullptr && s->next != nullptr) {
            s = (s->next)->next;
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        if (s != nullptr) {
            p = p->next;
        }

        while (p != nullptr) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }

        return true;
    }
};

int main() {
    Solution sol;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int value;
    while (cin >> value) {
        ListNode *temp = tail;
        if (!head) {
            head = new ListNode(value);
            tail = head;
        } else {
            tail->next = new ListNode(value);
            tail = tail->next;
        }
    }

    cout << sol.isPalindrome(head) << endl;

    return 0;
}