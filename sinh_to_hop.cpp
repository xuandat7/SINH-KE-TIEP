#include<bits/stdc++.h>
using namespace std;
int ok = 0; 
int n, k, a[30];
void khoitao(){
    for(int i=1; i<=n; i++){
        a[i] = i;
    }
}

void in(){
    for(int i=1; i<=k; i++){
        cout << a[i];
    }
    cout << ' ';
}
void sinh(){
    int i = k;
    while(a[i] == n-k+i){
        a[i] = i;
        i--;
    }
    if(i==0)    ok = 1;
    else{
        a[i]++;
        for(int j=i+1; j<=k; j++){
            a[j] = a[j-1] +1;   
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        
        cin >> n >> k;

        khoitao();
        while(!ok){
            in();
            sinh();
        }
        ok = 0;
        cout << endl;
    }
}