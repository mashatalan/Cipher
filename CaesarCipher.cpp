#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(string text, int step) : Cipher(text), step{step}{}

string CaesarCipher::encrypts()
{
	string encryptedText = text;
	for (char& ch : encryptedText)
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch + step;
			if (ch > 'Z')
			{
				ch = ch - 26;
			}
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			ch = ch + step;
			if (ch > 'z')
			{
				ch = ch - 26;
			}
		}
	}
	text = encryptedText;
	return encryptedText;
}

string CaesarCipher::decodes()
{
	string decodesText = text;
	for (char& ch: decodesText)
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch - step;
			if (ch < 'A')
			{
				ch = ch + 26;
			}
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			ch = ch - step;
			if (ch < 'a')
			{
				ch = ch + 26;
			}
		}
	}
	return decodesText;
}
