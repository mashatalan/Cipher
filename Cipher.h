#pragma once
#include <iostream>
using namespace std;

class Cipher
{
protected:
	string text;
public:
	explicit Cipher(const string&);
	virtual ~Cipher() = default;

	virtual string encrypts() = 0;
	virtual string decodes() = 0;
};


