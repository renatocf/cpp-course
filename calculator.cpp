#include <iostream>
#include <cstdio>

template<typename T>
T read() {
  T variable_read;
  std::cin >> variable_read;
  return variable_read;
}

int main() {
  std::cout << "> ";

  int  a  = read<int>();
  char op = read<char>();
  int  b  = read<int>();

  if (op == '+') {
    std::printf("The result of %d %c %d is %d\n", a, op, b, a + b);
  } else if (op == '-') {
    std::printf("The result of %d %c %d is %d\n", a, op, b, a - b);
  } else if (op == '*') {
    std::printf("The result of %d %c %d is %d\n", a, op, b, a * b);
  } else if (op == '/') {
    std::printf("The result of %d %c %d is %d\n", a, op, b, a / b);
  } else {
    std::printf("Error! Operator %c is unknown\n", op);
  }

  return 0;
}
