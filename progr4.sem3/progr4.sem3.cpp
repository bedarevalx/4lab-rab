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
    void Init(std::string a, int b, float c) {
        title = a;
        population = b;
        millitarypow = c;
    }
    void surrend() {
        std::cout << "Государство" << title << "сдалось" << endl;
        surrender = true;
    };
    void war() {
        std::cout << "***********Начало войны***********" << endl;
         
    };
   // void endwar();
    std::string title;
    int population;
    float millitarypow;
    bool surrender = false;
    bool win = false;
};

class peacefull : public nation {
public:
    void devpopulation() {
        std::cout << "У государства" << title << "выросла популяция, военная сила уменьшена";
        population *= 1, 5;
        millitarypow -= 0, 1;
    };
    void Display() {
        std::cout << "Информация о государстве" << title << endl;
        std::cout << "Популяция - " << population << endl;
        std::cout << "Военная мощь - " << millitarypow << endl;
        std::cout << "Тип государства - Дружелюбное" << endl;
    };
};

class enemy : public nation {
public:
    void devmilitar() {
        std::cout << "У государства" << title << "увеличилась военная мощь, популяция уменьшена";
        millitarypow += 1;
        population *= 0, 7;
    }
    void Display() {
        std::cout << "Информация о государстве" << title << endl;
        std::cout << "Популяция - " << population << endl;
        std::cout << "Военная мощь - " << millitarypow << endl;
        std::cout << "Тип государства - Военное" << endl;
    };
};

int main()
{
    setlocale(LC_ALL, "RUS");
    peacefull* one = new peacefull();
    enemy* two = new enemy();
    one->Read();
    two->Init("rome", 11000, 0.1);
    getchar();
    std::cout << "***********Начало войны***********" << endl;
    std::cout << "У государств еще есть возможность этого избежать, если\n одно из государств сдастся";
    std::cout << "Государство" << one->title << "вы хотите сдаться? (1-да 2-нет)";
    int num;
    do {
        num = getchar();
    } while (num != 49 || num != 50);
    if(num==49){
        one->surrend();
    }


}
