#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int* random_int_list(int numElements)
{
    int* randomNums = new int[numElements];

    for (int i=0; i<numElements; i++)
    {
        randomNums[i] = rand()%1001;
    }

    return randomNums;

}

int main()
{
    srand(time(0));

    int arraySize;
    cout << "How many random numbers do you want? ";
    cin >> arraySize;

    int* myRandomArray = random_int_list(arraySize);

    cout << "Here are your random numbers: ";
    
    for (int i=0; i<arraySize; i++)
    {
        cout<<myRandomArray[i] << " ";
    }
    cout<<endl;

    delete[] myRandomArray;

    return 0;

}

