#ifndef TICKET_H
#define TICKET_H



class Ticket_1 {
private:
    int number;  // номер билета
    int saleTime; // время продажи
    int maxTrips; // максимальное число поездок
    int remainingTrips; //остаток поездок
    int lastControlTime; // время последнего прохода через контроль

public:
public:
    // Создание билета с заданным числом поездок (с использованием конструктора)
    Ticket_1(int num, int saleT, int maxT);

    // Метод для попытки прохода контроля
    bool tryControl(int currentTime);

    
    int getNumber() const;
    int getSaleTime() const;
    int getMaxTrips() const;
    int getRemainingTrips() const;
    int getLastControlTime() const;

    // Операторы сравнения по времени продажи
    bool operator==(const Ticket_1& other) const;
    bool operator<(const Ticket_1& other) const;
    bool operator<=(const Ticket_1& other) const;
};

#endif
