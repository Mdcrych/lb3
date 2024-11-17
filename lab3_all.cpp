#include <iostream>
#include 
class Name {
  private:
  std::string surname;
  std::string firstName;
  std::string patronymic;
  public:
  Name(std::string sur, std::string first, std::string pat):
  surname(sur), firstName(first), patronymic(pat) {}
  std::string toString() {
    std::string result = "";
    if (!surname.empty()) {
        result += surname;
    }
    if (!firstName.empty()) {
        if (!result.empty()) result += " ";
        result += firstName;
    }
    if (!patronymic.empty()) {
        if (!result.empty()) result += " ";
        result += patronymic;
    }
    return result;}
};
int main() {
  Name name1("", "Клеопатра", ""); 
  Name name2("Пушкин", "Александр", "Сергеевич");
  Name name3("Маяковский", "Владимир", "");
  std::cout << "Имя 1: " << name1.toString() << std::endl;
  std::cout << "Имя 2: " << name2.toString() << std::endl;
  std::cout << "Имя 3: " << name3.toString() << std::endl;

return 0;};
ц
