#include "std_lib_facilities.h"

class Date {
    int y, m, d;
public:
    Date(int y, int m, int d);
    void add_day(int n);
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
};

Date::Date(int yy, int mm, int dd) :y{ yy }, m{ mm }, d{ dd }
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
    return os << d.year() << '-' << d.month() << '-' << d.day();
}

int main()
try {
    Date today(1978, 6, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << today << endl;
    cout << tomorrow << endl;
    //Date bad_day(2004, 13, -5);
}
catch (exception& e)
{
    cerr << e.what() << endl;
    return 1;
}
catch (...)
{
    cerr << "Unknown error!" << endl;
    return 2;
}
