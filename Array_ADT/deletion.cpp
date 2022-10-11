#include<iostream>
using namespace std;

main()
{
    int a[5] = {4,7,2,8,4};
    int i, k, n=5;

    cout<<"Enter location of an array to be deleted : ";
    cin>>k;

    for(i=k; i<(n-1); i++)
       a[i] = a[i+1];
    n=n-1;

    for(i=0; i<5; i++)  // Printing updated array
      cout<<a[i]<<endl;
    
}
