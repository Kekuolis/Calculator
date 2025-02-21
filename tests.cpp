#include <bits/types/error_t.h>
#include <cstdint>
#include <gtest/gtest.h>
#include "test.h"
#include "variable.h"
#include "INode.h"
#include "expression.h"


// Function to evaluate an expression string
double evaluateExpression(const std::string& input) {
    std::string processed;
    std::copy_if(input.begin(), input.end(), std::back_inserter(processed), [](char c) { return !isspace(c); });
  
    fill replaceVariables;
    replaceVariables.setter(processed);
    processed = replaceVariables.replace();
  
    size_t pos = 0;
    INode* tree = buildTree(processed, pos);
    
    double result = tree->calc();
    delete tree;
  
    return result;
  }

  
// Test case 1: Basic expression
TEST(ExpressionEvaluationTest, BasicExpression) {
    EXPECT_DOUBLE_EQ(evaluateExpression("4 + 5 + 6 * 9 + (9 + 8 / 7 * (2 * (3 + 2)))"), 83.428571428571431);
}

// Test case 2: Simple addition
TEST(ExpressionEvaluationTest, SimpleAddition) {
    EXPECT_DOUBLE_EQ(evaluateExpression("2 + 2"), 4);
}

// Test case 3: Multiplication precedence
TEST(ExpressionEvaluationTest, MultiplicationPrecedence) {
    EXPECT_DOUBLE_EQ(evaluateExpression("3 + 4 * 2"), 11);
}

// Test case 4: Parentheses precedence
TEST(ExpressionEvaluationTest, ParenthesesPrecedence) {
    EXPECT_DOUBLE_EQ(evaluateExpression("(3 + 4) * 2"), 14);
}

// Test case 4: Nested Parenthesies
TEST(ExpressionEvaluationTest, NestedParenthesies) {
    EXPECT_DOUBLE_EQ(evaluateExpression("(8 / 7 * (2 * (3 + 2)))"), 11.428571428571427);
}

// Test case 5: Division and floating point handling
TEST(ExpressionEvaluationTest, DivisionHandling) {
    EXPECT_DOUBLE_EQ(evaluateExpression("8 / 2"), 4);
}
// Test case 6: Division by zero
TEST(ExpressionEvaluationTest, DivisionZero) {
    EXPECT_THROW(evaluateExpression("8 / 0"), std::runtime_error);
}
// Test case 7: Division by zero
TEST(ExpressionEvaluationTest, Subtraction) {
    EXPECT_DOUBLE_EQ(evaluateExpression("8 - 10"), -2);
}


// Main function for running the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
