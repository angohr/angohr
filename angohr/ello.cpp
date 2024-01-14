module;

#include <iostream>

export module core : iface.ello;

namespace core {
export class ello {
public:
  ello();
  void hello();
};

ello::ello() = default;
void ello::hello() {
  std::cout << "Why hello!\n";
}
}
