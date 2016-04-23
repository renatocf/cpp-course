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

int calculate(char op, int lhs, int rhs) {
  switch (op) {
    case '+': return lhs + rhs;
    case '-': return lhs - rhs;
    case '*': return lhs * rhs;
    case '/': return lhs / rhs;
    default:
      std::ostringstream error_message;
      error_message << "Operator " << op << " is unknown";
      throw std::invalid_argument(error_message.str());
  }
}

int main() {
  while (true) {
    std::cout << "> ";

    struct Expression exp;
    exp.lhs = read<int>();
    exp.op  = read<char>();
    exp.rhs = read<int>();

    std::printf("The result of %d %c %d is %d\n",
        exp.lhs, exp.op, exp.rhs, calculate(exp.op, exp.lhs, exp.rhs));
  }

  return 0;
}
