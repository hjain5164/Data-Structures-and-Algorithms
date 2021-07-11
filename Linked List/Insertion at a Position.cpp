// Linked List - Insertion at the Head

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

node* insertAtPos(node *head, int data, int pos){
    if(pos == 0)
        return insertAtHead(head, data);
    else{
        node *temp = head;
        node *n = new node(data);
        for(int i = 1; i < pos ; i++){
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
    return head;
}

void printLinkedList(node *head){
    while(head!= NULL){
        cout << head -> data << "\n";
        head = head->next;
    }
}

int main() {
    node* head = NULL;
    head = insertAtHead(head, 7);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    head = insertAtPos(head, 4, 3);
    head = insertAtPos(head, 5, 4);

    printLinkedList(head);
    
}
