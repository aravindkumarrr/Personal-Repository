#include <iostream>
#include <iomanip>
#include <queue>
#include <utility>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f){
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare{
    bool operator()(Node* a, Node*b){
        return a->freq > b->freq;   
    }
};

Node* huffman_tree(vector<Node*> &nodevec){
    priority_queue<Node*, vector<Node*>, compare> h_tree;
    for(int i=0;i<nodevec.size();i++)
    {
        h_tree.push(nodevec[i]);
    }
    
    
    while(h_tree.size()>1){
        Node* x = h_tree.top();
        h_tree.pop();
        Node* y = h_tree.top();
        h_tree.pop();
        
        Node* z = new Node('$', x->freq+y->freq);
        z->left = x;
        z->right = y;
        h_tree.push(z);
    }
    return h_tree.top();
}

void printTree(Node* root, string code = ""){
    if(!root) return;
    if(root->left ==NULL && root->right == NULL){
        cout<<root->ch<<" "<<code<<endl;
        return;
    }
    printTree(root->left, code + "0");
    printTree(root->right, code + "1");
}

int main(){
    int n;
    cin>>n; // Number of symbols
    vector<Node*> inputs;
    for(int i=0;i<n;i++){
        char tempchar;
        int tempint;
        cin>>tempchar>>tempint;
        Node* temp = new Node(tempchar, tempint);
        inputs.push_back(temp);
    }
    
    Node* root = huffman_tree(inputs);
    printTree(root);
    
    
}
