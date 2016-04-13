#include <iostream>

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
  int a, b;
  char op;

  std::cout << "> ";

  a  = readNumber();
  op = readCharacter();
  b  = readNumber();

  if (op == '+') {
    std::cout << "The result of " << a << " " << op << " " << b
              << " is " << a + b << std::endl;
  } else if (op == '-') {
    std::cout << "The result of " << a << " " << op << " " << b
              << " is " << a - b << std::endl;
  } else if (op == '*') {
    std::cout << "The result of " << a << " " << op << " " << b
              << " is " << a * b << std::endl;
  } else if (op == '/') {
    std::cout << "The result of " << a << " " << op << " " << b
              << " is " << a / b << std::endl;
  } else {
    std::cout << "Error! Operator " << op << " is unknown" << std::endl;
  }

  return 0;
}
