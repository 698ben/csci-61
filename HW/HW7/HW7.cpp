#include <iostream>

using namespace std;

void insertionSort(int arr[], int size);
bool swap(int arr[], int a, int b);

int main()
{
    cout << "Insertion sort: " << endl;
    int num = 0;
    cout << "How many numbers do you want to sort" << endl;
    cin >> num;
    int arr[num];
    cout << "enter the numbers you want to sort separted by a space" << endl;
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i]; 
    }
    insertionSort(arr,num);
    cout << "the sorted out come is " << endl;
    for(int i = 0; i < num; i++)
    {
        std::cout << arr[i] << "  " << std::endl;
    }
    cout << "___________________________" << endl;
    cout << "Quick sort: " << endl;
    
    return 0;
}

void insertionSort(int arr[], int size)
{
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        j = i;
        while(swap(arr, j , j - 1  ) && j > 0)
        {
            j--;
        }
    }
}
bool swap(int arr[], int a, int b)
{
    int temp = 0;
    if(arr[a] < arr[b])
    {
        temp = arr[b];
        arr[b] = arr[a];
        arr[a] = temp;
        return true;
    }else
    {
        return false;
    }
}