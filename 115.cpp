#include <iostream>

#define MAX 31

using namespace std;

int main(){
    int n;

    int a55[MAX],a99[MAX],a95[MAX],a59[MAX];

    cin>>n;

    a55[2]=1;
    a99[2]=1;
    a95[2]=1;
    a59[2]=1;

    for(int i=3; i<=n; ++i){
        a55[i]=a95[i-1];
        a99[i]=a59[i-1];
        a95[i]=a99[i-1]+a59[i-1];
        a59[i]=a55[i-1]+a95[i-1];
    }

    if(n==0) cout<<0<<endl; else
    if(n==1) cout<<2<<endl; else
    cout<<a55[n]+a99[n]+a95[n]+a59[n]<<endl;

    return 0;
}
