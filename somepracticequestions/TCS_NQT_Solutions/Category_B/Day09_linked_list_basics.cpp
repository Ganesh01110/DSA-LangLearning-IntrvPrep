#include <iostream>
#include <vector>
using namespace std;

/**
 * Simple Linked List: Insert and Traverse
 */

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

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
    
    printList(head);
    
    return 0;
}
