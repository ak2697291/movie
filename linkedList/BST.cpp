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

Node* insertIntoBST(Node* root, int data){
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    }else{
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}
void takeInput(Node* &root) {
    int data;
    cin>>data;

    while(data!=-1) {

        root = insertIntoBST(root,data);
        cin>>data;
    } 
}

bool searchTree(Node* root, int data) {
    if (root == NULL)
    return false;
    if (data == root->data)
    return true;

    if (data > root->data) {
        return searchTree(root->right, data);
    }
    return searchTree(root->left, data);

}

Node* minValue(Node* root) {
    Node* temp = root;

    while(temp->left!=NULL)
    temp = temp->left;

    return temp;
}
Node* maxValue(Node* root) {
    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp;
}



Node* deleteNode (Node* root, int data) {
if (root == NULL)
return root;

if (root->data == data) {

    //child 0
    if (root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }
    //child 1
    //left child
    if (root->left != NULL && root->right == NULL) {
        root = root->left;
        return root;
    }
    //right child
    if (root->left == NULL && root->right != NULL) {
         root = root->right;
         return root;

    }
    //child 2
    if (root->left != NULL && root->right != NULL) {
        Node* minNode = minValue(root->right);
        root->data = minNode->data;
        root->right = deleteNode(root->right, root->data);
        return root;

    }
}else if (root->data > data) {
    root->left = deleteNode(root->left, data);
    return root;
}else {
    root->right = deleteNode(root->right, data);
    return root;
}


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

void inOrderTraversal(Node* root) {
    if (root == NULL)
    return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
int main() {

    Node* root = NULL;
    cout << "Enter data to create BST" <<endl;
    takeInput(root);
    cout<<"in order traversal"<<endl;
    inOrderTraversal(root);
    cout<<"level order traversal"<<endl;
    levelOrderTraversal(root);

    // cout<<"enter the data to search for" <<endl;
    // int sd;
    // cin>>sd;
    // if(searchTree(root, sd)) {
    //     cout<<"FOUND"<<endl;
    // }else{
    //     cout<< "NOT FOUND"<<endl;
    // }

    cout<<"enter the data to delete"<<endl;
    int dd;
    cin>>dd;
    root = deleteNode(root,dd);
    cout<<"in order traversal after deletion"<<endl;
    inOrderTraversal(root);
    cout<<"level order traversal after deletion"<<endl;
    levelOrderTraversal(root);
//10 21 16 5 8 11 23 25 -1
}