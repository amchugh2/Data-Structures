#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>

// NOTE: THIS PROGRAM ONLY WORKS IF ARGUMENTS ARE WITH DOUBLE QUOTES (" ") NOT SINGLE (' ')
using namespace std;

string concatenate(string &input){
	char bad[] = " , '";
	for(unsigned int i = 0; i < strlen(bad); ++i){
		input.erase( remove(input.begin(), input.end(), bad[i]), input.end());
		}
	return input;
}

bool is_delimiter(string &input){
	//char good[] = "(,),[,],{,},<,>";
	size_t found = input.find_first_not_of("()[]{}<>");
	if(found != string::npos){
		cout << "invalid delmiter" << endl;
		return false;
	}
	else{
		return true;
	}
}

bool is_balanced(string expr) { 
    stack<char> s; 
    char ch; 
  
    for (int i=0; i<expr.length(); i++){
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{' || expr[i] == '<'){
            s.push(expr[i]); 
            continue; 
        } 

        if (s.empty())
           return false; 
  
        switch (expr[i]){ 
	case ')':
            ch = s.top(); 
            s.pop(); 
            if (ch=='{' || ch=='[' || ch == '<') 
                return false; 
            break; 
  
        case '}': 
            ch = s.top(); 
            s.pop(); 
            if (ch=='(' || ch=='[' || ch == '<') 
                return false; 
            break; 
	
	case '>':
	    ch = s.top();
	    s.pop();
	    if(ch == '(' || ch == '[' || ch == '{')
		    return false;
	    break;
  
        case ']': 
            ch = s.top(); 
            s.pop(); 
            if (ch =='(' || ch == '{' || ch == '<') 
                return false; 
            break;
	}
    } 
    return (s.empty()); 
} 
  
 
//string expr = "([[]])";

int main(int argc, char *argv[]){
	string input = string (argv[1]);
	string str = concatenate(input);
	cout << str << endl;
	if(is_delimiter(str)){
		string expr = str;
		if(is_balanced(expr)){
			return 0;
		}
		else if(!is_balanced(expr)){
			cout << "unbalanced" << endl;
		}
	}
}
