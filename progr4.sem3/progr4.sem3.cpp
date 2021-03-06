﻿#include <iostream>
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
    void endwar() {
        score = population * millitarypow;
    };
    std::string title;
    int population;
    float score;
    float millitarypow;
    bool surrender = false;
    bool win = false;
};

class peacefull : public nation {
public:
    void devpopulation() {
        std::cout << "\nУ государства " << title << " выросла популяция, военная сила уменьшена";
        population *= 1.5;
        millitarypow -= 0.1;
    };
    void Display() {
        std::cout << "Информация о государстве " << title << endl;
        std::cout << "Популяция - " << population << endl;
        std::cout << "Военная мощь - " << millitarypow << endl;
        std::cout << "Тип государства - Дружелюбное" << endl;
    };
};

class enemy : public nation {
public:
    void devmilitar() {
        std::cout << "\nУ государства " << title << " увеличилась военная мощь, популяция уменьшена";
        millitarypow += 1;
        population *= 0.7;
    }
    void Display() {
        std::cout << "Информация о государстве " << title << endl;
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
    two->Init("Rome", 11000, 1.1);
    one->Display();
    two->Display();
    std::cout << "***********Начало войны***********" << endl;
    std::cout << "\nУ государств еще есть возможность этого избежать, если\n одно из государств сдастся";
    //**********
    std::cout << "\nГосударство " << one->title << " вы хотите сдаться? (1-да 2-нет)";
    int num;
    do {
        num = getchar();
        if (num == 50) break;
        if (num == 49) break;
    } while (1);
    if(num==49){
        one->surrend();
    }
    //*****
    std::cout << "\nГосударство " << two->title << " вы хотите сдаться? (1-да 2-нет)";
    do {
        num = getchar();
        if (num == 50) break;
        if (num == 49) break;
    } while (1);
    if (num == 49) {
        two->surrend();
    }

    if (one->surrender == true && two->surrender == true) {
        std::cout << "Был заключен мирный переговор, война закончилась" << endl;
    }
    if (one->surrender == true && two->surrender == false) {
        std::cout << "Государство "<<one->title<<" сдалось, победу одержало государство "<<two->title << endl;
    }
    if (one->surrender == false && two->surrender == true) {
        std::cout << "Государство " << two->title << " сдалось, победу одержало государство " << one->title << endl;
    }
    if (one->surrender == false && two->surrender == false) {
        one->devpopulation();
        two->devmilitar();
        one->endwar();
        two->endwar();
        if (one->score > two->score) {
            std::cout<< "В ходе войны государство " <<two->title<< " потерпело поражение, победу одержало государство " << one->title << endl;
        }
        if (one->score < two->score) {
            std::cout << "\nВ ходе войны государство " << one->title << " потерпело поражение, победу одержало государство " << two->title << endl;
        }
        if (one->score == two->score) {
            std::cout << "В ходе войны силы обоих сторон оказались равными, объявлена ничья!" << endl;
        }
    }

}
