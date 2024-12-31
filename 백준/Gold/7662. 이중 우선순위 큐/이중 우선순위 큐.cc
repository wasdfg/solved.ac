#include<iostream>
#include<queue>
#include<map>

using namespace std;

int main(void){
    int t,k,num,count;
    char command;
    cin>>t;
    for(int i = 0;i < t;i++){
        priority_queue<int,vector<int>,greater<int>> asc;
        priority_queue<int> desc;
        map<int,int> count;
        cin>>k;
        for(int j = 0;j < k;j++){
            cin>>command>>num;
            if(command == 'I'){
                asc.push(num);
                desc.push(num);
                count[num]++;
            }
            else{
                if(num == -1){
                    if(asc.empty()){
                        continue;
                    }
                    count[asc.top()]--;
                    asc.pop();
                }
                else{
                    if(desc.empty()){
                        continue;
                    }
                    count[desc.top()]--;
                    desc.pop();
                }
                while(!asc.empty() && count[asc.top()] == 0){
                    asc.pop();
                }
                while(!desc.empty() && count[desc.top()] == 0){
                    desc.pop();
                }
            }
        }
        while(!asc.empty() && count[asc.top()] == 0){
            asc.pop();
        }
        while(!desc.empty() && count[desc.top()] == 0){
            desc.pop();
        }
        if(asc.empty() || desc.empty()){
            cout<<"EMPTY\n";
        }
        else{
            cout<<desc.top()<<" "<<asc.top()<<"\n";
        }
    }
    return 0;
}