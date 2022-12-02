// To find the valid string is valid or not, there are two methods: 1 is simple method and 2 is using Regular Expression
#include <iostream>
using namespace std;

int validate(char *name);

int main()
{
    char *name = "Khan321";
    if(validate(name))
    {
        cout<<"Valid String";
    }
    else
        cout<<"Invalid String";
}

int validate(char *name)
{
    int i;
    for(i=0; name[i] != '\0'; name++)
    {
        if(!(name[i]>=65 && name[i]<=90)&&
        !(name[i]>=97 && name[i] <=122) &&
        !(name[i] >=48 && name[i] <= 57))
            return 0;
    }
        return 1;
}