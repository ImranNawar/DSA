#include<iostream>
using namespace std;

int main()
{
    //IST METHOD --creaate  array inside stack
    int A[3][4]={{1,2,3,4},{5,6,7,8},{2,4,6,8}};



    //2ND METHOD
    //array of pointer of size 3
    int *B[3];       // inside stack
    B[0]= new int[4]; // inside heap
    B[1]= new int[4];
    B[2]= new int[4];


    //3RD METHOD
    int **C;
    C = new int *[3]; //row itself created in heap 

    C[0] = new int[4]; //these three arrays are also in heap
    C[1] = new int[4];
    C[2] = new int[4];

    for(int i=0; i<3; i++)  //printing
    {
        for(int j=0; j<4; j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

}