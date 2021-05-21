#include <iostream>
//Question #1
#include <iostream>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
struct expressionTree {
    char value;
    expressionTree* left, * right;
};

expressionTree* newNode(int v)
{
    expressionTree* temp = new expressionTree;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};
void printInOrder(expressionTree* t)
{
    if (t != NULL) {
        printInOrder(t->left);
        std::cout << t->value;
        printInOrder(t->right);
    }
}
bool isOperator(char x) {
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
expressionTree* constructTree(string postfix)
{
    stack<expressionTree*> stacc;
    expressionTree* t, * t1, * t2;
    for (size_t i = 0; i < postfix.size(); i++)
    {
        // If operand push into stack
        if (!isOperator(postfix[i])) {
            t = newNode(postfix[i]);
            stacc.push(t);
        }
        //is operator below
        else {
            t = newNode(postfix[i]);
            t1 = stacc.top();
            stacc.pop();
            t2 = stacc.top();
            stacc.pop();
            //makes children
            t->right = t1;
            t->left = t2;
            stacc.push(t);
        }
    }

    t = stacc.top();
    stacc.pop();

    return t;
}
string preToPost(string prefix) {
    stack<string> stacc;
    int length = prefix.size();
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string op1 = stacc.top(); stacc.pop();
            string op2 = stacc.top(); stacc.pop();
            string temp = op1 + op2 + prefix[i];
            stacc.push(temp);
        }
        else {
            stacc.push(string(1, prefix[i]));
        }
    }
    return stacc.top();
}
int main()
{
    string prefix_expression = "-2+4*32";
    string postfix = preToPost(prefix_expression);
    expressionTree* r = constructTree(postfix);
    std::cout << "the expression in infix form:" << '\n';
    printInOrder(r);
    std::cout << std::endl;
    return 0;

}