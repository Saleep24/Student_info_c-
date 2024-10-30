#include <iostream>
#include <string>
#include <limits>
#include <cstdlib> //for modulus operation

using namespace std;

class RomanNumeral {
private:
    int number;

public:
    RomanNumeral(int num = 0) {
        if (num > 0 && num <= 2000) {
            number = num;
        } else {
            number = 0;
        }
    }

    void inputFromUser(const string& varName) {
        int num;
        cout << "Enter a positive number for " << varName << " (1-1000) only, please!: ";
        cin >> num;

        while (cin.fail() || num <= 0 || num > 1000) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input hehe! Please enter a valid number between 1 and 1000: ";
            cin >> num;
        }
        number = num;
    }

    int getNumber() const {
        return number;
    }

    string toRoman() const {
        if (number <= 0) return "";

        string romanNumeral = "";
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int n = number;
        for (int i = 0; i < 13; i++) {
            while (n >= values[i]) {
                romanNumeral += numerals[i];
                n -= values[i];
            }
        }
        return romanNumeral;
    }

    RomanNumeral operator+(const RomanNumeral& other) const {
        int sum = number + other.number;
        return RomanNumeral(sum);
    }

    RomanNumeral operator-(const RomanNumeral& other) const {
        int diff = abs(number - other.number);
        return RomanNumeral(diff);
    }
};

int main() {
    RomanNumeral n1, n2, n3;
    int choice;

    cout << "What would you like to do?\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "Please enter 1 or 2: ";
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "Invalid choice! Please enter 1 for addition or 2 for subtraction: ";
        cin >> choice;
    }

    n1.inputFromUser("n1");
    n2.inputFromUser("n2");

    if (choice == 1) {
        n3 = n1 + n2;
        if (n3.getNumber() != 0) {
            cout << "n1 + n2 = " << n3.getNumber() << " (" << n3.toRoman() << ")" << endl;
        }
    } else if (choice == 2) {
        n3 = n2 - n1;
        if (n3.getNumber() != 0) {
            cout << "n2 - n1 = " << n3.getNumber() << " (" << n3.toRoman() << ")" << endl;
        }
    }

    return 0;
}
