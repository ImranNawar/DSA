#include<iostream>
using namespace std;

main()
{
    int a[5] = {3,6,23,1};
    int i, k, n=4; //n is size which is 4 and capacity is 5

    cout<<"Enter location for insertion : ";
    cin>>k;

    for(i = n-1; i >= k; i--)
      a[i+1] = a[i];
    cout<<"Enter new element : ";
    cin>>a[k];
    n++;
    
    for(i=0; i<5; i++)  // Print the updated array
    cout<<a[i]<<endl;
    
}