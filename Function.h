#pragma once
#ifndef _FUNCTION_
#define _FUNCTION_

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

int readByte(LPCWSTR, LARGE_INTEGER, BYTE*, int);
string toHex(int);
string hexToASCII(string);

#endif // !_FUNCTION_

