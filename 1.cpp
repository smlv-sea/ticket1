#include "1.h"

// Создание билета
void Ticket_1::creat(int num, int saleT, int maxT) {  // 
    number = num;      // 
    saleTime = saleT;
    maxTrips = maxT;
    remainingTrips = maxT;
    lastControlTime = -1;
}

// Возможность прохода контроля 
bool Ticket_1::tryControl(int currentTime) {
    if (remainingTrips <= 0) {
        return false;
    } // если чило поездок меньше или равно нуля, то пройти контроль невозможно

    if (lastControlTime != -1 && (currentTime - lastControlTime) <= 3) {
        return false;
    } // если билет уже использовался и текущее время минус время прохода контроля
      // меньше 3 секунд, то проход невозможен

    remainingTrips--; //после прохода уменьшается число поездок
    lastControlTime = currentTime; //время последнего прохода становится равным текущему времени
    return true;
}

// Методы дают доступ к параметрам билета из поля private
int Ticket_1::getNumber() const { return number; }  
int Ticket_1::getSaleTime() const { return saleTime; }
int Ticket_1::getMaxTrips() const { return maxTrips; }
int Ticket_1::getRemainingTrips() const { return remainingTrips; }
int Ticket_1::getLastControlTime() const { return lastControlTime; }

// Операторы сравнения по времени продажи (используется переопределение операторов)
bool Ticket_1::operator==(const Ticket_1& other) const {
    return saleTime == other.saleTime;
}

bool Ticket_1::operator<(const Ticket_1& other) const {
    return saleTime < other.saleTime;
}

bool Ticket_1::operator<=(const Ticket_1& other) const {
    return saleTime <= other.saleTime;
}
