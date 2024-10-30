#include <iostream>
#include "Bibas_Kandel_Cipher.h"
#include <ctype.h>
#include <string>
using namespace std;

string Cipher::GetPlainText()
{
    return plaintext;
}

string Cipher::GetCipherText()
{
    return ciphertext;
}

int Cipher::GetKey()
{
    return Key;
}

void Cipher::SetKey(int KEY)
{
    if (KEY != 0)
    {
        Key = KEY;
    }
}

void Cipher::ChangeText(string text, int KEY, bool is_encoded)
{

    SetKey(KEY);
    if (is_encoded)
    {
        this->ciphertext = text;
    }
    else
    {
        this->plaintext = text;
    }
}

string Cipher::Encode(string plaintext, int Key)
{

    int size = plaintext.length();
    bool upper = false;
    string result;
    for (int i = 0; i <= size - 1; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            upper = isupper(c);
            c = EncodeChar(c, Key);
            result += c;
        }
        else
        {
            result += c;
        }
    }

    return result;
}

string Cipher::Decode(string ciphertext, int Key)
{

    int size = ciphertext.length();
    bool upper = false;
    string result;
    for (int i = 0; i <= size - 1; i++)
    {
        char c = ciphertext[i];

        if (isalpha(c))
        {
            upper = isupper(c);
            c = DecodeChar(c, Key);

            result += c;
        }
        else
        {
            result += c;
        }
    }

    return result;
}

char Cipher::EncodeChar(char c, int k)
{
    bool upper = isupper(c);
    int indx = FindChar(c);
    if (indx + k >= 0)
    {

        indx = (indx + k) % 26;
    }
    else
    {

        indx = (26 + indx + k) % 26;
    }
    if (upper)
    {
        indx = indx + 65;
    }
    else
    {
        indx = indx + 97;
    }

    c = char(indx);

    return c;
}

char Cipher::DecodeChar(char c, int k)
{
    bool upper = isupper(c);
    int indx = FindChar(c);
    if (indx - k >= 0)
    {

        indx = (indx - k) % 26;
    }
    else
    {

        indx = (26 + indx - k) % 26;
    }
    if (upper)
    {
        indx = indx + 65;
    }
    else
    {
        indx = indx + 97;
    }

    c = char(indx);
    return c;
}

int Cipher::FindChar(char c)
{
    int indx = 0;
    if (isupper(c))
    {
        indx = int(c) - 65;
    }
    else if (islower(c))
    {
        indx = int(c) - 97;
    }

    return indx;
}

int main()
{

    int shift_key;
    string Text;
    bool is_encoded;
    int choice;
    // Cipher my_obj;
    do
    {
        cout << "Enter 1 to Encode and 2 to Decode and 3 to exit:";
        cin >> choice;
        cin.get();

        if (choice == 1)
        {
            cout << "Enter your plain text: ";
            getline(cin, Text);
            cout << "Enter your shift_key: ";
            cin >> shift_key;
            is_encoded = false;
            Cipher my_obj(Text, shift_key, is_encoded);
            cout << my_obj.GetCipherText();
        }
        else if (choice == 2)
        {
            cout << "Enter your encoded text: ";
            getline(cin, Text);
            cout << "Enter your shift_key: ";
            cin >> shift_key;
            is_encoded = true;
            Cipher my_obj(Text, shift_key, is_encoded);
        }
    } while (choice != 3);

    return 0;
}