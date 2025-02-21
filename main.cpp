#include "INode.h"
#include "expression.h"
#include "variable.h"
#include <cstddef>
#include <type_traits>
#include <vector>

// 4 + 5 + 6 * 9 + (9 + 8 / 7 * (2 * (3 +2)))
int main(int argc, char *argv[]) {
  std::string expression, processed;

  if (argc == 1)
    std::getline(std::cin, expression);
  else
    expression = argv[1];
  std::copy_if(expression.begin(), expression.end(), std::back_inserter(processed), [](char c) { return !isspace(c); });
  fill *replaceVariables = new fill;
  replaceVariables->setter(processed);
  processed = replaceVariables->replace();

  size_t pos = 0;
  INode *tree = buildTree(processed, pos);

  tree->print();
  std::cout<<std::endl;
  std::cout << "Result: " << tree->calc() << std::endl;
  delete tree;
}