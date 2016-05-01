#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

template<typename T>
T read(std::istream& is) {
  T variable_read;
  is >> variable_read;
  return variable_read;
}

class Expression {
 public:
  Expression() = default;

  Expression(int lhs, char op, int rhs)
      : lhs(lhs), op(op), rhs(rhs) {
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

void readEvalPrint(std::string& line) {
  try {
    std::istringstream iss(line);
    auto exp = read<Expression>(iss);
    auto result = exp.evaluate();
    std::cout << result << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

int main() {
  std::string line;
  while (std::cout << "> ", std::getline(std::cin, line)) {
    readEvalPrint(line);
  }

  return 0;
}
