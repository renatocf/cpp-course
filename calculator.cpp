#include <iostream>
#include <cstdio>

int readNumber() {
  int new_number;
  std::cin >> new_number;
  return new_number;
}

char readCharacter() {
  char new_character;
  std::cin >> new_character;
  return new_character;
}

int main() {
  std::cout << "> ";

  int  a  = readNumber();
  char op = readCharacter();
  int  b  = readNumber();

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
