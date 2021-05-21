#include <iostream>
#include <string>
#include <stack>

using namespace std;

void InfixtoPrefix();
void PrefixToInfix();

int main()
{
  char input;
  char temp;
  std::cout << "enter 1 to convert infix to  prefix and 2 to convert prefix to infix or anything else to exit" << endl;
  cin.get(input);
  cin.get(temp);
  input -= 48;
  while (input == 1 || input == 2)
  {
    if(input == 1)
    {
      std::cout << "enter your equation: " << endl;
      InfixtoPrefix();
    }else if( input == 2)
    {
      std::cout << "enter your equation: " << endl;
      PrefixToInfix();
    }
    std::cout << "enter 1 to convert infix to  prefix and 2 to convert prefix to infix or anything else to exit" << endl;
    cin.get(temp);
    cin.get(input);
    cin.get(temp);
    input -= 48;
  }
  std::cout << "exting." << endl;
  return 0;
}

void InfixtoPrefix()
{
  char temp;
  stack<char> operations;
  stack<char> input;
  stack<char> output;
  while(cin.peek() != '\n')
  {
    cin.get(temp);
    input.push(temp);
  }
  do
  {
    if(input.top() == ')')
    {
     temp = input.top();
     input.pop();
     operations.push(temp);
    }else if ((input.top() >= 48 && input.top() <= 57) || (input.top() >= 65 && input.top() <= 90) || (input.top() >= 97 && input.top() <= 122) || input.top() == ' ')
    {
      temp = input.top();
      input.pop();
      output.push(temp);
    }else if(input.top() == '+' || input.top() == '-' || input.top() == '/' || input.top() == '*')
    {
      temp = input.top();
      input.pop();
      operations.push(temp);
    }else
    {
      temp = operations.top();
      input.pop();
      output.push(operations.top());
      operations.pop();
      operations.pop();
    }
  }while(!(input.empty()));
  std::cout << "the converted equation is: " << endl;
  while(!(output.empty()))
  {
    std::cout << output.top();
    output.pop();
  }
  std::cout << endl;
}
void PrefixToInfix()
{
  stack<char> input;
  stack<char> operations;
  stack<string> operands;
  string stemp = "";
  char temp;
  int i = 0;
  //cin.get(temp);
  while(cin.peek() != '\n')
  {
    cin.get(temp);
    input.push(temp);
  }
  std::cout << "the converted equation is: " << endl;
  while(!(input.empty()))
  {
    if(input.top() == '+' || input.top()  == '-' || input.top()  == '*' || input.top()  == '/')
    {
      stemp = "(" + operands.top();
      operands.pop();
      stemp.push_back(input.top());
      stemp = stemp + operands.top() + ")";
      input.pop();
      operands.pop();
      operands.push(stemp);
      stemp = "";
    }else if((input.top()  >= 48 && input.top()  <= 57) || (input.top()  >= 65 && input.top()  <= 90) || (input.top()  >= 97 && input.top()  <= 122))
    {
       string s = "";
       s.push_back(input.top());
      operands.push(s);
      input.pop();
    }
  }
  std::cout << operands.top() << endl;
  //cout << operands.size() << endl;
}