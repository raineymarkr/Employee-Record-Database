#include <iostream>
#include <string>
#include <list>

using namespace std;

class emp_rec {
private:


public:

    string last_name;
    string first_name;
    int agep;
    int job_level;
    friend ostream &operator<<(ostream &os, emp_rec &emp1);

    emp_rec() {cout << "Must include all data in format last, first, age, job level" << endl;}
    emp_rec(string last, string first, int age, int level) {set(last_name, first_name, age, job_level);}

    void set(string last, string first, int age, int level){
    last_name = last; first_name = first; agep = age; job_level = level;}
    string get_last() {return last_name;}
    string get_first() {return first_name;}
    int get_age() {return agep;}
    int get_job_level() {return job_level;}
    bool lessthan(emp_rec other);
    bool operator<(const emp_rec &other)
        {
            return lessthan(other);
        }
    bool operator==(emp_rec other);
    void print();
};

int main(int argc, char *argv[])
{
    emp_rec emp1;
    string last, first; int age = 0, level = 0, more;
    list<emp_rec> employees;
    list<emp_rec>::iterator iter;

do {
cout << "Insert Last Name (ENTER to end input.) :" << endl;
getline(cin, last);
    if(last.length() == 0)
        break;

cout << "Insert First Name" << endl;
getline(cin, first);

cout << "Insert Age" << endl;
cin >> age;
cin.ignore(1,'\n');

cout << "Insert Job Level" << endl;
cin >> level;
cin.ignore(1,'\n');

emp1.set(last, first, age, level);
employees.push_back(emp1);
}
while(true);


employees.sort();

for (iter = employees.begin(); iter != employees.end(); iter++)
    cout << *iter << endl;

return 0;

}
bool emp_rec::lessthan(emp_rec other) {
    if (last_name < other.last_name)
        {
        return true;
        }
        else if (first_name < other.first_name)
        {
            return true;
        }
           else if(job_level < other.job_level)
           {
               return true;
           }
           else if(agep < other.agep)
           {
                return true;
           }
        else {return false;}
}

bool emp_rec::operator==(emp_rec other) {
    return (first_name==other.first_name && last_name==other.last_name && job_level == other.job_level && agep == other.agep);
    }

ostream &operator<<(ostream &os, emp_rec &emp) {
os << emp.first_name << " " << emp.last_name << ", Age: " << emp.agep << ",Job Level: " << emp.job_level;}
