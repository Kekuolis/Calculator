#include "expression.h"
#include "INode.h"
#include <cctype>

// Parses numbers and parenthesized expressions
INode *parseFactor(std::string &expr, size_t &pos) {
  if (expr[pos] == '(') {
    ++pos;
    INode *node = buildTree(expr, pos);
    if (expr[pos] != ')') {
      throw std::invalid_argument("Missing closing parenthesis");
    }
    ++pos;
    return node;
  } else {
    size_t start = pos;
    while (pos < expr.size() && (isdigit(expr[pos]) || expr[pos] == '.')) {
      ++pos;
    }
    return new Value(std::stod(expr.substr(start, pos - start)));
  }
}

// Parses multiplication and division
INode *parseTerm(std::string &expr, size_t &pos) {
  INode *node = parseFactor(expr, pos);
  while (pos < expr.size() && (expr[pos] == '*' || expr[pos] == '/')) {
    char op = expr[pos++];
    INode *right = parseFactor(expr, pos);
    if (op == '*') {
      node = new Multp(node, right);
    } else { // /
      node = new Div(node, right);
    }
  }
  return node;
}

// Parses addition and subtraction
INode *buildTree(std::string &expr, size_t &pos) {
  INode *node = parseTerm(expr, pos);
  while (pos < expr.size() && (expr[pos] == '+' || expr[pos] == '-')) {
    char op = expr[pos++];
    INode *right = parseTerm(expr, pos);
    if (op == '+') {
      node = new Sum(node, right);
    } else { // -
      node = new Sub(node, right);
    }
  }
  return node;
}