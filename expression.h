#pragma once
#include "INode.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

class substring {
public:
  virtual void print() const = 0;
  virtual ~substring() {}
};

INode *buildTree(std::string &expr, size_t &pos);
int findTopLevelOperator(const std::string &expr,
                         const std::unordered_map<char, int> &precedence);