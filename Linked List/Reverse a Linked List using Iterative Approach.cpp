// Linked List - Given a Linked List. Write a function to reverse the linked list.

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
        cout << head -> data << "\n";
        head = head->next;
    }
}

node * reverse(node *head){
    if(head == NULL || head -> next == NULL)
        return head;
    node* current = head;
    node* prev = NULL;
    node* temp;

    while(current!= NULL){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;
}
int main() {
    node* head = NULL;
    head = insertAtHead(head, 7);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);

    printLinkedList(head);
    node * reverseHead = reverse(head);

    printLinkedList(reverseHead);
    
}
