#include "1.h"

// �������� ������
void Ticket_1::creat(int num, int saleT, int maxT) {  // 
    number = num;      // 
    saleTime = saleT;
    maxTrips = maxT;
    remainingTrips = maxT;
    lastControlTime = -1;
}

// ����������� ������� �������� 
bool Ticket_1::tryControl(int currentTime) {
    if (remainingTrips <= 0) {
        return false;
    } // ���� ���� ������� ������ ��� ����� ����, �� ������ �������� ����������

    if (lastControlTime != -1 && (currentTime - lastControlTime) <= 3) {
        return false;
    } // ���� ����� ��� ������������� � ������� ����� ����� ����� ������� ��������
      // ������ 3 ������, �� ������ ����������

    remainingTrips--; //����� ������� ����������� ����� �������
    lastControlTime = currentTime; //����� ���������� ������� ���������� ������ �������� �������
    return true;
}

// ������ ���� ������ � ���������� ������ �� ���� private
int Ticket_1::getNumber() const { return number; }  
int Ticket_1::getSaleTime() const { return saleTime; }
int Ticket_1::getMaxTrips() const { return maxTrips; }
int Ticket_1::getRemainingTrips() const { return remainingTrips; }
int Ticket_1::getLastControlTime() const { return lastControlTime; }

// ��������� ��������� �� ������� ������� (������������ ��������������� ����������)
bool Ticket_1::operator==(const Ticket_1& other) const {
    return saleTime == other.saleTime;
}

bool Ticket_1::operator<(const Ticket_1& other) const {
    return saleTime < other.saleTime;
}

bool Ticket_1::operator<=(const Ticket_1& other) const {
    return saleTime <= other.saleTime;
}
