#include <iostream>
using namespace std;
#define max 100

class ArrayBT{
    private:
        int tree[max];
        int size;
    public:
        ArrayBT(){
            size = 0;
            for(int i=0;i<max;i++){
                tree[i] = -1;
            }
        } //constructor to initialize default element value
        void insert(int val){
            if(size<max){
                tree[size] = val;
                size++;
            }
            else{
                cout<<"Tree is full!\n";
            }
        }
        bool isValid(int indx){
            if(indx<max && tree[indx]!=-1) return true;
            else return false;
        }

        void inorder(int root = 0){
            if(!isValid(root)) return;

            inorder(2*root + 1); // Left child
            cout<<tree[root]<<" "; // Root
            inorder(2*root + 2); // Right child
        }
        void preorder(int root = 0){
            if(!isValid(root)) return;
            cout<<tree[root]<<" "; // Root
            preorder(2*root + 1); // Left child
            preorder(2*root + 2); // Right child
        }
        void postorder(int root = 0){
            if(!isValid(root)) return;
            postorder(2*root + 1);
            postorder(2*root + 2);
            cout<<tree[root]<<" ";
        }
        
};
