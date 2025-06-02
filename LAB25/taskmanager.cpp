#include <iostream>
#include <stdexcept>
using namespace std;

class Money {
private:
    unsigned int rubles;
    short int kopeks;

    void normalize() {
        if(kopeks >= 100) {
            rubles += kopeks / 100;
            kopeks %= 100;
        }
        if(rubles == 0 && kopeks < 0) {
            kopeks = 0;
        }
    }

public:
    Money() : rubles(0), kopeks(0) {}

    Money(unsigned int rubles, short int kopeks) : rubles(rubles), kopeks(kopeks) {
        if(kopeks < 0 || kopeks >= 100) {
            throw invalid_argument("скажи мне, мой хороший, какой диапазон у копеек? правильно, от 0 до 99. ну дак а че тогда?.");
        }
    }

    Money(const Money &other) : rubles(other.rubles), kopeks(other.kopeks) {}

    unsigned int getRubles() const { return rubles; }
    short int getKopeks() const { return kopeks; }

    Money& operator--() {
        long totalKopeks = static_cast<long>(rubles) * 100 + kopeks;
        totalKopeks -= 1;
        if(totalKopeks < 0) {
            totalKopeks = 0;
        }
        rubles = static_cast<unsigned int>(totalKopeks / 100);
        kopeks = static_cast<short int>(totalKopeks % 100);
        return *this;
    }

    Money& operator++() {
        long totalKopeks = static_cast<long>(rubles) * 100 + kopeks;
        totalKopeks += 1;
        rubles = static_cast<unsigned int>(totalKopeks / 100);
        kopeks = static_cast<short int>(totalKopeks % 100);
        return *this;
    }

    Money operator-(unsigned int sub_kopeks) const {
        long totalKopeks = static_cast<long>(rubles) * 100 + kopeks;
        long resultKopeks = totalKopeks - static_cast<long>(sub_kopeks);
        if(resultKopeks < 0) {
            resultKopeks = 0;
        }
        return Money(static_cast<unsigned int>(resultKopeks / 100),
                     static_cast<short int>(resultKopeks % 100));
    }

    Money& operator-=(unsigned int sub_kopeks) {
        *this = *this - sub_kopeks;
        return *this;
    }

    Money operator-(const Money &other) const {
        long totalKopeks1 = static_cast<long>(rubles) * 100 + kopeks;
        long totalKopeks2 = static_cast<long>(other.rubles) * 100 + other.kopeks;
        long resultKopeks = totalKopeks1 - totalKopeks2;
        if(resultKopeks < 0) {
            resultKopeks = 0;
        }
        return Money(static_cast<unsigned int>(resultKopeks / 100),
                     static_cast<short int>(resultKopeks % 100));
    }

    void input() {
        cout << "введи рубли: ";
        cin >> rubles;
        cout << "введи копейи (0-99): ";
        cin >> kopeks;
        if(kopeks < 0 || kopeks >= 100) {
            throw invalid_argument("я, видимо, неясно выразился, но диапазон от 0 до 99.");
        }
    }

    void display() const {
        cout << rubles << " руб. " << kopeks << " коп." << endl;
    }

    explicit operator unsigned int() const {
        return rubles;
    }

    operator bool() const {
        return (rubles != 0 || kopeks != 0);
    }
};

ostream& operator<<(ostream &os, const Money &m) {
    os << m.getRubles() << " руб. " << m.getKopeks() << " коп.";
    return os;
}

void Moni() {
    try {
        cout << "тест основных конструкторов:" << endl;
        Money m1;
        cout << "m1 (по дефолту): " << m1 << endl;

        Money m2(10, 50);
        cout << "m2 (10 руб. 50 коп.): " << m2 << endl;

        Money m3(m2);
        cout << "m3 (сплагиатил m2): " << m3 << endl;

        cout << "\nбинарное вычитание: " << endl;
        cout << "m2 - 75 копеек: ";
        Money m4 = m2 - 75;
        cout << m4 << endl;

        cout << "m2 - m3: ";
        Money m5 = m2 - m3;
        cout << m5 << endl;

        cout << "\nунарные (что бы это ни значило) операции:" << endl;
        cout << "начальное значение m2: " << m2 << endl;
        ++m2;
        cout << "после ++m2: " << m2 << endl;
        --m2;
        cout << "после --m2: " << m2 << endl;

        cout << "\nоперации призраков типов:" << endl;
        unsigned int rubles_m2 = static_cast<unsigned int>(m2);
        cout << "приведение m2 к unsigned int (рубли): " << rubles_m2 << endl;

        if(m2) {
            cout << "приведение к bool: m2 не равен 0" << endl;
        }
        else {
            cout << "приведение к bool: m2 равен 0" << endl;
        }

        cout << "\nультра тест: введи рубли и копейки" << endl;
        Money m_user;
        m_user.input();
        cout << "у тебя есть: " << m_user << endl;
        
        unsigned int sub_kopeks;
        cout << "сколько копеек вычесть: ";
        cin >> sub_kopeks;
        Money m_subbed = m_user - sub_kopeks;
        cout << "рузультат (m_user - " << sub_kopeks << " коп.): " << m_subbed << endl;

    } catch (const exception &ex) {
        cerr << "ошибос: " << ex.what() << endl;
    }
}
