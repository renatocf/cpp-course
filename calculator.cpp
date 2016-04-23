#include <iostream>
#include <stdexcept>
#include <sstream>

struct Expression {
  int lhs;
  char op;
  int rhs;
};

template<typename T>
T read() {
  T variable_read;
  std::cin >> variable_read;
  return variable_read;
}

struct Expression readExpression() {
  return { read<int>(), read<char>(), read<int>() };
}

std::string printExpression(struct Expression exp) {
  std::ostringstream formatted_expression;
  formatted_expression << exp.lhs << " " << exp.op << " " << exp.rhs;
  return formatted_expression.str();
}

int evaluateExpression(struct Expression exp) {
  switch (exp.op) {
    case '+': return exp.lhs + exp.rhs;
    case '-': return exp.lhs - exp.rhs;
    case '*': return exp.lhs * exp.rhs;
    case '/': return exp.lhs / exp.rhs;
    default:
      std::ostringstream error_message;
      error_message << "Operator " << exp.op << " is unknown";
      throw std::invalid_argument(error_message.str());
  }
}

int main() {
  while (true) {
    std::cout << "> ";

    auto exp = readExpression();

    std::cout << "The result of " << printExpression(exp)
              << " is " << evaluateExpression(exp) << std::endl;
  }

  return 0;
}
