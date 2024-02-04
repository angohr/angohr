module;

#include <fmt/core.h>

export module core : iface.ello;

namespace core {
export class ello {
public:
  ello();
  void hello();
  int theAnswer();
};

ello::ello() = default;
void ello::hello() {
  fmt::print("Why hello!!!\n");
}
int ello::theAnswer() {
  return 42;
}
}
