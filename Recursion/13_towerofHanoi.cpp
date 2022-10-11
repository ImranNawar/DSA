#include<iostream>
using namespace std;

void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1, A,C,B); //callin itself
        cout<<"("<<A<<","<<C<<")"<<endl;
        TOH(n-1,B,A,C);
    }
}

int main(){
    TOH(3,1,2,3);  //first value is number of disk, the remaining three value are tower numbers

    return 0;
}
//THIS PROGRAM IS JUST GIVING THE STEPS TO BE TAKEN FOR MOVING THE DISK