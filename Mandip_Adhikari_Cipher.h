#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Cipher {
private:
    string plaintext;
    string ciphertext;
    int key;
    static const vector<char> alphabet;
    
    void Encode();
    void Decode();
    char EncodeChar(char c);
    char DecodeChar(char c);
    int FindChar(char c);

public:
    Cipher(const string& text, int shiftKey, bool isEncrypted);
    
    string GetPlainText() const { return plaintext; }
    string GetCipherText() const { return ciphertext; }
    int GetKey() const { return key; }
    
    void SetKey(int newKey);
    void ChangeText(const string& newText, int newKey, bool isEncrypted);
};


const vector<char> Cipher::alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

Cipher::Cipher(const string& text, int shiftKey, bool isEncrypted) : key(shiftKey) {
    if (key == 0) {
        cerr << "Key cannot be 0" << endl;
        exit(1);
    }
    
    if (isEncrypted) {
        ciphertext = text;
        Decode();
    } else {
        plaintext = text;
        Encode();
    }
}

void Cipher::SetKey(int newKey) {
    if (newKey == 0) {
        cerr << "Key cannot be 0" << endl;
        return; // Early return to avoid invalid key
    }
    key = newKey;
    Encode();
}

void Cipher::ChangeText(const string& newText, int newKey, bool isEncrypted) {
    if (newKey == 0) {
        cerr << "Key cannot be 0" << endl;
        return; 
    }
    key = newKey;
    
    if (isEncrypted) {
        ciphertext = newText;
        Decode();
    } else {
        plaintext = newText;
        Encode();
    }
}

void Cipher::Encode() {
    ciphertext.clear();
    for (char c : plaintext) {
        ciphertext += EncodeChar(c);
    }
}

void Cipher::Decode() {
    plaintext.clear();
    for (char c : ciphertext) {
        plaintext += DecodeChar(c);
    }
}

char Cipher::EncodeChar(char c) {
    if (!isalpha(c)) return c;
    
    int pos = FindChar(toupper(c));
    int newPos = (pos + key) % 26;
    if (newPos < 0) newPos += 26;
    
    char encodedChar = alphabet[newPos];
    return islower(c) ? tolower(encodedChar) : encodedChar;
}

char Cipher::DecodeChar(char c) {
    if (!isalpha(c)) return c;
    
    int pos = FindChar(toupper(c));
    int newPos = (pos - key) % 26;
    if (newPos < 0) newPos += 26;
    
    char decodedChar = alphabet[newPos];
    return islower(c) ? tolower(decodedChar) : decodedChar;
}

int Cipher::FindChar(char c) {
    for (int i = 0; i < 26; ++i) {
        if (alphabet[i] == c) return i;
    }
    return -1; // This should not happen if the input is valid
}