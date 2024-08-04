//    1 Solution =>  https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/1343900639/

//    2 Solution =>  https://leetcode.com/problems/merge-in-between-linked-lists/submissions/1343908431/

//    3 Solution =>  https://leetcode.com/problems/swapping-nodes-in-a-linked-list/submissions/1343910248/

//    5 Solution =>  

#include <iostream>

struct ListNode {
    int value;
    ListNode *next;
    ListNode(int val) : value(val), next(nullptr) {}
};

int findCycleLength(ListNode *head) {
    ListNode *slow = head, *fast = head;

    // Step 1: Detect if a cycle exists
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Cycle detected
            break;
        }
    }

    // No cycle found
    if (fast == nullptr || fast->next == nullptr) {
        return 0;
    }

    // Step 2: Find the length of the cycle
    int cycleLength = 0;
    ListNode *current = slow;
    do {
        current = current->next;
        cycleLength++;
    } while (current != slow);

    return cycleLength;
}

int main() {
    // Creating a linked list with a cycle for testing: 1 -> 2 -> 3 -> 4 -> 5 -> 2 (cycle)
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next;  // Creating the cycle

    int cycleLength = findCycleLength(head);
    std::cout << "Length of the cycle is: " << cycleLength << std::endl;

    // Cleaning up the allocated memory to avoid memory leak
    // Note: This is a simplified cleanup for the demonstration. Proper cleanup is needed for production code.
    delete head->next->next->next->next->next; // Node with value 5
    delete head->next->next->next->next; // Node with value 4
    delete head->next->next->next; // Node with value 3
    delete head->next->next; // Node with value 2
    delete head; // Node with value 1

    return 0;
}

