class Solution {
public:
    // Reverses k nodes from 'head' and sets 'nextGroupHead'
    Node* reverse(Node* head, int k, Node*& nextGroupHead) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        nextGroupHead = curr; // Head of next group
        return prev; // New head of reversed group
    }

    Node* reverseKGroup(Node* head, int k) {
        if (!head || k <= 1) return head;

        Node* newHead = nullptr;
        Node* prevTail = nullptr;
        Node* curr = head;

        while (curr) {
            Node* nextGroupHead = nullptr;
            Node* groupHead = curr;
            Node* reversedHead = reverse(groupHead, k, nextGroupHead);

            if (!newHead) newHead = reversedHead;
            if (prevTail) prevTail->next = reversedHead;

            prevTail = groupHead; // Old head becomes new tail
            curr = nextGroupHead;
        }

        return newHead ? newHead : head;
    }
};
