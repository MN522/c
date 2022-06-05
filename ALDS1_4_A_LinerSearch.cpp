#include <iostream>
#include <cstdint>
using namespace std;

int main(){
    
    
    uint32_t n,q,count=0,key,j;
    uint32_t S[10001];
    cin >> n;
    
    for (uint32_t i=0;i<n;i++){
        cin >> S[i];
    }

    cin >> q;
   
    for (uint32_t i=0;i<q;i++){
        cin >> key;
        S[n]=key;
        j =0;
        while(S[j]!=key){
            j++;
        }
        if(j!=n)
            count++;
    }

    cout << count <<endl;

    return 0;
}