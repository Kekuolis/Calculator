#pragma once
#include <iostream>
#include <stdexcept>

class INode {
public:
  virtual void print() const = 0;
  virtual double calc() const = 0;
  virtual ~INode() {}
};

class Value : public INode {
private:
  double value;

public:
  Value(double val) : value(val) {}

  void print() const override { std::cout << value; }
  double calc() const override { return value; }
};

class Sum : public INode {
private:
  INode *left, *right;

public:
  Sum(INode *l, INode *r) : left(l), right(r) {}

  void print() const override {
    std::cout << "(";
    left->print();
    std::cout << " + ";
    right->print();
    std::cout << ")";
  }

  double calc() const override { return left->calc() + right->calc(); }
};

class Multp : public INode {
private:
  INode *left, *right;

public:
  Multp(INode *l, INode *r) : left(l), right(r) {}

  void print() const override {
    std::cout << "(";
    left->print();
    std::cout << " * ";
    right->print();
    std::cout << ")";
  }

  double calc() const override { return left->calc() * right->calc(); }
};

class Sub : public INode {
private:
  INode *left, *right;

public:
  Sub(INode *l, INode *r) : left(l), right(r) {}

  void print() const override {
    std::cout << "(";
    left->print();
    std::cout << " - ";
    right->print();
    std::cout << ")";
  }

  double calc() const override { return left->calc() - right->calc(); }
};

class Div : public INode {
private:
  INode *left, *right;

public:
  Div(INode *l, INode *r) : left(l), right(r) {}

  void print() const override {
    std::cout << "(";
    left->print();
    std::cout << " / ";
    right->print();
    std::cout << ")";
  }

  double calc() const override {
    double denominator = right->calc();
    if (denominator == 0) {
      throw std::runtime_error("Division by zero error");
    }
    return left->calc() / denominator;
  }
};
