#include <iostream>
#include <cstdio>
#include <stdexcept>

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
      throw std::invalid_argument("Operator is unknown");
  }
}

int main() {
  std::cout << "> ";

  auto a  = read<int>();
  auto op = read<char>();
  auto b  = read<int>();

  std::printf("The result of %d %c %d is %d\n", a, op, b, calculate(op, a, b));

  return 0;
}
