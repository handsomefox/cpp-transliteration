#include <Windows.h>
#include <iostream>
#include <string>

const std::string ENG =
    R"(QWERTYUIOP{}ASDFGHJKL:"ZXCVBNM<>qwertyuiop[]asdfghjkl;'zxcvbnm,.)";
const std::string RUS =
    R"(ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮйцукенгшщзхъфывапролджэячсмитьбю)";
std::string transliterator(std::string &text) {
  size_t pos = 0;
  for (size_t i = 0; i < text.length(); ++i) {
    pos = ENG.find(text[i]);
    if (pos != ENG.npos)
      text[i] = RUS[pos];
  }
  return text;
}
int main() {
  SetConsoleOutputCP(1251);
  std::string string;
  std::cout << "\nEnter any transliterated text: ";
  std::getline(std::cin, string);
  std::cout << "Back to russian: " << transliterator(string);
  return 0;
}
