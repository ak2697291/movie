#include<bits/stdc++.h>

using namespace std;

class Node {
public:
int data;
Node* left;
Node* right;

Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

};

Node* buildTree(Node* root) {
    int d;
    cin >> d;
    root = new Node(d);

    if (d == -1) {
        return NULL;
    }

    cout << "enter the data for inserting in left of"<<d<<endl;
    root->left = buildTree(root->left);
    cout<< "enter the data for inserting in right of" <<d<<endl;
    root->right  = buildTree(root->right);

    return root;

    

}
void levelOrderTraversal(Node* root){
queue<Node*> q;
q.push(root);
q.push(NULL);

while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    

    if (temp == NULL) {
        cout<<endl;
        if (!q.empty()){
            q.push(NULL);
        } 
    } else {
        cout<<temp->data<<" ";
           if (temp->left) {
        q.push(temp->left);
    }
    if(temp->right){
        q.push(temp->right);
    }
    }

 
}
}

void reverselevelOrderTraversal(Node* root) {
    queue<Node*> q;
    stack<Node*> s;
q.push(root);
q.push(NULL);
s.push(root);
s.push(NULL);

while(!q.empty()){
    Node* temp = q.front();
    
    q.pop();
    

    if (temp == NULL) {
        // cout<<endl;
        if (!q.empty()){
            q.push(NULL);
            s.push(NULL);
        } 
    } else {
        // cout<<temp->data<<" ";
           if (temp->left) {
        q.push(temp->left);
        s.push(temp->left);
    }
    if(temp->right){
        q.push(temp->right);
        s.push(temp->right);
    }
    }
  

 
}

stack<Node*> ns;

  cout<<"reverse level order traversal" <<endl;
while(!s.empty()) {
        Node* temp = s.top();
        s.pop();
        if (temp == NULL) {
            while(!ns.empty()){
                cout<<ns.top()->data<<" ";
                ns.pop();
            }
            cout<<endl;
        } else {
            ns.push(temp);
            // cout <<temp->data<<" ";
        }
    }
    cout<<ns.top()->data<<endl;



}

void inorderTraversal(Node* root) {//left root right

if (root == NULL){
    return;
}

if (root->left) {
    inorderTraversal(root->left);
}
cout <<root->data<<" ";

if (root->right){
    inorderTraversal(root->right);
}

}

void preOrderTraversal(Node* root ){ //root left right

if (root == NULL){
    return;
}
cout <<root->data<<" ";
if (root->left) {
    preOrderTraversal(root->left);
}

if (root->right){
    preOrderTraversal(root->right);
}

}

void postOrderTraversal(Node* root) { //left right root

if (root == NULL){
    return;
}

if (root->left) {
    postOrderTraversal(root->left);
}

if (root->right){
    postOrderTraversal(root->right);
}
cout <<root->data<<" ";

}

Node* buildTreeFromLevelOrder(Node* root) {
queue<Node*> q;

int d;
cin>>d;
root = new Node(d);
q.push(root);
while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    cout<< "enter the node you want to put left of"<<temp->data<<endl;
    int ld;
    cin>>ld;
    if (ld !=-1){

    temp->left = new Node(ld);
    q.push(temp->left);
    }

    cout<< "enter the node you want to put right of"<<temp->data<<endl;
    int rd;
    cin>>rd;
    if (rd !=-1){
    temp->right =  new Node(rd);
    q.push(temp->right);
    }

}
return root;
}

int main() {
// #ifndef ONLINE_JUDGE	
// 	freopen("output.txt","w",stdout);
// 	freopen("input.txt","r",stdin);
// #endif
//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 10 -1 -1 -1 7 -1 12 -1 -1
//3 20 11 15 16 18 20 1 -1 3 -1 7 -1 -1 8 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Node * root = NULL;
cout << "Enter the data for root Node:" <<endl;

// root = buildTree(root);
root = buildTreeFromLevelOrder(root);
cout<<"level order traversal:"<<endl;
levelOrderTraversal(root);
reverselevelOrderTraversal(root);
cout << "inorder Traversal"<<endl;
inorderTraversal(root);

cout<<endl << "pre order Traversal"<<endl;
preOrderTraversal(root);

cout<<endl<<"post order Traversal" <<endl;
postOrderTraversal(root);

/*
                    1
        2                       4
    8    -1                 -1      9
-1    -1                         5      -1
                            -1      3
                                6       10
                            -1      -1  -1  7
                                        -1      12
                                            -1      -1
*/
}