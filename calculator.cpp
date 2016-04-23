#include <iostream>
#include <stdexcept>
#include <sstream>

template<typename T>
T read() {
  T variable_read;
  std::cin >> variable_read;
  return variable_read;
}

class Expression {
 public:
  void read() {
    lhs = ::read<int>();
    op  = ::read<char>();
    rhs = ::read<int>();
  }

  void reverse() {
    switch (op) {
      case '+': op = '-'; break;
      case '-': op = '+'; break;
      case '*': op = '/'; break;
      case '/': op = '*'; break;
    }
  }

  std::string toString() const {
    std::ostringstream formatted_expression;
    formatted_expression << lhs << " " << op << " " << rhs;
    return formatted_expression.str();
  }

  int evaluate() const {
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

 private:
  int lhs;
  char op;
  int rhs;
};

int main() {
  while (true) {
    std::cout << "> ";

    Expression exp;
    exp.read();
    exp.reverse();

    std::cout << "The result of " << exp.toString()
              << " reversed is " << exp.evaluate() << std::endl;
  }

  return 0;
}
