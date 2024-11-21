#pragma once
#include "Cipher.h"
class XorCipher :public Cipher
{
	char key;
public:
	string encrypts()override;
	string decodes() override;
};

