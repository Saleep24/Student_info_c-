#include <iostream>
#include <string>
#include <limits>

using namespace std;

class RomanNumeral{
private:
    int number;

public:
    RomanNumeral(int num){
        if(num>0 && num <=1000){
            number = num;
        }
        else{
            cout << "Error!!! Number must be between 1 and 1000." << endl;
            number = -1;
        }
    }

    string toRoman(){
        if (number == -1){
            return "";
        }
        string romanNumeral = "";
        int values[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int n = number;
        for (int i = 0; i<13; i++){
            while (n>= values[i])
            {
                romanNumeral += numerals[i];
                n -= values[i];
            }
        }
        return romanNumeral;
    }
};

int main(){
    int num;
    while(true){
        cout << "Enter a positive number greater than 0. Enter -1 to end the program: ";
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer." << endl;
            continue;
        }
        

        if (num == -1){
            break;
        } else if(num <= 0){
            cout << "Error phew! Only positive numbers are accepted!!!" << endl;
        } else{
            RomanNumeral roman(num);
            string romanStr = roman.toRoman();
            if (!romanStr.empty()){
                cout << "The number " <<"'"<<num<<"'"<< " is Roman Numeral " << "'"<< romanStr <<"'" << endl;
            }
        }
    }
    return 0;
}