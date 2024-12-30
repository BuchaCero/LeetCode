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
    ListNode *reverseList(ListNode *head) {
        ListNode *p = head, *q = nullptr, *r;

        while (p != nullptr) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        return q;
    }
};

int main() {
    Solution sol;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    int value;
    while (cin >> value) {
        if (!head) {
            head = new ListNode(value);
            tail = head;
        } else {
            tail->next = new ListNode(value);
            tail = tail->next;
        }
    }

    ListNode *p = sol.reverseList(head);

    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}