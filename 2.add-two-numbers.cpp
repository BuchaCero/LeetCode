#include <iostream>
#include <sstream>

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
    ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode *current = &dummy;

        while (l1 || l2 || carry) {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int sum = num1 + num2 + carry;
            current->next = new ListNode(sum % 10);
            current = current->next;
            carry = sum / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }
};

void inputLinkedList(ListNode *ptr) {
    string line;
    getline(cin, line);
    istringstream iss(line);
    int num;
    while (iss >> num) {
        ptr->next = new ListNode(num);
        ptr = ptr->next;
    }
}

void printLinkedList(ListNode *head) {
    ListNode *current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << "->";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    ListNode dummy1(0);
    ListNode dummy2(0);
    inputLinkedList(&dummy1);
    inputLinkedList(&dummy2);
    ListNode *result = sol.addTwoNumbers(dummy1.next, dummy2.next);
    printLinkedList(result);
}