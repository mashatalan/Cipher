#include "XorCipher.h"

XorCipher::XorCipher(char key) : Cipher(text), key{key}{}

string XorCipher::encrypts()
{
    string encryptedText = text;
    for (char& ch: encryptedText)
    {
        ch = ch ^ key;
    }

    text = encryptedText;
    return encryptedText;
}

string XorCipher::decodes()
{
    string decodesText = text;
    for (char& ch : decodesText)
    {
        ch = ch ^ key;
    }
    return decodesText;
}
