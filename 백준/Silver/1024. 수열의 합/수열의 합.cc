#include<iostream>
#include<cmath>

using namespace std;

int main(void){
    long long N,L,saved,check = 0;
    bool over100 = true;
    cin>>N>>L;
    int start = -1, count = 0;
    
    for(int i = L; i <= 100; i++) {
        int t = i * (i - 1) / 2;

        if((N - t) % i == 0 && (N - t) / i >= 0) {
            start = (N - t) / i;
            count = i;
            break;
        }
    }

    if(start < 0) {
        cout<<start<<endl;
        return 0;
    }
    for(int i = 0; i < count; i++) {
        cout<<start + i<<" ";
    }
    return 0;
}