#include <iostream>
#include <vector>
#define INF_MIN -9999999
using namespace std;

int CSS(vector<int>& A, int low, int mid, int high);

int max(int a, int b, int c){
    int max_val = a;
    if(b > max_val) max_val = b;
    if(c > max_val) max_val = c;
    return max_val;
}

int MSS(vector<int>& A, int low, int high){
    if (high == low) return A[low];
    else{
        int mid = (high+low)/2;
        int leftsum = MSS(A, low, mid);
        int rightsum = MSS(A, mid+1, high);
        int midcrosssum = CSS(A, low, mid, high);
        return max(leftsum, rightsum, midcrosssum);
    }
}

int CSS(vector<int>& A, int low, int mid, int high){
    int sum = 0;
    int leftsum = INF_MIN;
    for(int i=mid; i>=low; i--){
        sum+=A[i];
        if(sum>leftsum) leftsum = sum;
    }
    sum = 0;
    int rightsum = INF_MIN;
    for(int i=mid+1; i<=high; i++){
        sum+=A[i];
        if(sum>rightsum) rightsum = sum;
    }
    return leftsum+rightsum;
}

int main(){
    int n;
    cin>>n;
    vector<int> inputs;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        inputs.push_back(temp);
    }
    cout<<MSS(inputs, 0, n-1);
}
