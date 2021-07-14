// Linked List - Remove Duplicates from the Linked List

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

node* removeDuplicates(node* head){
    if(head == NULL || head->next == NULL)
        return head;
    
    unordered_set<int> dup_set;
    node *curr = head;
    dup_set.insert(curr->data);
    while(curr->next != NULL){
        if(dup_set.find(curr->next->data) == dup_set.end()){
            dup_set.insert(curr->next->data);
            curr = curr->next;
        }else{
            node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
    return head;
}

int main() {
    node* head = NULL;
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 5);
    printLinkedList(head);

    head = removeDuplicates(head);

    printLinkedList(head);

    
}
