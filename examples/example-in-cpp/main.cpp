#include <iostream>
#include <ostream>

int main(int argc, char **argv) {
  std::cout << "This is a simple C++ application example." << std::endl
            << "It's been given " << argc << " arguments:" << std::endl;
  for (int i = 0; i < argc; i++) {
    std::cout << "\targv[" << i << "] = \"" << argv[i] << "\"" << std::endl;
  }
  std::cout << "That'd be all!" << std::endl;
  return 0;
}