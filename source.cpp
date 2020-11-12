#include <Windows.h>
#include <iostream>
#include <string>

const std::string ENG = R"(QWERTYUIOP{}ASDFGHJKL:"ZXCVBNM<>qwertyuiop[]asdfghjkl;'zxcvbnm,.)";
const std::string RUS = R"(ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮйцукенгшщзхъфывапролджэячсмитьбю)";

std::string transliterator(const std::string &text) 
{
  size_t pos = 0;
  std::string newtext = text;

  for (size_t i = 0; i < text.length(); ++i) 
  {
    pos = ENG.find(text[i]);
    if (pos != std::string::npos)
      newtext[i] = RUS[pos];
  }
  std::cout << newtext << " ";
  return newtext;
}
int main(int argc, char *argv[]) 
{
  SetConsoleOutputCP(1251);

  for (unsigned int i = 1; i < argc; ++i) 
    transliterator(static_cast<std::string>(argv[i]));

  return 0;
}
