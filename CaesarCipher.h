#pragma once
#include "Cipher.h"
class CaesarCipher : public Cipher
{
	int step;
public:
	CaesarCipher(string, int);
	string encrypts() override;
	string decodes() override;

};

