// проект 1 (30.09.2025).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <cassert>
#include <iostream>
#include "1.h"

// тесты
void runTests() {
    // Создание билета
    Ticket_1 ticket1;
    ticket1.creat(12345, 1000, 5);  
    assert(ticket1.getNumber() == 12345);  
    assert(ticket1.getSaleTime() == 1000);
    assert(ticket1.getMaxTrips() == 5);
    assert(ticket1.getRemainingTrips() == 5);
    assert(ticket1.getLastControlTime() == -1);

    // Успешный проход контроля
    assert(ticket1.tryControl(1100) == true);
    assert(ticket1.getRemainingTrips() == 4);
    assert(ticket1.getLastControlTime() == 1100);

    // Слишком быстрый повторный проход
    assert(ticket1.tryControl(1102) == false); // прошло только 2 секунды после последнего прохода
    assert(ticket1.getRemainingTrips() == 4);
    

    // Успешный проход после задержки
    assert(ticket1.tryControl(1105) == true); // прошло больше 3 секунд после последнего прохода
    assert(ticket1.getRemainingTrips() == 3);

    // Проход с нулевым количеством поездок
    Ticket_1 ticket2;
    ticket2.creat(67890, 2000, 1);  
    assert(ticket2.tryControl(2100) == true);
    assert(ticket2.tryControl(2200) == false); //тут количество поездок 0, поэтому функция выдаст false

    // Сравнение билетов по времени продажи
    Ticket_1 ticket3;
    ticket3.creat(11111, 1500, 3);  
    Ticket_1 ticket4;
    ticket4.creat(22222, 1600, 3);  

    assert(ticket3 < ticket4);
    assert(ticket3 <= ticket4);
    assert(!(ticket3 == ticket4));

    Ticket_1 ticket5;
    ticket5.creat(33333, 1500, 2);  
    assert(ticket3 == ticket5);
    assert(ticket3 <= ticket5);

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    runTests();  // Запуск тестов
    return 0;
}
