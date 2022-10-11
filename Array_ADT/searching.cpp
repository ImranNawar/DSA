#include <iostream>
using namespace std;

main()
{
    int a[5];
    int i, large;
    for(i=0; i<5; i++)  // Loop to store values in an array
    {
        cout<<"Enter elements to  array : ";
        cin>>a[i];
    }

    large = a[0];
    for(i =0; i<5; i++)  // Find largest value in an array
    if(a[i] > large)
       large =a[i];

    cout<<"largest value : "<<large;

    
}