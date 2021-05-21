//This program takes in an infix and prefix expression from the user and returns the infix
//as a prefix and the prefix as an infix.

#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>

using namespace std;

//code fron parens.cxx
//checks if parentheses are balanced
bool is_balanced(const string& expression)
// Library facilities used: stack, string
{
    // Meaningful names for constants
    const char LEFT_PARENTHESIS = '(';
    const char RIGHT_PARENTHESIS = ')';

    stack<char> store;    // Stack to store the left parentheses as they occur
    string::size_type i;  // An index into the string
    char next;            // The next character from the string
    bool failed = false;  // Becomes true if a needed parenthesis is not found

    for (i = 0; !failed  &&  (i < expression.length( )); ++i)
    {
        next = expression[i];
        if (next == LEFT_PARENTHESIS)
            store.push(next);
        else if ((next == RIGHT_PARENTHESIS) && (!store.empty( )))
            store.pop( ); // Pops the corresponding left parenthesis.
        else if ((next == RIGHT_PARENTHESIS) && (store.empty( )))
            failed = true;
    }

    return (store.empty( ) && !failed);
}

//converts prefix expression to infix
string prefixToInfix(const string expression) {

  //check for balanced parentheses
  if(is_balanced(expression) == false) {
    return "Invalid expression. Check parentheses placement.";
  }

  stack<string> s; //declare stack
  //loops through expression and pops two values from the stack if current element
  //is an operator. If not, it will push the operand on the stack
  for(int i = expression.size() - 1; i >= 0; i--) {
    if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
      string var1 = s.top();
      s.pop();
      string var2 = s.top();
      s.pop();
      string temp = "("  + var1  + expression[i] + var2 + ")";
      s.push(temp);
    }
    else if(expression[i] == '(' || expression[i] == ')' ) {
      continue;
    }
    else {
      s.push(string(1, expression[i]));
    }
  }
  return s.top();
}

//converts infix expression to prefix
string infixToPrefix(const string expression) {
  stack<string> operands;
  stack<char> operators;

  //check if parentheses are balanced
  if(is_balanced(expression) == false) {
    return "Invalid expression. Check parentheses placement.";
  }

  //loops through expression and pops two values if current element is ")"
  //if not a ")", then push value onto stack if operand or skip to next element
  //if it is a "("
  for(int i = 0; i < expression.size(); i++) {
    if(expression[i] == ')') {
      string var1 = operands.top();
      operands.pop();
      string var2 = operands.top();
      operands.pop();
      char op = operators.top();
      operators.pop();
      string temp = string(1, op)  + var2 + var1;
      operands.push(temp);
    }
    else {
      //the two stacks are for operands and operators only, therefore skip "("
      if(expression[i] == '(') {
        continue;
      }
      if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
        operators.push(expression[i]);
      }
      else {
        operands.push(string(1, expression[i]));
      }
    }
  }
  return operands.top();
}

int main() {
  string strp;
  string stri;
  cout << "Enter a prefix expression with no spaces (EX: +*AB/CD): ";
  cin >> strp;

  cout << "Resulting Infix: ";
  cout << prefixToInfix(strp) << endl << endl;

  cout << "Enter an infix expression, fully parenthesized with no spaces (EX:((A*B)+(C/D))): ";
  cin >> stri;

  cout << "Resulting Prefix: ";
  cout << infixToPrefix(stri) << endl;

  return 0;
}
