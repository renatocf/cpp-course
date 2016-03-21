#include <iostream>

int main() {
  int a, b;

  std::cout << "Input 1st number (a): ";
  std::cin >> a;
  std::cout << "Input 2nd number (b): ";
  std::cin >> b;

  std::cout << "The result of `a + b` is: " << a + b << std::endl;
  std::cout << "The result of `a - b` is: " << a - b << std::endl;
  std::cout << "The result of `a * b` is: " << a * b << std::endl;
  std::cout << "The result of `a / b` is: " << a / b << std::endl;

  return 0;
}
