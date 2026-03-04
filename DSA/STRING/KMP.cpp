#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> compute_LPS(string p){
    int len = p.length();
    int k=0;
    int m=1;
    vector<int>LPS(len,0);

    while(m<len){
        if(p[k]==p[m]){
            k++;
            LPS[m] = k;
            m++;
        }
        else if(k!=0 && p[k]!=p[m]){
            k = LPS[k-1];
        }
        else if(k==0&&p[k]!=p[m]){
            LPS[m] = 0;
            m++;
        }
    }
    return LPS;
}

void KMP(string p, string t, vector<int>LPS){
    int m = p.length();
    int n = t.length();
    int i=0, j=0;
    bool not_found = true;

    while(i<n){
        if(p[j]==t[i]){
            i++;
            j++;
        }
        if(j==m){
            not_found = false;
            cout<<i-m<<endl;
            j = LPS[j-1];
        }
        else if(i<n&&p[j]!=t[i]){
            if(j!=0){
                j=LPS[j-1];
            }
            else if(j==0){
                i++;
            }
        }
    }
    if(not_found){
        cout<<-1;
    }
}

int main(){
    string t="ABBABCBDBBBABCBDCCDBABCBDBABDBDBABDBASDABCC";
    string p = "SDAB";
    vector<int>LPS = compute_LPS(p);
    KMP(p,t,LPS);
}
