#include <iostream>
#include <string>
#include <map>

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
class House{
    private:
    int p_floors;
    public:
    int getFloors() { return p_floors; };
    std::string forms;

    void setFloors(int floors)
    {
        p_floors = floors;
    }
    void print()
    {
        int form = getFloors();
        if (form == 1 or (form % 10 == 1 && form !=11))
            forms = "этажом";
        else
            forms = "этажами";
        std::cout<<"дом с "<< form << " " << forms << std::endl;
    }
    House(int n_floors)
    {
        this->p_floors = n_floors;
    }
};
class Employee{
    private:
    std::string name;
    std::string department;
    Employee* boss;
    public:
    Employee(std::string name, std::string department) : name(name), department(department), boss(nullptr) {}
    
    void setBoss(Employee* boss){
    this->boss = boss;
    }

    std::string toString() {
        if (boss!= nullptr && boss->department == department) {
            return name + " является начальником отдела " + department;
        }
        else {
            if(boss != nullptr && boss->name != name){
                return name + " Работает в отделе " + department + ", начальник которого: " + boss->name;
            }
            else{
                return name + " Работает в отделе " + department + ", у которого нет начальника ";
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    int choice = 1;
    std::cout << "Введите номер задания" <<std::endl;
    std::cin >> choice;
    switch (choice)
    {
        case 1:
        {
            Name name1("", "Клеопатра", ""); 
            Name name2("Пушкин", "Александр", "Сергеевич");
            Name name3("Маяковский", "Владимир", "");
            std::cout << "Имя 1: " << name1.toString() << std::endl;
            std::cout << "Имя 2: " << name2.toString() << std::endl;
            std::cout << "Имя 3: " << name3.toString() << std::endl;
            //int n =1;
            //std::cout<< "введите количество имен"<<std::endl;
            //std::cin >> n;
            //std::cin.ignore();
            //for(int i=1; i<=n; i++){
                //std::string sur,first,pat;
                //std::cout << "Введите фамилию: ";
                //std::getline(std::cin, sur);
                //std::cout << "Введите имя: ";
                //std::getline(std::cin, first);
                //std::cout << "Введите отчество: ";
                //std::getline(std::cin, pat);
                //Name name(sur,first,pat);
                //std::cout << "Имя " << i << ": " << name.toString() << std::endl;
            }      
        
            break;
        

        case 2:
        {
            House house1(1);
            house1.print();
            House house2(5);
            house2.print();
            House house3(23);
            house3.print();
        }
            break;

        case 3:
        {
            Employee Petrov("Петров", "IT");
            Employee Kozlov("Козлов", "IT");
            Employee Sidorov("Сидоров", "IT");
            Kozlov.setBoss(&Kozlov);
            std::cout << Petrov.toString() << std::endl;
            std::cout << Kozlov.toString() << std::endl;
            std::cout << Sidorov.toString() << std::endl;
            return 0;
        }
            break;

        case 6:
            {
            
            }

        case 4:
        {
            

        }
            break;

        case 5:
        {
            
        }
            break;
    }
    return 0;
}

