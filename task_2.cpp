#include <iostream>
#include <string>
#include <Windows.h>    //Для ввода русских букв с консоли (SetConsoleCP(1251))

class Counter {
public:
    void increment() { ++count; }
    void decrement() { --count; }
    void print_count() { std::cout << count << std::endl; }
    Counter(int start_val = 1) : count{start_val} {};
private:
    int count{ 0 };
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);             // установка кодовой страницы win-cp 1251 в поток ввода
    std::string user_input;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> user_input;
    std::cout << user_input << std::endl;
    Counter* counter = nullptr;
    if (user_input == "да" || user_input == "ДА")
    {
        int start_val = 0;
        std::cout << "Введите начальное значение счётчика : ";
        std::cin >> start_val;
        counter = new Counter(start_val);
    }
    else counter = new Counter();
    char command = ' ';
    do
    {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;
        switch (command)
        {
            case '+':
            {
                counter->increment();
                break;
            }
            case '-':
            {
                counter->decrement();
                break;
            }
            case '=':
            {
                counter->print_count();
                break;
            }
        }
    } while (command != 'x' && command != 'х');
    delete counter;
}

