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
    bool isPalindrome(ListNode *head) {
        int count = 0;
        ListNode *p = head;

        while (p != nullptr) {
            count++;
            p = p->next;
        }

        p = head;
        ListNode *q = nullptr, *r;
        for (int i = 0; i < count/2; i++) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        if (count % 2 != 0) p = p->next;

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