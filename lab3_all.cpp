#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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
class Department;

class Employee {
private:
    std::string name;
    Department* department;
public:
    Employee(std::string n): name(n), department(nullptr) {}

    std::string getName() {
        return name;
    }

    void setDepartment(Department* dep) {
        department = dep;
    }

    Department* getDepartment() {
        return department;
    }

    std::string toString() {
        return getName();
    }
};

class Department {
private:
    std::string name;
    Employee* manager;
    std::vector<Employee*> employees;
public:
    Department(std::string n, Employee* m): name(n), manager(m) {}

    std::string getName() {
        return name;
    }

    void addEmployee(Employee* emp) {
        emp->setDepartment(this);
        employees.push_back(emp);
    }

    Employee* getManager() {
        return manager;
    }

    std::vector<Employee*> getEmployees() {
        return employees;
    }
};
void printEmployeeInfo(Employee* emp) {
    if (emp->getDepartment()->getManager() == emp) {
    std::cout << emp->getName() << " является начальником отдела " << emp->getDepartment()->getName() << std::endl;
        } 
    else {
        std::cout << emp->getName() << " работает в отделе " << emp->getDepartment()->getName() << ", начальник которого " << emp->getDepartment()->getManager()->getName() << std::endl;
        }
}
void printAllEmployeesInDepartment(Employee* emp) {
    Department* dep = emp->getDepartment();
    std::vector<Employee*> employees = dep->getEmployees();
    
    std::cout << "Сотрудники отдела " << dep->getName() << ": ";
    for (Employee* employee : employees) {
        std::cout << employee->getName() << ", ";
    }
    std::cout << std::endl;
}
class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    std::string getString() {
        std::stringstream ss;
        ss << numerator << "/" << denominator;
        return ss.str();
    }

    Fraction add(const Fraction& other) {
        int newNum = numerator * other.denominator + other.numerator * denominator;
        int newDenom = denominator * other.denominator;
        return Fraction(newNum, newDenom);
    }

    Fraction subtract(const Fraction& other) {
        int newNum = numerator * other.denominator - other.numerator * denominator;
        int newDenom = denominator * other.denominator;
        return Fraction(newNum, newDenom);
    }

    Fraction multiply(const Fraction& other) {
        int newNum = numerator * other.numerator;
        int newDenom = denominator * other.denominator;
        return Fraction(newNum, newDenom);
    }

    Fraction divide(const Fraction& other) {
        int newNum = numerator * other.denominator;
        int newDenom = denominator * other.numerator;
        return Fraction(newNum, newDenom);
    }

    Fraction add(int value) {
        int newNum = numerator + value * denominator;
        return Fraction(newNum, denominator);
    }

    Fraction subtract(int value) {
        int newNum = numerator - value * denominator;
        return Fraction(newNum, denominator);
    }

    Fraction multiply(int value) {
        int newNum = numerator * value;
        return Fraction(newNum, denominator);
    }

    Fraction divide(int value) {
        int newDenom = denominator * value;
        return Fraction(numerator, newDenom);
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
            Employee Petrov("Петров");
            Employee Kozlov("Козлов");
            Employee Sidorov("Сидоров");
            Department IT("IT", &Kozlov);
            IT.addEmployee(&Kozlov);
            IT.addEmployee(&Petrov);
            IT.addEmployee(&Sidorov);
            printEmployeeInfo(&Petrov);
            printEmployeeInfo(&Kozlov);
            printEmployeeInfo(&Sidorov);
        }
            break;

        case 6:
            {
            Employee Petrov("Петров");
            Employee Kozlov("Козлов");
            Employee Sidorov("Сидоров");
            Department IT("IT", &Kozlov);
            IT.addEmployee(&Kozlov);
            IT.addEmployee(&Petrov);
            IT.addEmployee(&Sidorov);
            printAllEmployeesInDepartment(&Kozlov);
            }

        case 4:
            {
            Name name1("", "Клеопатра", "" ); 
            Name name2("Пушкин", "Александр", "Сергеевич");
            Name name3("Маяковский", "Владимир", "");
            Name name4("Христофор", "Бонифатьевич", "" );
            std::cout << "Имя 1: " << name1.toString() << std::endl;
            std::cout << "Имя 2: " << name2.toString() << std::endl;
            std::cout << "Имя 3: " << name3.toString() << std::endl;
            std::cout << "Имя 4: " << name4.toString() << std::endl;
            }
            break;

        case 5:
            {
            Fraction f1(1, 3);
            Fraction f2(2, 3);
            Fraction f3(3, 4);
            std::cout << f1.getString() << " + " << f2.getString() << " = " << f1.add(f2).getString() << std::endl;
            std::cout << f1.getString() << " - " << f2.getString() << " = " << f1.subtract(f2).getString() << std::endl;
            std::cout << f1.getString() << " * " << f2.getString() << " = " << f1.multiply(f2).getString() << std::endl;
            std::cout << f1.getString() << " / " << f2.getString() << " = " << f1.divide(f2).getString() << std::endl;
            Fraction result = f1.add(f2).divide(f3).subtract(5);
            std::cout << "((" << f1.getString() << " + " << f2.getString() << ") / " << f3.getString() << ") - 5 = " << result.getString() << std::endl;
            }
            break;
    }
    return 0;
}

