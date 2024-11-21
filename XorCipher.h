#pragma once
#include "Cipher.h"
class XorCipher :public Cipher
{
	char key;
public:
	XorCipher(string, char);
	string encrypts()override;
	string decodes() override;
};

