#include "std_lib_facilities.h"

struct Date 
{
    int y;
    int m;
    int d;
};

void init_day(Date& dd, int y, int m, int d)
{
    if (m < 1 || m > 12)
        error("Invalid month!");
    if (d < 1 || d > 31)
        error("Invalid day!");
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n)
{
    dd.d += n;
    while(dd.d > 31)
    {
        ++dd.m;
        dd.d -= 31;
        if (dd.m == 13)
        {
            ++dd.y;
            dd.m = 1;
        }
    }
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << d.y << '-' << d.m << '-' << d.d;
}

int main()
try {
    Date today;
    init_day(today, 1978, 6, 25);
    Date tomorrow = today;
    add_day(tomorrow, 1);
    cout << today << '\n' << tomorrow << '\n';
    //Date bad_day;
    //init_day(bad_day, 2004, 13, -5);
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
