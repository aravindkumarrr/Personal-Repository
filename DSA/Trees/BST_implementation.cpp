#include <iostream>
using namespace std; 
struct BinaryNode{
    int data;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(int data){
        data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryNode* insert(BinaryNode* root, int data){
    if(root==NULL){
        root = new BinaryNode(data);
        return root;
    }
    if(data<root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

BinaryNode* search(BinaryNode* root, int key){
    if(root->data == key || root == NULL) return root;
    if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

BinaryNode* kthSmallest(BinaryNode* root, int &k){
    if(root == NULL || k<0){
        return NULL;
    }
    BinaryNode* leftresult = kthSmallest(root->left, k);
    if(leftresult!= NULL) return leftresult;
    k--;
    if(k==0) return root;
    return kthSmallest(root->right, k);
}

BinaryNode* kthLargest(BinaryNode* root, int &k){
    if(root == NULL || k<0) return root;
    BinaryNode* rightresult = kthLargest(root->right, k);
    if(rightresult!=NULL) return rightresult;
    k--;
    if(k==0) return root;
    return kthLargest(root->left,k);
}

BinaryNode* LCA(BinaryNode* root, int n1, int n2){
    if(root == NULL) return NULL;
    if (root->data > n1 && root->data >n2){
        return LCA(root->left, n1, n2);
    }
    if(root->data<n1 && root->data<n2){
        return LCA(root->right, n1, n2);
    }
    return root;
}

int successor(BinaryNode* root, int val){
    BinaryNode* curr = root;
    BinaryNode* succ = NULL;
    while(curr!=NULL){
        if(curr->data > val){
            succ = curr; 
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return succ ? succ->data : -1;
}

int predecessor(BinaryNode* root, int val){
    BinaryNode* curr = root;
    BinaryNode* pred = NULL;
    while(curr!=NULL){
        if(curr->data < val){
            pred = curr;
            curr = curr->right;
        }
    }
}

BinaryNode* findMin(BinaryNode* root){
    if(root==NULL) return root;
    if(root->left == NULL) return root;
    return findMin(root->left);
}

BinaryNode* deleteNode(BinaryNode* root, int val){
    if(root==NULL) return root;
    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }

    else{
        if(root->left == NULL){
            BinaryNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            BinaryNode* temp = root->left;
            delete root;
            return temp;
        }
        else{
            BinaryNode* temp = findMin(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
