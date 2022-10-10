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
string hexToBin(string);
long long hexToDec(string);
int binToDec(string);
string toString(int);
LPWSTR ConvertString(const std::string& instr);

#endif // !_FUNCTION_

