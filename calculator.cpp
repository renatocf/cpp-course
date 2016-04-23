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

Expression readExpression() {
  return { read<int>(), read<char>(), read<int>() };
}

void reverseExpression(Expression& exp) {
  switch (exp.op) {
    case '+': exp.op = '-'; break;
    case '-': exp.op = '+'; break;
    case '*': exp.op = '/'; break;
    case '/': exp.op = '*'; break;
  }
}

std::string printExpression(const Expression& exp) {
  std::ostringstream formatted_expression;
  formatted_expression << exp.lhs << " " << exp.op << " " << exp.rhs;
  return formatted_expression.str();
}

int evaluateExpression(const Expression& exp) {
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
    reverseExpression(exp);

    std::cout << "The result of " << printExpression(exp)
              << " reversed is " << evaluateExpression(exp) << std::endl;
  }

  return 0;
}
