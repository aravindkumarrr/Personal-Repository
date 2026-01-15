#include <iostream>
#include <iomanip>
#include <vector>
using namespace std; 

template <typename T>
void swap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n, W; 
    double currWeight = 0.0;
    double currProfit = 0.0;
    
    cin>>n;
    
    vector<int> weight;
    vector<int> profit;
    vector<double> ratio;
    vector<double> frac(n,0);
    
    for(int i=0;i<n;i++){
        int temp = 0;
        cin>>temp; 
        weight.push_back(temp);
    }
    
    for(int i=0;i<n;i++){
        int temp = 0;
        cin>>temp; 
        profit.push_back(temp);
    }
    
    cin>>W;
    
    for(int i=0;i<n;i++){
        double temp = (double)profit[i]/weight[i];
        ratio.push_back(temp);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ratio[i]>ratio[j]){
                swap(&ratio[i],&ratio[j]);
                swap(&weight[i],&weight[j]);
                swap(&profit[i], &profit[j]);
            }
        }
    } // Bubble-sorting by highest P/W ratio
    
    for(int i=0;i<n; i++){
        if(currWeight + weight[i] <= W){
            currWeight += weight[i];
            currProfit += profit[i];
        }
        else{
            int remain = W - currWeight;
            currProfit += profit[i]*((double)remain/weight[i]);
            break;
        }
    }
    
    cout<<currProfit;
}
