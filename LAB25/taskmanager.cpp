#include <iostream>
#include <stdexcept>
using namespace std;

class Money {
private:
    unsigned int rubles;
    short int kopeks; // должно находиться в диапазоне 0..99 (копейки)

    // Вспомогательный метод для нормализации (если вдруг копейки окажутся вне диапазона)
    void normalize() {
        if(kopeks >= 100) {
            rubles += kopeks / 100;
            kopeks %= 100;
        }
        // Если вдруг получилось отрицательное значение (при вычитании) приводим к 0
        if(rubles == 0 && kopeks < 0) {
            kopeks = 0;
        }
    }

public:
    // Конструктор по умолчанию
    Money() : rubles(0), kopeks(0) {}

    // Параметризованный конструктор
    Money(unsigned int rubles, short int kopeks) : rubles(rubles), kopeks(kopeks) {
        if(kopeks < 0 || kopeks >= 100) {
            throw invalid_argument("Копейки должны находиться в диапазоне [0, 99].");
        }
    }

    // Копирующий конструктор
    Money(const Money &other) : rubles(other.rubles), kopeks(other.kopeks) {}

    // Геттеры
    unsigned int getRubles() const { return rubles; }
    short int getKopeks() const { return kopeks; }

    // Унарный префиксный оператор -- (вычитание одной копейки):
    Money& operator--() {
        // Преобразуем всю сумму в копейки
        long totalKopeks = static_cast<long>(rubles) * 100 + kopeks;
        totalKopeks -= 1; // вычитаем одну копейку
        if(totalKopeks < 0) {
            totalKopeks = 0;
        }
        rubles = static_cast<unsigned int>(totalKopeks / 100);
        kopeks = static_cast<short int>(totalKopeks % 100);
        return *this;
    }

    // Унарный префиксный оператор ++ (добавление одной копейки):
    Money& operator++() {
        // Преобразуем в копейки и прибавим одну копейку
        long totalKopeks = static_cast<long>(rubles) * 100 + kopeks;
        totalKopeks += 1;
        rubles = static_cast<unsigned int>(totalKopeks / 100);
        kopeks = static_cast<short int>(totalKopeks % 100);
        return *this;
    }

    // Бинарный оператор вычитания копеек (unsigned int):
    Money operator-(unsigned int subKopeks) const {
        long totalKopeks = static_cast<long>(rubles) * 100 + kopeks;
        long resultKopeks = totalKopeks - static_cast<long>(subKopeks);
        if(resultKopeks < 0) {
            resultKopeks = 0;
        }
        return Money(static_cast<unsigned int>(resultKopeks / 100),
                     static_cast<short int>(resultKopeks % 100));
    }

    // Бинарный оператор -= для копеек
    Money& operator-=(unsigned int subKopeks) {
        *this = *this - subKopeks;
        return *this;
    }

    // Бинарный оператор вычитания суммы другого объекта Money:
    Money operator-(const Money &other) const {
        // Преобразуем обе суммы в копейки
        long totalKopeks1 = static_cast<long>(rubles) * 100 + kopeks;
        long totalKopeks2 = static_cast<long>(other.rubles) * 100 + other.kopeks;
        long resultKopeks = totalKopeks1 - totalKopeks2;
        if(resultKopeks < 0) {
            resultKopeks = 0;
        }
        return Money(static_cast<unsigned int>(resultKopeks / 100),
                     static_cast<short int>(resultKopeks % 100));
    }

    // Операция ввода с проверкой
    void input() {
        cout << "Введите рубли: ";
        cin >> rubles;
        cout << "Введите копейки (0-99): ";
        cin >> kopeks;
        if(kopeks < 0 || kopeks >= 100) {
            throw invalid_argument("Копейки должны находиться в диапазоне [0, 99].");
        }
    }

    // Метод вывода
    void display() const {
        cout << rubles << " руб. " << kopeks << " коп." << endl;
    }

    // Явное приведение к unsigned int (выделяем рубли, копейки отбрасываем)
    explicit operator unsigned int() const {
        return rubles;
    }

    // Неявное приведение к bool: true, если сумма ненулевая
    operator bool() const {
        return (rubles != 0 || kopeks != 0);
    }
};

// Перегрузка оператора << для вывода объекта Money
ostream& operator<<(ostream &os, const Money &m) {
    os << m.getRubles() << " руб. " << m.getKopeks() << " коп.";
    return os;
}

void Moni() {
    try {
        cout << "Тестирование базовых конструкторов:" << endl;
        Money m1;
        cout << "m1 (по умолчанию): " << m1 << endl;

        Money m2(10, 50);
        cout << "m2 (10 руб. 50 коп.): " << m2 << endl;

        Money m3(m2);
        cout << "m3 (копия m2): " << m3 << endl;

        cout << "\nТестирование бинарного вычитания: " << endl;
        cout << "m2 - 75 копеек: ";
        Money m4 = m2 - 75;
        cout << m4 << endl;

        cout << "m2 - m3: ";
        Money m5 = m2 - m3; // должно дать 0
        cout << m5 << endl;

        cout << "\nТестирование унарных операций:" << endl;
        cout << "Начальное значение m2: " << m2 << endl;
        ++m2;
        cout << "После ++m2: " << m2 << endl;
        --m2;
        cout << "После --m2: " << m2 << endl;

        cout << "\nТестирование операций приведения типов:" << endl;
        unsigned int rublesFromM2 = static_cast<unsigned int>(m2);
        cout << "Явное приведение m2 к unsigned int (рубли): " << rublesFromM2 << endl;

        if(m2) {
            cout << "Неявное приведение к bool: m2 не равен 0" << endl;
        } else {
            cout << "Неявное приведение к bool: m2 равен 0" << endl;
        }

        cout << "\nТестирование ввода с консоли и операций:" << endl;
        Money mUser;
        mUser.input();
        cout << "Введено: " << mUser << endl;
        
        unsigned int subKopeks;
        cout << "Введите количество копеек для вычитания: ";
        cin >> subKopeks;
        Money mSubtracted = mUser - subKopeks;
        cout << "Результат (mUser - " << subKopeks << " коп.): " << mSubtracted << endl;

    } catch (const exception &ex) {
        cerr << "Ошибка: " << ex.what() << endl;
    }
}
