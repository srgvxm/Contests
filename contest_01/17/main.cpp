#include <iostream>
using namespace std;
int main() {
    long ans=0,n;
    cin>>n;
    int *land=new int[n];
    int *wat=new int[n];
    for (int i=0; i<n; i++) {
        cin>>land[i];
    }
    int mx=0;
    for (int i=0; i<n; i++) {
        if (mx<land[i]) {
            mx=land[i];
            wat[i]=0;
        } else {
            wat[i]=mx-land[i];
        }
    }
    mx=0;
    for (int i=n-1; i>=0; i--) {
        if (mx<land[i]){
            mx=land[i];
            wat[i]=0;
        } else {
            wat[i]=min(wat[i], mx-land[i]);
        }
        ans+=wat[i];
    }
    std::cout<<ans;
}