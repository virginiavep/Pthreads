#include <iostream>

using namespace std;

int main()
{
    //defines array of integers my_ints with a size of 4.
    int my_ints[4];
    //Populates my_ints with input data provided by the user
    cout << "Please enter 4 integers" << endl;
    for (int x = 0; x < 4; x++)
    {
        cin >> my_ints[x];
    }
    //Defines an array of pointers called my_ptrs of the same size as my_ints
    int *my_ptrs[4];
    //initializes my_ptrs to point to corresponding elements of my_ints
    cout << "my_ptrs inital values: " <<endl;
    for (int x = 0; x < 4; x++)
    {
        my_ptrs[x] = &my_ints[x];
        cout << *my_ptrs[x] << endl;
    }
    //Sorts the array my_ptrs so they point to values in ascending order
    int i, j, *temp;
    cout << "my_ptrs values after sorting: " <<endl;
    for (int i = 0; i < 4; i++)
    {
        for(j = (i+1); j<4; j++){
            if (*my_ptrs[i]> *my_ptrs[j]) //ascending order
            {
            temp = my_ptrs[i];
            my_ptrs[i] = my_ptrs[j];
            my_ptrs[j] = temp;
            }
        }
    //Traverse my_ptrs and print values being pointed to
        cout << *my_ptrs[i] <<endl;
    }
    return 0;
}
