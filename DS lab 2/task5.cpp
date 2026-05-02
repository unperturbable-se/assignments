#include <iostream>
using namespace std;

class Department
{
    string name;
    int courseCount;
    float* gpas;

public:
    Department(string deptName, int count) : name(deptName), courseCount(count)
    {
        gpas = new float[courseCount];
    }

    void inputGPA()
    {
        cout << "Enter GPA for " << courseCount << " core courses in " << name << ":\n";
        for (int i = 0; i < courseCount; i++)
        {
            cout << "  Course " << i + 1 << ": ";
            cin >> gpas[i];
        }
    }

    void displayGPA()
    {
        cout << name << ": ";
        for (int i = 0; i < courseCount; i++)
        {
            cout << gpas[i] << " ";
        }
        cout << endl;
    }

    ~Department()
    {
        delete[] gpas;
    }
};

int main()
{
    Department departments[] = 
    {
        Department("SE", 3),
        Department("AI", 4),
        Department("CS", 2),
        Department("DS", 1)
    };

    for (int i = 0; i < 4; i++)
    {
        departments[i].inputGPA();
    }

    cout << "\n--- GPA Summary ---\n";
    for (int i = 0; i < 4; i++)
    {
        departments[i].displayGPA();
    }

    return 0;
}
