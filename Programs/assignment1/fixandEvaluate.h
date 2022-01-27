#include "queueType.h"
#include "stackType.h"
#include "token.h"
#include <sstream>
#include <iostream>
#include<string>


queueType<Token> convertInfixToPostfix(queueType<Token> q,stackType<Token> s, string infix)
{
    string postFix;

    for(int i=0;i<infix.size();i++)
    {
        Token t=Token(infix[i]);
        if(isdigit(infix[i]))
        {
            double ct=infix[i];
            t=Token(ct-48);
        }
        if(t.IsOperand())
        {
            q.addQueue(t);  
        }
        else if(t.IsLeftParen())
        {
           s.push(t);
        }
        else if(t.IsRightParen())
        {
           while(!s.top().IsLeftParen()&&(!s.isEmptyStack()))
           {
             q.addQueue(s.top());
             s.pop();
           }
           if(s.top().IsLeftParen())
           {
               s.pop();
           }
        }
        else if(t.IsOperator())
        {
           if(s.isEmptyStack())
           {
               s.push(t);
           }
           else
           {
               if(t.Precedence()>s.top().Precedence())
               {
                   s.push(t);
               }

               else if((t.Precedence()==s.top().Precedence())&&(infix[i]=='^'))
               {
                   s.push(t);
               }

               else
               {
                   while((!s.isEmptyStack())&&(t.Precedence()<=s.top().Precedence()))
                   {
                       q.addQueue(s.top());
                       s.pop();  
                   }
                   s.push(t);
               }
           }
        }
    }
    while (!s.isEmptyStack())
    {
       q.addQueue(s.top());
       s.pop();
    }
    return q;
};

Token evaluatePostfixexpression(string exp)
{
    stackType<Token> Postfixstack;

   
    for(int i=0;i<exp.length();i++)
    {
        Token t=Token(exp[i]);
        if(isdigit(exp[i]))
        {
            double temp=exp[i];
            t=temp;
            Postfixstack.push(exp[i]-48);
            
        }
        else
        {
            Token val1=Postfixstack.top();
            Postfixstack.pop();
            Token val2=Postfixstack.top();
            Postfixstack.pop();
           
            switch (exp[i])
            {
            case '+':Postfixstack.push(val1+val2);break;
            case '-':Postfixstack.push(val1-val2);break;
            case '*':Postfixstack.push(val1*val2);break;
            case '/':Postfixstack.push(val1/val2);break;
            case '^':Postfixstack.push(val1^val2);break;
            
            default:
                break;
            }

            

        }
        
    }
    return Postfixstack.top();
};

template <typename T>
std::string Myto_string( const T& value )
{
  std::ostringstream ss;
  ss << value;
  return ss.str();
};
