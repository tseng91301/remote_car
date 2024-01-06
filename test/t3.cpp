#include<bits/stdc++.h>
using namespace std;
int addFunc(int a,int b){
    return a+b;
}
int minusFunc(int a,int b){
    return a-b;
}
int main(){
    typedef int (*FunctionPointer)(int,int);
    FunctionPointer *FunctionArray = new FunctionPointer[2];
    FunctionArray[0]=addFunc;
    FunctionArray[1]=minusFunc;
    cout<<"Function 1(a+b): "<<FunctionArray[0](1,2)<<endl;
    cout<<"Function 2(a-b): "<<FunctionArray[1](1,2)<<endl;
    delete[] FunctionArray;
}