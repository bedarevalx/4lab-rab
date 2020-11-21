#include <iostream>
#include <string>
using namespace std;

class nation {
public:
    void Read() {
        std::cout << "Введите название государства:";
        std::cin >> title;
        std::cout << "Введите кол-во населения:";
        std::cin >> population;
        std::cout << "Введите военную мощь (=<2):";
        std::cin >> millitarypow;
    }
   /* void Init();
    void Display();
    void surrend();
    void war();
    void endwar();*/
    std::string title;
    int population;
    float millitarypow;
};

class peacefull : public nation {
public:
    void devpopulation() {
        population *= 1, 5;
        millitarypow -= 0, 1;
    };
};

class enemy : public nation {
public:
    void devmilitar() {
        millitarypow += 1;
        population *= 0, 7;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    peacefull *one = new peacefull();
    enemy* two = new enemy();
    one->Read();
    two->Read();
   

}
