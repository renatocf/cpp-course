#include <iostream>
#include <cstdio>
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

    std::printf("The result of %d %c %d is %d\n",
        exp.lhs, exp.op, exp.rhs, evaluateExpression(exp));
  }

  return 0;
}
