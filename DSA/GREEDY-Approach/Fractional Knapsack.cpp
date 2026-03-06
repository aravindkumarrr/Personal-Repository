#include <iostream>
#include <vector>
using namespace std;

void sort(vector<double>&ratio,vector<int>&p, vector<int>&w){
    int n = p.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){ // use j = i+1 to prevent switching back (happens when j starts from 0)
            if(ratio[i]<ratio[j]){
                swap(ratio[i],ratio[j]);
                swap(p[i],p[j]);
                swap(w[i],w[j]);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> profit(n,0);
    vector<int> weight(n,0);
    int capacity = 0;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        profit[i] = temp;
        cin>>temp;
        weight[i] = temp;
    }

    cin>>capacity;

    
    vector<double>ratio(n,0);
    vector<double>hot_encode(n,0);
    for(int i=0;i<n;i++){
        ratio[i] = (double)profit[i]/weight[i]; // Force a type conversion to prevent integer division and getting wrong answer.
    }
    sort(ratio,profit,weight);

    int rem_cap = capacity;
    int total_used = 0;

    for(int i=0;i<n;i++){
        if(total_used + weight[i]>capacity){
            hot_encode[i] = (double)rem_cap/weight[i]; // Force a type conversion to prevent integer division and getting wrong answer.
            break;
        }
        else{
            rem_cap -= weight[i];
            total_used +=weight[i];
            hot_encode[i] = 1;
        }
    }
    double total_profit=0;
    for(int i=0;i<n;i++){
        total_profit+=hot_encode[i]*profit[i];
    }

    cout<<total_profit;
}
