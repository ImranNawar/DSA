// Different twenty functions of an array

#include<iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    cout<<"\n Elements are \n";
    for(int i=0; i<arr.length; i++)
        cout<<arr.A[i]<<" ";
}


//adding  NEW ELEMENT AT END
void append(struct Array *arr, int x) //As it is going to modify array it should be call by address type
{
    if(arr->length < arr->size)   //to check free space 
        arr->A[arr->length++]=x;
}

void insert(struct Array *arr, int index, int x)//As it is going to modify array it should be call by address type
{                                                //x is element to be insert
    int i;
    if(index>=0 && index <= arr->length)
    {
        for(i=arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}

int Delete(struct Array *arr,int index) //As it is going to modify array it should be call by address type
{
    int x = 0;
    if(index>=0 && index<= arr->length)//To check index is valid or not
    {
        x = arr->A[index];
        for(int i=index; i<arr->length-1; i++)
           arr->A[i] = arr->A[i+1];  //This will shift all the elements
        arr -> length--;   //After shifting length of an array should be decremented
        return x;     //value x whatever the value is deleted
    }
    return 0;  //if element is not found return 0
}

void swap(int *x, int *y)   // Swapping two elements
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int linearsearch(struct Array arr,int key)//we are not passing by address because we are not modifying array
{
    for(int i =0; i<arr.length; i++)  //in call by value we use dot . and in call by address we use arrow ->
    {
        if(key == arr.A[i])
            return i;
    }
    return -1;
}

// ITERATIVE PROCEDURE
int binarySearch(struct Array arr, int key )
{
    int l,  h, mid;
    l=0; 
    h=arr.length;


    while(l<=h)
    {
        mid=(l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l= mid+1;
    }
    return -1; //  if it return -1 means unsuccesful search
}

// RECURSIVE PROCEDURE
int rbinarySearch(int a[], int l, int h, int key)
{
    int  mid;

    if(l<=h)
    {
        mid=(l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key<a[mid])
            return rbinarySearch(a, l, mid-1, key);
        else
            return rbinarySearch(a, mid+1, h, key);
    }
    return -1;
}


////////  GET FUNCTON  ///////
int get(struct Array arr, int index) //It should be called by value because it is not going to modify array
{
    if(index >= 0 && index < arr.length) // to check whether given index is valid or not
        return arr.A[index];
    return -1;    //otherwise
}

////////  SET FUNCTION  ////////
void set(struct Array *arr, int index, int x) //It should be call by addres because it is going to modify array
{
    if(index >=0 && index < arr->length)
        arr->A[index] = x;
}

/////////  MAXIMUM FUNTION  //////////
int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

///// MINIMUM FUNTION  ///////////
int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
 /////// SUM FUNCTION  ////////
int sum(struct Array arr)
{
    int s =0;
    for(int i =0; i<arr.length; i++)
        s+=arr.A[i];

    return s;
}

//////// FLOAT FUNCTION ////////
float avg(struct Array arr)
{
    return (float)sum(arr)/arr.length;  //type casted as float - - i call the sum functon by passing array
}


//////    REVERSING ARRAY BY USING AUXILLARY ARRAY B   /////////////

void Reverse(struct Array *arr)
{
    int *B;            // Array B should of size equal to array A
    int i,j;
    
    B = new int[arr->length];  //create array B from heap by new operator length must be equal to arra y A
    for(i=arr->length-1,j=0;i>=0;i--,j++) // reverse copying all the elements from array A to arraY B
    B[j]=arr->A[i];

    for(i=0;i<arr->length;i++)
    arr->A[i]=B[i];
}

///// Reversing the array by exchanging first and last and corresponding elements
void Reverse2(struct Array *arr)
{
    int i, j;
    for(i= 0,j=arr->length-1; i<j; i++,j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

//////// INSERT ELEMENT IN A SORTED POSITION 
void insertSort(struct Array *arr, int x)
{
    int i=arr->length-1;
    if(arr->length == arr->size)
        return;
    while(i >= 0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr-> length++;
}

/// CHECK WHETHER ARRAY IS  SORTED OR NOT
int isSorted(struct Array arr)
{
    for(int i=0;i<arr.length-1; i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }

    return 1;
}

////// not working correctly
void Rearrange(struct Array *arr)
{
    int i, j;
    i=0; 
    j=arr->length-1;

    while(i<j)
    {
        while(arr->A[i]<0)i++;
        while(arr->A[i]>=0)j--;
        if(i<j)swap(&arr->A[i], & arr->A[j]);
    }

}


/// /// MERGING TWO ARRAYS
struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    if(arr1->A[i]<arr2->A[j])
        arr3->A[k++]=arr1->A[i++];
    else
        arr3->A[k++]=arr2->A[j++];
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}


//////////  UNION FOR SORTED ARRAYS //////
// union for sorted array is same as merging
struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
             arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
             arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3-> A[k++] = arr1 ->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j]; 
    arr3->length =k;
    arr3->size = 10;

    return arr3;
}

////////// INTERSECTION OF Two sorted sets ///////
struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if(arr1 ->A[i] == arr2 -> A[j])
        {
            arr3 -> A[k++] = arr1 -> A[i++];
            j++;
        }
    }
     
    arr3->length =k;
    arr3->size = 10;

    return arr3;
}

///////  DIFFERENCE OF TWO SORTED ARRAYS ////
struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
             arr3->A[k++]=arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++] = arr1->A[i];
    
    arr3->length =k;
    arr3->size = 10;

    return arr3;
}

//SET MEMBERSHIP FUNCTON //// ---- it is same as search
int membership(struct Array arr,int key)//we are not passing by address because we are not modifying array
{
    for(int i =0; i<arr.length; i++)  //in call by value we use dot . and in call by address we use arrow ->
    {
        if(key == arr.A[i])
            return i;
    }
    return -1;
}


int main()
{
    int ch;
    int x, index;
    int l;
    struct Array arr1;  //struct type variable
    cout<<"Enter size of an array: ";
    cin>>arr1.size;
    arr1.length = 0;
    arr1.A = new int[arr1.size];  //we create array in heap

    cout<<"Enter length of array  \n";
    cin>>l;

    cout<<"Enter all elements \n";
    for(int i=0; i<l; i++)
        cin>>arr1.A[i];
    arr1.length=l;


    do                      // use loop so this menu should be repeatedly appear
    {
        cout << "\n\n\n Menu\n";
        cout << "1.  Display\n";
        cout << "2.  Append\n";
        cout << "3.  Insert\n";
        cout << "4.  Delete\n";
        cout << "5.  Linear Search\n";
        cout << "6.  Binary Search\n";
        cout << "7.  Get\n";
        cout << "8.  Set\n";
        cout << "9.  Maximum\n";
        cout << "10.  Minimum\n";
        cout << "11.  Sum\n";
        cout << "12.  Average\n";
        cout << "13.  Reverse\n";
        cout << "14.  insertSort (Insert in sorted array)\n";
        cout << "15.  isSorted (is array sorted or not)\n";
        cout << "16.  Merge\n";
        cout << "17.  Union\n";
        cout << "18.  Intersection\n";
        cout << "19.  Difference\n";
        cout << "20.  membership ( same as search )\n";
        cout << "21.  Exit\n";

        cout << "Enter  your choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            display(arr1);
            break;
        case 2:
            cout<<"Enter an element ";
            cin>>x;
            append(&arr1,10); 
            break;
        case 3:
            cout << "Enter an element and index ";
            cin >> x, index;
            insert(&arr1, index, x);
            break;   
        case 4:
            cout<<"Enter index ";
            cin>>index;
            x=Delete(&arr1,index);
            cout<<"Deleted Element is \n"<<x;
            break;      
        case 5:
            cout<<"Enter element to search ";
            cin>>x;
            index=linearsearch(arr1,x);
            cout<<"Element index "<<index;
            break;
        case 6:
            cout<<"Enter element to search ";
            cin>>x;
            index=binarySearch(arr1,x);
            cout<<"Element index "<<index;
            break;     
        case 7:
            cout<<"Enter index ";
            cin>>index;
            x =  get(arr1,index);
            cout<<"value at the given index is : "<<x;
            break;
        case 8:
            cout << "Enter an element and index ";
            cin >> x;
            cin>>index;
            set(&arr1, index, x);
            display(arr1);
            break;
        case 9:
            cout<<"Maximum is \n"<<Max(arr1);
            break;
        case 10:
            cout<<"Minimum is \n"<<Min(arr1);
            break;
        case 11:
            cout<<"Sum is  :  "<<sum(arr1);
            break;
        case 12:
            cout<<"Average is : "<<avg(arr1);
            break;
            
        case 13:
            Reverse(&arr1);
            display(arr1);
            break;
        case 14:
            cout<<"Enter an element ";
            cin>>x;
            insertSort(&arr1, x);
            display(arr1);
            break;
        case 15:
            cout<<isSorted(arr1);
            cout<<"\n 0 : unsorted , 1 : sorted \n";
            break;
        case 16:
        //    arr3 = Merge(&arr1, &arr2);
            break;
        case 17:
        //    arr3 = Union(&arr1, &arr2);
            break;
        case 18:
        //    arr3 = Intersection(&arr1, &arr2);
            break;
        case 19:
        //    arr3 = Difference(&arr1, &arr2);
            break;
        case 20:
            cout<<"Enter an element \n";
            cin>>x;
            cout<<" element is present at index "<<membership(arr1,x);
            break;
        }
    }while (ch<21);
        return 0;
}