#include<bits/stdc++.h>
using namespace std;
void f1(){
    cout<<"function 1"<<endl;
}
void f2(){
    cout<<"function 2"<<endl;
}
int main(){
    typedef void (*FunctionPointer)();
    FunctionPointer *FunctionArray = new FunctionPointer[2];
    FunctionArray[0]=f1;
    FunctionArray[1]=f2;
    FunctionArray[0]();
    cout<<"and"<<endl;
    FunctionArray[1]();
    delete[] FunctionArray;
}