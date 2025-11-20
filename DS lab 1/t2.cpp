#include <iostream>
using namespace std;

class Exam
{
private:
    string* studentName;
    string* examDate;
    float* score;

public:
    Exam()
    {
        studentName = new string("");
        examDate = new string("");
        score = new float(0.0f);
    }

    ~Exam()
    {
        delete studentName;
        delete examDate;
        delete score;
        cout << "Destructor called.\n";
    }

    void setDetails(const string& name, const string& date, float sc)
    {
        *studentName = name;
        *examDate = date;
        *score = sc;
    }

    void display() const
    {
        cout << "Student Name: " << *studentName << "\n";
        cout << "Exam Date: " << *examDate << "\n";
        cout << "Score: " << *score << "\n";
    }
};

int main()
{
    Exam exam1;
    exam1.setDetails("Alice", "2025-08-23", 92.5f);

    cout << "Original Exam Details:\n";
    exam1.display();

    Exam exam2 = exam1;

    cout << "\nCopied Exam Details:\n";
    exam2.display();

    return 0;
}

//destructor will be called only once (: