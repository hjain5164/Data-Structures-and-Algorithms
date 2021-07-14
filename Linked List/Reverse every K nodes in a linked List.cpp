// Linked List - Reverse every K nodes in a Linked List

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data = data;
            this->next = NULL;
        }
};

node* insertAtHead(node* head, int data){
    if(head == NULL){
        return new node(data);
    }
    node *temp = new node(data);
    temp->next = head;
    
    return temp;
}

void printLinkedList(node *head){
    while(head!= NULL){
        cout << head -> data << " ";
        head = head->next;
    }
}

node *KReverse(node* head, int K){
    if(head == NULL)
        return head;
    
    node *prev = NULL;
    node *current = head;
    node *temp;
    int cnt = 1;
    while(current != NULL && cnt <= K){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        cnt++;
    }
    if(temp != NULL)
        head->next = KReverse(temp, K);
    
    return prev;
}

int main() {
    node* head = NULL;
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 9);
    head = insertAtHead(head, 8);
    head = insertAtHead(head, 7);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    printLinkedList(head);

    head = KReverse(head, 3);

    printLinkedList(head);

    
}
