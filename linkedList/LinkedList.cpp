#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back
class node{
    public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }

};

class doublyNode {
    public:
    int data;
    doublyNode* next;
    doublyNode* prev;

    doublyNode(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTailDL(doublyNode* &head, int val) {

    doublyNode* n = new doublyNode(val);
    if (head == NULL) {
        head = n;
        return;
    }
    doublyNode* prev = NULL;
    doublyNode* ptr = head;

    while(ptr->next!=NULL) {
      ptr = ptr->next;
    }

    ptr->next = n;
    n->prev = ptr;
    n->next = NULL;
}

void insertAtTail(node * &head,int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node* ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = n;

}

void insertAtHead(node* &head, int val) {
node *n = new node(val);

n->next = head;
head = n;

}

void deleteNodeByKey(node * &head, int val) {
    node* ptr = head;
    node* prev = NULL;
    node* todelete = NULL;
    while(ptr != NULL) {
        if (ptr->data == val) {
            if (prev != NULL) {
                todelete = prev->next;
                prev->next = ptr->next;
                delete todelete;
                return;
            } else {
                todelete = head;
                head = head->next;
                delete todelete;
                return;
            }

        }
        prev = ptr;
        ptr = ptr->next;
    }
}
void reverseLinkedList(node* &head) {
    node* ptr = head;
    node* prev = NULL;
    node* next1 = NULL;
    while(ptr ->next != NULL) {


        next1 = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next1;
  
    }
    ptr->next = prev;

    head = ptr;
}
bool search(node* head, int key) {
    while(head != NULL) {
        if (head->data == key) {
            return true;
        }
        head = head->next;
    }
    return false;
}

void displayList(node* head) {
    while(head!= NULL) {
        cout <<head->data << "->";
        head = head->next;
    }

    cout <<"NULL"<<endl;
}

void displayDList(doublyNode* head) {
    while(head!= NULL) {
        cout <<head->data << "->";
        head = head->next;
    }

    cout <<"NULL"<<endl;
}
int32_t main() {
#ifndef ONLINE_JUDGE	
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
#endif
node* head = NULL;
insertAtHead(head, 1);
insertAtTail(head, 2);
insertAtTail(head, 3);
insertAtTail(head, 4);

displayList(head);

insertAtHead(head, 5);
displayList(head);

if (search(head, 3)) {
    cout<<"Found Key"<<endl;
}else {
    cout <<"Key Not Found" <<endl;
}

// deleteNodeByKey(head, 3);
displayList(head);
reverseLinkedList(head);
displayList(head);




//doubly linkedList;
doublyNode* dhead = NULL;
insertAtTailDL(dhead, 1);
insertAtTailDL(dhead, 2);
insertAtTailDL(dhead, 3);
insertAtTailDL(dhead, 4);
insertAtTailDL(dhead, 5);

displayDList(dhead);

}