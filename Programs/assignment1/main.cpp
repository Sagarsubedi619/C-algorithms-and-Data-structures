#include "queueType.h"
#include "stackType.h"
#include "token.h"
#include <sstream>
#include <iostream>
#include<string>
#include"fixandEvaluate.h"



 int main()
{
    string infix_exp;
    string postfix_exp;
    queueType<Token> resultQueue;
    stackType<Token> stack;
    queueType<Token> queue;
    cout<<"Please enter a Infix Expression: "<<endl;
    cin>>infix_exp;
    cout<<endl;
    cout<<"Infix Expression : "<<infix_exp<<endl;
    resultQueue=convertInfixToPostfix(queue,stack,infix_exp);
   while (!resultQueue.isEmptyQueue())
    {
        postfix_exp+=Myto_string(resultQueue.front());
        resultQueue.deleteQueue();
    }
    cout<<endl<<"Postfix expression: "<<postfix_exp<<endl;
    evaluatePostfixexpression(postfix_exp);
    cout<<endl<<"result: "<<evaluatePostfixexpression(postfix_exp)<<endl;
    return 0;

    
}