#include "std_lib_facilities.h"

struct Date
{
    int y, m, d;
    Date(int y, int m, int d);
    void add_day(int n);
};

Date::Date(int yy, int mm, int dd):y{yy}, m{mm}, d{dd}
{
    if (m < 1 || m > 12)
        error("Invalid month!");
    if (d < 1 || d > 31)
        error("Invalid day!");
}

void Date::add_day(int n)
{
    d += n;
    while (d > 31)
    {
        ++m;
        d -= 31;
        if (m == 13)
        {
            ++y;
            m = 1;
        }
    }
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << d.y << '-' << d.m << '-' << d.d;
}

int main()
try {
    Date today(1978, 6, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << today << '\n' << tomorrow << '\n';
    //Date bad_day (2004, 13, -5);
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Unknown error!" << endl;
    return 2;
}
