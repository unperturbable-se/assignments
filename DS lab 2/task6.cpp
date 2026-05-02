#include <iostream>
using namespace std;

class Seat
{
    string name;

public:
    void setName(const string& n)
    {
        name = n;
    }

    string getName() const
    {
        return name;
    }
};

class Row
{
    int seatCount;
    Seat* seats;

public:
    Row()
    {
        seatCount = 0;
        seats = nullptr;
    }

    void allocateSeats(int count, int rowNumber)
{
    seatCount = count;
    seats = new Seat[seatCount];

    cout << "Enter names for Row " << rowNumber << ":\n";
    cin.ignore();  

    for (int i = 0; i < seatCount; i++)
    {
        cout << "  Seat " << i + 1 << ": ";
        string name;
        getline(cin, name);
        seats[i].setName(name);
    }
}


    void displaySeats(int rowNumber) const
    {
        cout << "Row " << rowNumber << ": ";
        for (int i = 0; i < seatCount; i++)
        {
            cout << " " << seats[i].getName() << " ";
        }
        cout << endl;
    }

    ~Row()
    {
        delete[] seats;
    }
};

int main()
{
    int numRows;
    cout << "Enter number of rows in the hall: ";
    cin >> numRows;

    Row* rows = new Row[numRows];

    for (int i = 0; i < numRows; i++)
    {
        int seatCount;
        cout << "Enter number of seats in row " << i + 1 << ": ";
        cin >> seatCount;
        rows[i].allocateSeats(seatCount, i + 1);
    }

    cout << "\n--- Seating Chart ---\n";
    for (int i = 0; i < numRows; i++)
    {
        rows[i].displaySeats(i + 1);
    }

    delete[] rows;

    return 0;
}
