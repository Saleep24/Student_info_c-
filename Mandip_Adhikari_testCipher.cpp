/*
Name: Mandip Adhikari
NetID: w10167734
Program Description: This program tests the Cipher class implementation for the Caesar Cipher encryption and decryption.
*/

#include <iostream>
#include <cassert>
#include <string>
#include "Mandip_Adhikari_Cipher.h"

using namespace std;

void testCipher(const string& plaintext, int key) {
    cout << "\nTesting with the plaintext: \"" << plaintext << "\" and key: " << key << endl;
    Cipher cipher(plaintext, key, false);
    cout << "The encrypted text is: \"" << cipher.GetCipherText() << "\"" << endl;
    assert(cipher.GetPlainText() == plaintext);
    Cipher decipher(cipher.GetCipherText(), key, true);
    assert(decipher.GetPlainText() == plaintext);
    cout << "The decrypted text is: \"" << decipher.GetPlainText() << "\"" << endl;
    cout << "Test passed!" << endl;
}

void runUserCipher() {
    string userPlaintext;
    int userKey;
    cout << "Enter the plaintext you want to encrypt: ";
    getline(cin, userPlaintext);
    cout << "Enter the key for encryption (positive for right shift, negative for left shift): ";
    cin >> userKey;
    Cipher cipher(userPlaintext, userKey, false); 
    cout << "The encrypted text is: \"" << cipher.GetCipherText() << "\"" << endl;
    Cipher decipher(cipher.GetCipherText(), userKey, true);
    cout << "The decrypted text is: \"" << decipher.GetPlainText() << "\"" << endl;
};

int main(){
    char continueTesting = 'y';
    testCipher("The army will strike at 18:59. All troops prepare immediately!", -6);
    // Positive key test
    testCipher("Hello, World!", 3);
    // Larger positive key test
    testCipher("This is a test message for the Caesar Cipher", 15);
    // Test case 4: Negative key
    testCipher("Rice is often served in round bowls", -8);
    // Key larger than alphabet size
    testCipher("The quick brown fox jumps over the lazy dog", 30);
    cout << "\nAll tests passed successfully!" << endl;
    while (continueTesting == 'y' || continueTesting == 'Y') {
        cout << "\nDo you want to test your own cipher? (y/n): ";
        cin >> continueTesting;
        cin.ignore(); // ignores the newline after the character input
        if (continueTesting == 'y' || continueTesting == 'Y') {
            runUserCipher();
        } else {
            cout << "Exiting user test mode." << endl;
        }
    }

    cout << "You have existed the program sucessfully!" << endl;
    return 0;
}