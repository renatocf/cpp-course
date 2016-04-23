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

  friend std::istream& operator>>(std::istream& is, Expression& exp);
  friend std::ostream& operator<<(std::ostream& os, const Expression& exp);
};

std::istream& operator>>(std::istream& is, Expression& exp) {
  is >> exp.lhs >> exp.op >> exp.rhs;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Expression& exp) {
  os << exp.lhs << " " << exp.op << " " << exp.rhs;
  return os;
}

int main() {
  while (true) {
    std::cout << "> ";

    auto exp = read<Expression>();

    std::cout << "The result of " << exp << " is " << exp.evaluate()
              << std::endl;
  }

  return 0;
}
