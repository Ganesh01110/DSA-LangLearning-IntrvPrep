#include <iostream>
#include <vector>
using namespace std;

/**
 * Linked List Reversal
 */

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n; cin >> n;
    if (n <= 0) return 0;
    
    int val; cin >> val;
    Node* head = new Node(val);
    Node* curr = head;
    
    for (int i = 1; i < n; i++) {
        cin >> val;
        curr->next = new Node(val);
        curr = curr->next;
    }
    
    cout << "Original: ";
    printList(head);
    
    head = reverseList(head);
    
    cout << "Reversed: ";
    printList(head);
    
    return 0;
}
