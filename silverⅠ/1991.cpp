#include<iostream>
#include<vector>

using namespace std;

pair<char,char> alpha[27];

void inorder(char parent){
	if(parent == '.') 
        return ;
	inorder(alpha[parent-'A'].first);
	cout<<parent;
	inorder(alpha[parent-'A'].second);
}

void preorder(char parent){
	if(parent == '.')
        return ;
	cout<<parent;
	preorder(alpha[parent-'A'].first);
	preorder(alpha[parent-'A'].second);
}

void postorder(char parent){
	if(parent == '.')
        return;
	postorder(alpha[parent-'A'].first);
	postorder(alpha[parent-'A'].second);
	cout<<parent;
}
int main(void){ //.46
    int n;
    char parent,lnode,rnode;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>parent>>lnode>>rnode;
        alpha[parent-'A'] = {lnode,rnode};
    }
    preorder('A');
    cout<<endl;
    inorder('A');
    cout<<endl;
    postorder('A');
    cout<<endl;
}