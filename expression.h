#pragma once
#include "INode.h"
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class substring {
public:
  virtual void print() const = 0;
  virtual ~substring() {}
};

INode *buildTree(std::string &expr, size_t &pos);