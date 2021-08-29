#include <iostream>

using namespace std;

void merge(int A[], int B[], int sizeA, int sizeB)

{
int i = 0;

int j = 0;

int used = sizeA;

while(i < sizeA && j < sizeB)


{

if(A[i] < B[j])

{

for(int k= used- 1 ; k> i; k--)

{

A[k + 1] = A[k];

}

 A[i + 1] = B[j];

j++;

 used++;

}else

{

i++;

}

}

}

int main()
{
    int A[10] = {1,2,6,4,9};
    int B[5] = {3,5,7,8,10};
    merge(A,B,10,5);
    for(int i = 0; i < 10; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}