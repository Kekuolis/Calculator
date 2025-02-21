#include "expression.h"
#include "INode.h"
#include <cctype>

int findTopLevelOperator(const std::string &expr,
                         const std::unordered_map<char, int> &precedence) {
  int minPrecedence = 100;
  int topOperatorLocation = -1;

  for (size_t i = 0; i < expr.length(); i++) {
    char c = expr[i];

    if (precedence.find(c) != precedence.end() &&
        precedence.at(c) <= minPrecedence) {
      minPrecedence = precedence.at(c);
      topOperatorLocation = i;
    }
  }

  return topOperatorLocation;
}
INode* buildTree(std::string &expr, size_t &pos) {
  INode* left = nullptr;
  if (expr[pos] == '(') {
      ++pos; 
      left = buildTree(expr, pos);
      if (expr[pos] != ')')
          throw std::invalid_argument("Missing closing parenthesis");
      ++pos; 
  } else {
      size_t start = pos;
      while (pos < expr.size() && (isdigit(expr[pos]) || expr[pos]=='.')) pos++;
      left = new Value(std::stod(expr.substr(start, pos - start)));
  }

  while (pos < expr.size() && std::string("+-*/").find(expr[pos]) != std::string::npos) {
      char op = expr[pos++];
      INode* right = buildTree(expr, pos);
      switch (op) {
          case '+': 
          left = new Sum(left, right); 
          break;
          case '-': 
          left = new Sub(left, right); 
          break;
          case '*': 
          left = new Multp(left, right); 
          break;
          case '/': 
          left = new Div(left, right); 
          break;
      }
  }
  return left;
}