#ifndef SALEEP_SHRESTHA_CIPHER_H
#define SALEEP_SHRESTHA_CIPHER_H

#include <string>
using namespace std;

class Cipher {
private:
    string plainText;
    string cipherText;
    int shiftKey;

public:
    Cipher() : plainText(), cipherText(), shiftKey() {}  
    Cipher(string text, int key, bool isEncoded); 

    string GetPlainText();
    string GetCipherText();
    int GetShiftKey();

    void SetShiftKey(int key);
    void ChangeText(string text, int key, bool isEncoded);

    string Encode(string text, int key);
    string Decode(string text, int key);
    char EncodeChar(char c, int key);
    char DecodeChar(char c, int key);
    int FindCharIndex(char c);
};

#endif  // SALEEP_SHRESTHA_CIPHER_H
