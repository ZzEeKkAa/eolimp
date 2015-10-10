#include <iostream>

using namespace std;

int main(){
    int n,ans=0;
    cin>>n;

    for(int i=1; i<=n; i++){
        if( (n/i)*i == n ) ++ans;
    }

    cout<<ans<<endl;

}
