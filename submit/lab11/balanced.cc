#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

string concatenate(string &input){
	char bad[] = " , '";
	for(unsigned int i = 0; i < strlen(bad); ++i){
		input.erase( remove(input.begin(), input.end(), bad[i]), input.end());
		}
	return input;
}

bool is_delimiter(string &input){
	char good[] = "(,),[,],{,}";
	size_t found = input.find_first_not_of("()[]{}");
	if(found != string::npos){
		cout << "invalid delmiter" << endl;
		return false;
	}
	else{
		return true;
	}
}


bool is_balanced(string str){
	stack<char> s;
	char ch;

	for(int i = 0; i < str.length(); i++){
		if(str[i] == "(" || str[i] == "[" || str[i] == "{"){
			s.push(str[i]);
			continue;
		}
		if(s.empty()){
			cout << "Please enter delimiters" << endl;
			return false;
		}

		switch(str[i]){
			case ')':
				ch = s.top();
				s.pop();
				if(ch == "{" || ch == "["){
					return false;
				}
				break;
			case '}':
				ch = s.top();
				s.pop();
				if(ch == "(" || ch == "["){
					return false;
				}
				break;
			case ']':
				ch = s.top();
				s.pop();
				if(ch == '(' || ch == '{'){
					return false;
				}
				break;
		}
	}
	return (s.empty());
}

bool isBalanced(string expr) { 
    stack<char> s; 
    char ch; 
  
    for (int i=0; i<expr.length(); i++) { //for each character in the expression, check conditions 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{') { //when it is opening bracket, push into stack
            s.push(expr[i]); 
            continue; 
        } 

        if (s.empty()) //stack cannot be empty as it is not opening bracket, there must be closing bracket
           return false; 
  
        switch (expr[i]){ 
        case ')': //for closing parenthesis, pop it and check for braces and square brackets
            ch = s.top(); 
            s.pop(); 
            if (ch=='{' || ch=='[') 
                return false; 
            break; 
  
        case '}': //for closing braces, pop it and check for parenthesis and square brackets
  
            ch = s.top(); 
            s.pop(); 
            if (ch=='(' || ch=='[') 
                return false; 
            break; 
  
        case ']': //for closing square bracket, pop it and check for braces and parenthesis
  
            ch = s.top(); 
            s.pop(); 
            if (ch =='(' || ch == '{') 
                return false; 
            break; 
        } 
    } 
    return (s.empty()); //when stack is empty, return true
} 
  
 
main() { 
    string expr = "([[]])";
  
    if (isBalanced(expr)) 
        cout << "Balanced"; 
    else
        cout << "Not Balanced"; 
}


int main(int argc, char *argv[]){
	string input = string (argv[1]);
	string str = concatenate(input);
	if(is_delimiter(str)){
		cout << "true" << endl;
	}
}
