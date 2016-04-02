#include <iostream>

int readNumber(int position) {
  int new_number;

  std::cout << "Input " << position << "th number: ";
  std::cin >> new_number;

  return new_number;
}

int main() {
  int a, b;

  a = readNumber(1);
  b = readNumber(2);

  std::cout << "The result of `a + b` is: " << a + b << std::endl;
  std::cout << "The result of `a - b` is: " << a - b << std::endl;
  std::cout << "The result of `a * b` is: " << a * b << std::endl;
  std::cout << "The result of `a / b` is: " << a / b << std::endl;

  return 0;
}
