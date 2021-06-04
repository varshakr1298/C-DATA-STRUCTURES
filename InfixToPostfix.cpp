//Application of stack: Infix to Postfix Expression

#include <iostream>
#include <stdio.h>
#include "Stack.h"
#include <string>
using namespace std;
//Calculating the priority of the operators
int Priority(char op){
	switch(op){
		case '(':{
			return 0;
			break;
		}
		case '+':{
			return 1;
			break;
		}
		case '-':{
			return 1;
			break;
		}
		case '*' :{
			return 2;
			break;
		}
		case '/' :{
			return 2;
			break;
		}
		case '%':{
			return 3;
			break;
		}
		case '^':{
			return 4;
			break;
		}
	}
}
//Function takes one input parameter(in) and one output parameter(post) and returns the status whether string conversion is possible or not!
bool InToPost(string in, string &post){
	
	Stack <char>stOperator(in.length());
	
	int j = 0;
	char topToken,poppedToken;
	for(int i=0;i<in.length();i++){
		char token = in[i];
		if((token == '+') || (token == '-') || (token == '*') || (token == '^') || (token == '/') || (token == '%')){
			
			stOperator.peep(topToken);
			while (!stOperator.isStackEmpty() && Priority(token)<=Priority(topToken)){
				
				stOperator.pop(poppedToken);
				post+=poppedToken;
				j++;
				stOperator.peep(topToken);
			}
			
			stOperator.push(token);
		}
		else if((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')){
			
			post+=token;
			j++;
		}else if(token == '('){
			
			stOperator.push(token);
		}else if(token == ')'){
			
			while(stOperator.pop(poppedToken) && poppedToken != '('){
				
				post+=poppedToken;
				j++;
			}
		}else{
			post+="";
			return false;
		}
	
	}
	while(stOperator.pop(poppedToken)){
		
		post+=poppedToken;
		j++;
	}
	if(stOperator.isStackEmpty()){
		return true;
	}else{
		return false;
	}
}
int main(){
	string input;
	string post;
	cout<<"Enter the infix expression that has to be converted into postfix: ";
	cin>>input;
	bool result = InToPost(input,post);
	if(result == true){
		cout<<"Infix to postix conversion successful! The result postfix expression: "<<post;
	}else{
		cout<<"Conversion unsuccessful!";
	}
}

