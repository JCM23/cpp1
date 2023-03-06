// Converting an infix expression to postfix format
// Input with no spaces

#include <iostream>
#include <stack>

using namespace std;

/* empty, size, push(insert element), pop(remove element), top
Sample Stack
 nameofStack.empty(), nameofStack.size(), nameofStack.push(element), nameofStack.pop()*/

int precedence(char op)
{
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;
  return 0;
}

string InfixToPostfix(string infix) // infix to postfix
{
  stack<char> stack;
  string p = ""; // EMPTY postfix

  // for each symbol in I from left to right do
  for (int i = 0; i < infix.size(); i++)

  {
    // if the symbol is an operand then
    if (infix[i] >= 'A' && infix[i] <= 'Z')
    {
      p += infix[i]; // append to postfix
    }

    // else-If the symbol is an operator then
    else if (infix[i] == '^' || infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
    {
      while (!stack.empty() && precedence(stack.top()) >= precedence(infix[i]))
      {
        p += stack.top(); // append to postfix
        stack.pop();
      }
      stack.push(infix[i]);
    }

    // else-If the symbol is an opening (left) parenthesis then
    else if (infix[i] == '(')
    {
      stack.push(infix[i]);
    }

    // else-If the symbol is a closing (right) parenthesis then
    else if (infix[i] == ')')
    {
      while (!stack.empty() && stack.top() != '(')
      {
        p += stack.top(); // append to postfix
        stack.pop();
      }
      stack.pop();
    }
  }

  // Pop all operators from S and append to P
  while (!stack.empty())
  {
    p += stack.top();
    stack.pop();
  }

  cout << " Postfix expression is: " << p; // OUTPUT

  return p;
}

int main()
{
  string infix, postfix; // infix and postfix expression

  cout << " Enter an infix expression: "; // USER INPUT
  cin >> infix;
  postfix = InfixToPostfix(infix);

  return 0;
}
