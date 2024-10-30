#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* random_int_list(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 1001;
    }
    return array;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* array = random_int_list(size);
    cout << "The array generated is: ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
    delete[] array;

    return 0;
}
