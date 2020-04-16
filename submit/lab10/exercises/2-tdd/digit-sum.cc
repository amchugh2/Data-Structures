#include <cctype>

#include "digit-sum.hh"
#include <cctype>
#include <string>
#include <iostream>

int
digitSum(const char* str)
{
	int acc = 0;
	bool wantDigit = true;

	//const char* p = &str[0];

	for (const char* p = &str[0]; p; ++p){
		int c = *str;
		if(isdigit(c)){
			if(wantDigit){
		       	acc += c - '0';
			wantDigit = false;
			}
		else{
			break;
			}
		}
		else if (c == "+"){
			if (wantDigit) break;
			wantDigit = true;
		}
		else if(isspace(c)){
			continue;
		}
		else{
			break;
		}
	}
	return acc;
}
 
