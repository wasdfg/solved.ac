#include<iostream>
#include<string>

using namespace std;

int main(void){
    int n,sx,sy,kx,ky;
    string s,k,com;
    cin>>k>>s>>n;
    sx = s[0]-64;
    sy = s[1]-'0';
    kx = k[0]-64;
    ky = k[1]-'0';
    for(int i = 0;i < n;i++){
        int mx = 0,my = 0;
        cin>>com;
        if(com[0] == 'R'){
            mx = 1;
            if(com[1] == 'T'){
                my = 1;
            }
            else if(com[1] == 'B'){
                my = -1;
            }
        }
        else if(com[0] == 'L'){
            mx = -1;
            if(com[1] == 'T'){
                my = 1;
            }
            else if(com[1] == 'B'){
                my = -1;
            }
        }
        else if(com[0] == 'B'){
            my = -1;
        }
        else if(com[0] == 'T'){
            my = 1;
        }
        if(kx+mx < 1 || kx+mx > 8 || ky+my < 1 || ky+my > 8)
            continue;
        if(kx+mx == sx && ky+my == sy){
            if(sx+mx < 1 || sx+mx > 8 || sy+my < 1 || sy+my > 8){
                continue;
            }
            sx = sx+mx;
            sy = sy+my;
        }
        kx = kx+mx;
        ky = ky+my;
    }
    cout<<(char)(kx+64)<<ky<<"\n"<<(char)(sx+64)<<sy;
    return 0;
}