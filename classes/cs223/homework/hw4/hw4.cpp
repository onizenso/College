#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

#ifndef ELEMTYPE
#define ELEMTYPE double
#endif

#ifndef CAP 
#define CAP 100
#endif


typedef struct __arrayStack__ {
    ELEMTYPE elems[CAP];
    int count;
} arrayStack;


void initStack(arrayStack*);
bool empty(arrayStack*);
bool full(arrayStack*);
bool push(arrayStack*, ELEMTYPE);
bool pop(arrayStack*);
ELEMTYPE top(arrayStack*);

void evaluatePostfix(char *);

int main(){
    bool stop = false;
    int k = 0;

    char ans[25] = {0};
    char post[256] = {0};
    
    do{
        cout<<"Enter a postfix expression for me to evaluate: "<<endl;
        cin.getline(post, 256);

        evaluatePostfix(post);

        cout<< "Do you want to evaluate another expression?  " << endl;
        cin.getline(ans, 25);
                
        if(cin.gcount() > 4 || cin.gcount() < 1){
            cout<< "You fail at life." << endl;
            cin.clear();
            cin.ignore(98, '\n');
            return 0;
        }
        else{
            for(int c = 0; c < strlen(ans); c++){
                if(isalpha(ans[c])) 
                    ans[c] = tolower(ans[c]);
                else
                    cout<< "Invalid input guy, try again." << endl;     
            }
        
            if(ans[0] == 'y'){
                stop = false;
            }
            else{
                stop = true;
                break;
            }
        }
    }while(!stop);
    return 0;
}

void initStack(arrayStack *stack){
    stack->count = 0;
    
    for(int i = 0; i < CAP; i++)
        stack->elems[i] = 0;
    return;
}

bool empty(arrayStack *stack){
    return stack->count == 0;
}

bool full(arrayStack *stack){
    return stack->count == CAP;
}

bool push(arrayStack *stack, ELEMTYPE input){
    if(full(stack)){
        cout<<"Stack is full, remove some elements." << endl;
        return false;
    }
    
    stack->elems[stack->count] = input;
    stack->count++;
    cout<< "Succesfully added element."<< endl;
    
    return true;
}

bool pop(arrayStack *stack){
    if(empty(stack)){
        cout<<"Stack is empty, no elements to remove" << endl;
        return false;
    }

    stack->count--;
    stack->elems[stack->count] = 0;
    cout<<"Successfully removed element from stack"<<endl;

    return true;
}

ELEMTYPE top(arrayStack *stack){
    if(empty(stack))
        return 0;
    return stack->elems[stack->count-1];
}

bool isInteger(char *str){
    int len = strlen(str);

    for(int i=0; i < len; i++){
        if(i == 0 && (str[i] == '-' || str[i] == '+' || 
                    str[i] == '/' || str[i] == '*' ))
            if(len == 1) return false;
        else if(!isdigit(str[i]))
            return false;
    }
    return true;
}

bool isDouble(char *str){
    int dots = 0;
    int len = strlen(str);
    
    for(int i = 0; i < len; i++){
        if(str[i] == '.'){
            dots++;
            if(dots>1) return false;
        }
        else if(i == 0 && (str[i] == '-' || str[i] == '+' || 
                    str[i] == '/' || str[i] == '*'))
            if(len == 1) return false;
        else if(!isdigit(str[i]))
            return false;
        return true;
    }
}

bool isOperator(char *str){
    int len = strlen(str);

    if(len > 1) return false;
    if(str[0]=='+' || str[0]=='-' || str[0]=='*' || str[0]=='/' || str[0]=='%')
        return true;
    return false;
}

void evaluatePostfix(char *str){
    double result = 0;
    int count = 0;
    int slot = 0;
    char **tokens;
   
    arrayStack *stack;
    initStack(stack);

    int len = strlen(str);
    
    for(int i = 0; i < len; i++){
        if(isspace(str[i])){
            count++;
            while(isspace(str[++i]));
            i--;
        }
    }

    try{ 
        tokens = new char * [count+1];
    }catch(bad_alloc){ 
        tokens = NULL; 
    }

    int i = 0;

    while(i < len){
        if(!isspace(str[i])){
            tokens[slot++] = &(str[i]);
            while(!isspace(str[++i]) && i < len);
            str[i++] = '\0';
        }
        else
            str[i++] = '\0';
    }

    for(int i = 0; i <= count; i++){
        if(isInteger(tokens[i])){
            int num = atoi(tokens[i]);
            push(stack, num);
        }
        else if(isDouble(tokens[i])){
            double dnum = atof(tokens[i]);
            push(stack, dnum);
        }
        else if(isOperator(tokens[i])){
            char op = tokens[i][0];
            double operand2 = top(stack);
            if(!pop(stack)){
                cout<< "Invalid number of operands." <<endl;
                delete [] tokens;
                return;
            }
            
            double operand1 = top(stack);
            
            if(!pop(stack)){
                cout<< "Invalid number of operands." <<endl;
                delete [] tokens;
                return;
            }
            
            if(op == '+')
                result = operand1 + operand2;

            if(op == '-')
                result = operand1 - operand2;

            if(op == '*')
                result = operand1 * operand2;

            if(op == '/')
                result = operand1 / operand2;

            push(stack, result);
        }
        else{
            cout<< "Invalid character in expression" << endl;
            delete [] tokens;
            return;
        }
    }

    if(!empty(stack)){
        result = top(stack);
        pop(stack);
        if(empty(stack))
            cout<< "The result of your expression is " << result << endl;
        else
            cout<< "Invalid expression." << endl;
    }
    else
        cout<< "Invalid expression." << endl;
}

