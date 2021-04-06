#include "std_lib_facilities.h"

//10.1. Define the data type Point that has two coordinate members x and y.
class Point {
public:
    int x;
    int y;
};

ostream& operator<<(ostream& os, Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

int main()
try {
    //10.2. Prompt the user to input seven(x,y) pairs and store them in a vector.
    cout << "Please input seven(x,y) pairs:" << endl;
    vector<Point> original_points;
    int i = 1;
    for (i = 1; i <= 7; i++)
    {
        char ch1, ch2, ch3;
        int xx, yy;
        cin >> ch1 >> xx >> ch2 >> yy >> ch3;
        original_points.push_back(Point{xx, yy});
    }

    //10.3. Print out the original points.
    cout << "Print out the original points:" << endl;
    for (auto e : original_points)
        cout << e << " ";
    cout << endl;

    //10.4. Output the points to a file.
    string fname = "mydata.txt";
    ofstream opp{ fname };
    if (!opp) error("Cannot open file: ", fname);
    for (Point p : original_points)
        opp << p;

    //10.5. Close the ofstream and open an ifstream to further process the data.
    opp.close();
    vector<Point> processed_points;
    ifstream ipp{ fname };
    if (!ipp) error("Cannot open input file: ", fname);
    for (i = 1; i <= 7; i++)
    {
        int xx, yy;
        char ch1, ch2, ch3;
        ipp >> ch1 >> xx >> ch2 >> yy >> ch3;
        processed_points.push_back(Point{ xx,yy });
    }

    //10.6. Print out the processed points.
    cout << "Print out the processed points:" << endl;
    for (auto e : processed_points)
        cout << e << " ";
    cout << endl;

    //10.7. Compare the two vectors.
    if (original_points.size() != processed_points.size())
        cout << "Something's wrong! " << endl;
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "An error occured!" << endl;
    return 2;
}