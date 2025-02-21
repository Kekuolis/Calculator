#pragma once
#include <algorithm>
#include <iostream>
#include <string>

class fill {
private:
  std::string expr;

  bool is_number(const std::string &s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) {
                           return !std::isdigit(c);
                         }) == s.end();
  }
public:
  void setter(std::string exprSet) { expr = exprSet; }

  std::string replace() {
    std::string tmp;
    for (int i = 0; i < expr.length(); i++) {
      if (int(expr[i] > 64 && int(expr[i]) < 91) ||
          int(expr[i] > 97 && int(expr[i]) < 122)) {
        std::cout << "Please fill in the number " << expr[i] << " = ";
        std::cin >> tmp;
        while (!is_number(tmp)) {
          std::cout << "Please fill in the number " << expr[i] << " = ";
          std::cin >> tmp;
        }
        expr.replace(i, 1, tmp);
        // Adjust index if the inserted string has more than one character
        i += tmp.length() - 1;
      }
    }
    return expr;
  }
};