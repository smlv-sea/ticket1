#include <cassert>
#include <iostream>
#include "1.h"

// ���������� �����
void runTests() {
    // ���� 1: �������� ������
    Ticket ticket1;
    ticket1.init("A123", 1000, 5);
    assert(ticket1.getNumber() == "A123");
    assert(ticket1.getSaleTime() == 1000);
    assert(ticket1.getMaxTrips() == 5);
    assert(ticket1.getRemainingTrips() == 5);
    assert(ticket1.getLastControlTime() == -1);

    // ���� 2: �������� ������ ��������
    assert(ticket1.tryControl(1100) == true);
    assert(ticket1.getRemainingTrips() == 4);
    assert(ticket1.getLastControlTime() == 1100);

    // ���� 3: ������� ������� ��������� ������
    assert(ticket1.tryControl(1102) == false); // ������ ������ 2 �������
    assert(ticket1.getRemainingTrips() == 4); // ���������� �� ����������

    // ���� 4: �������� ������ ����� ��������
    assert(ticket1.tryControl(1105) == true); // ������ 5 ������
    assert(ticket1.getRemainingTrips() == 3);

    // ���� 5: ������ � ������� ����������� �������
    Ticket ticket2;
    ticket2.init("B456", 2000, 1);
    assert(ticket2.tryControl(2100) == true);
    assert(ticket2.tryControl(2200) == false); // ������� ������ ���

    // ���� 6: ��������� ������� �� ������� �������
    Ticket ticket3;
    ticket3.init("C789", 1500, 3);
    Ticket ticket4;
    ticket4.init("D012", 1600, 3);

    assert(ticket3 < ticket4);
    assert(ticket3 <= ticket4);
    assert(!(ticket3 == ticket4));

    Ticket ticket5;
    ticket5.init("E345", 1500, 2);
    assert(ticket3 == ticket5);
    assert(ticket3 <= ticket5);

    std::cout << "All tests passed successfully!" << std::endl;
}