#ifndef TICKET_H
#define TICKET_H



class Ticket_1 {
private:
    int number;  // ����� ������
    int saleTime; // ����� �������
    int maxTrips; // ������������ ����� �������
    int remainingTrips; //������� �������
    int lastControlTime; // ����� ���������� ������� ����� ��������

public:
public:
    // �������� ������ � �������� ������ ������� (� �������������� ������������)
    Ticket_1(int num, int saleT, int maxT);

    // ����� ��� ������� ������� ��������
    bool tryControl(int currentTime);

    
    int getNumber() const;
    int getSaleTime() const;
    int getMaxTrips() const;
    int getRemainingTrips() const;
    int getLastControlTime() const;

    // ��������� ��������� �� ������� �������
    bool operator==(const Ticket_1& other) const;
    bool operator<(const Ticket_1& other) const;
    bool operator<=(const Ticket_1& other) const;
};

#endif
