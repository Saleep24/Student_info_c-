/*
Name: Saleep Shrestha
NetID: w10167735
Program Description: This program implements a Caesar Cipher to encrypt and decrypt messages using a shift key.
*/

#include <iostream>
#include "Saleep_Shrestha_Cipher.h"
#include <ctype.h>
#include <limits>  // For input validation
using namespace std;

Cipher::Cipher(string text, int key, bool isEncoded) {
    SetShiftKey(key);
    if (isEncoded) {
        this->cipherText = text;
        this->plainText = Decode(text, key);  
    } else {
        this->plainText = text;
        this->cipherText = Encode(text, key);
    }
}


string Cipher::GetPlainText() {
    return plainText;
}

string Cipher::GetCipherText() {
    return cipherText;
}

int Cipher::GetShiftKey() {
    return shiftKey;
}


void Cipher::SetShiftKey(int key) {
    if (key != 0) {
        shiftKey = key;
        this->cipherText = Encode(this->plainText, shiftKey);
    }
}

void Cipher::ChangeText(string text, int key, bool isEncoded) {
    SetShiftKey(key);
    if (isEncoded) {
        this->cipherText = text;
    } else {
        this->plainText = text;
    }
}

string Cipher::Encode(string text, int key) {
    int size = text.length();
    string result;
    for (int i = 0; i < size; i++) {
        char c = text[i];
        if (isalpha(c)) {
            c = EncodeChar(c, key);
            result += c;
        } else {
            result += c;
        }
    }
    return result;
}

string Cipher::Decode(string text, int key) {
    int size = text.length();
    string result;
    for (int i = 0; i < size; i++) {
        char c = text[i];
        if (isalpha(c)) {
            c = DecodeChar(c, key);
            result += c;
        } else {
            result += c;
        }
    }
    return result;
}

char Cipher::EncodeChar(char c, int key) {
    bool isUpper = isupper(c);
    int index = FindCharIndex(c);
    index = (index + key) % 26;
    if (index < 0) {
        index += 26;
    }
    if (isUpper) {
        return char(index + 65);
    } else {
        return char(index + 97);
    }
}

char Cipher::DecodeChar(char c, int key) {
    bool isUpper = isupper(c);
    int index = FindCharIndex(c);
    index = (index - key) % 26;
    if (index < 0) {
        index += 26;
    }
    if (isUpper) {
        return char(index + 65);
    } else {
        return char(index + 97);
    }
}

int Cipher::FindCharIndex(char c) {
    if (isupper(c)) {
        return int(c) - 65;
    } else {
        return int(c) - 97;
    }
}

int main() {
    int shiftKey;
    string inputText;
    bool isEncoded;
    int option;

    do {
        cout << "Enter 1 to Encode, 2 to Decode, or 3 to Exit: ";
        cin >> option;

        while (cin.fail()) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Invalid input. Please enter a number (1 to Encode, 2 to Decode, or 3 to Exit): ";
            cin >> option;  
        }

        cin.ignore(); 

        if (option == 1) {
            cout << "Enter your plain text: ";
            getline(cin, inputText);
            cout << "Enter your shift key: ";
            cin >> shiftKey;

            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid shift key. Please enter an integer: ";
                cin >> shiftKey;
            }

            isEncoded = false;
            Cipher cipherObj(inputText, shiftKey, isEncoded);  
            cout << "Cipher Text: " << cipherObj.GetCipherText() << endl;

        } else if (option == 2) {
            cout << "Enter your encoded text: ";
            getline(cin, inputText);
            cout << "Enter your shift key: ";
            cin >> shiftKey;

            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid shift key. Please enter an integer: ";
                cin >> shiftKey;
            }

            isEncoded = true;
            Cipher cipherObj(inputText, shiftKey, isEncoded); 
            cout << "Decoded Text: " << cipherObj.GetPlainText() << endl;
        }

    } while (option != 3);

    return 0;
}
