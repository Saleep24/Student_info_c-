#include <string>
using namespace std;
class Cipher
{

private:
    string plaintext;
    string ciphertext;
    int Key;

    string Encode(string ciphertext, int Key);
    string Decode(string plaintext, int Key);
    int FindChar(char c);
    char EncodeChar(char c, int Key);
    char DecodeChar(char c, int Key);

public:
    Cipher() : plaintext(), ciphertext(), Key() {}
    Cipher(string text, int KEY, bool encoded)
    {

        ChangeText(text, KEY, encoded);
        if (encoded)
        {
            this->plaintext = Decode(ciphertext, Key);
            cout << "Your Encoded Text is : " << GetPlainText() << endl
                 << endl;
        }
        else
        {
            ciphertext = Encode(plaintext, Key);
            cout << "Your Encoded Text is : " << GetCipherText() << endl
                 << endl;
        }
    }

    void ChangeText(string text, int KEY, bool is_encoded);
    string GetPlainText();
    string GetCipherText();
    int GetKey();
    void SetKey(int KEY);
    // // vector<char> upper{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // // vector<char> lower{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // vector<char> upper;
    // vector<char> lower;
};