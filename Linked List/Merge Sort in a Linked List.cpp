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
        cout << head -> data << " ";
        head = head->next;
    }
}

node *merge(node *a, node *b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    node *c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node *midpoint(node *head){
    node *slow = head;
    node *fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *mergesort(node *head){
    if(head == NULL || head->next == NULL)
        return head;
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next = NULL;
    a = mergesort(a);
    b = mergesort(b);

    return merge(a, b);
}


int main() {
    node* head = NULL;
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 9);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 22);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 6);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 100);
    head = insertAtHead(head, 2);
    printLinkedList(head);
    head = mergesort(head);
    cout << endl;
    printLinkedList(head);

    
}
