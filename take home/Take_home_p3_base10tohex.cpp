#include <iostream>

using namespace std;

void decimalToHexadecimal(int decimal, bool isZero = true);

int main()
{
    int num;
    cout << "Enter a decimal number please: ";
    cin >> num;

    decimalToHexadecimal(num);
    cout << endl;  

    return 0;
}

void decimalToHexadecimal(int decimal, bool isZero) {
    if (decimal == 0 && isZero) {
        cout << "0";
        return;
    }

    if (decimal == 0) {
        return;
    }

    int remainder = decimal % 16;
    int quotient = decimal / 16;

    decimalToHexadecimal(quotient, false);

    if (remainder < 10) {
        cout << remainder;  
    } else {
        cout << char('A' + (remainder - 10));
    }
}
