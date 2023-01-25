// PROGRAM FOR MAX-HEAP AND HEAP SORT
#include<iostream>
using namespace std;

// Insert Function
void Insert(int A[], int n)
{
  int i = n, temp;
  temp = A[i];

  while(i>1 && temp>A[i/2])
  {
    A[i] = A[i/2];
    i=i/2;
  }
  A[i] = temp;
}

// Delete Function
// This funtion delete an element and alse keeping the deleted element at last
int Delete(int A[], int n)
{
  int i, j, x, temp, val;
  val = A[1]; //Deleted value
  x = A[n];
  A[1] = A[n];
  
  A[n] = val; // This statement storing the element at last place
  
  i=1; j=i*2;

  while(j < n-1)
  {
    if(A[j+1] > A[j])
      j=j+1;
    if(A[i] < A[j])
    {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      i = j;
      j = 2*j;
    }
    else
       break;
  }
  return val;
}

int main()
{
  int H[]={0,10,20,30,25,5,40,35}; // Array size is 8 but heap size is 7, because we will not consider 0
  // 40, 25, 35, 10, 5, 20 , 30

  int i;

  for(i=2; i<=7; i++)
    Insert(H, i);

  // cout<<"Deleted value is "<<Delete(H,7);
  // cout<<"Deleted value is "<<Delete(H,6);
  // cout<<"\n";

  // Heap sort
  for(i=7; i>1; i--)
  {
    Delete(H,i);
  }
  
  // Display
  for(i=1; i<=7; i++)
    cout<<" "<<H[i];
  cout<<"\n";

  return 0;
}