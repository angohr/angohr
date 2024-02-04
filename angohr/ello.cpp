module;

#include <fmt/core.h>
#include <spdlog/spdlog.h>

export module core : iface.ello;

namespace core {
export class ello {
public:
  ello();
  void hello();
  int theAnswer();
  void logSomething();
};

ello::ello() = default;

void ello::hello() {
  fmt::print("Why hello!!!\n");
}

int ello::theAnswer() {
  return 42;
}

void ello::logSomething() {
  spdlog::info("Welcome to Angohr!");
  spdlog::error("Error message with arg: {}", 42);
}

}
