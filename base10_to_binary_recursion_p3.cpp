#include <iostream>

using namespace std;

void decimalToBinary(int decimal, bool iszero = true);

int main()
{
    int num;
    cout << "Enter a decimal number please: ";
    cin >> num;

    decimalToBinary(num);
    cout << endl;

    return 0;
}


void decimalToBinary(int decimal, bool isZero) {
    if (decimal == 0 && isZero) {
        cout << "0";
        return;
    }

    if (decimal == 0) {
        return;
    }

    int remainder = decimal % 2;
    int quotient = decimal / 2;

    decimalToBinary(quotient, false);

    if (remainder == 0) {
        cout << "0";
    } else {
        cout << "1";
    }
}