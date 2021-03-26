#include"std_lib_facilities.h"

//This function compiled.
void swap_v(int a, int b)
{
	int temp; temp = a, a = b; b = temp;
}

//This function compiled.
void swap_r(int& a, int& b)
{
	int temp; temp = a, a = b; b = temp;
}

//This function couldn't compile.
//Because we can't assign values many times to const variables a and b.
/*
void swap_cr(const int& a, const int& b)
{
	int temp; temp = a, a = b; b = temp;
}
*/

int main()
{
	int x = 7;
	int y = 9;
	swap_v (x, y); //This call compiled. They were not actually swapped.
	swap_r (x, y); //This call compiled. They were actually swapped.
	swap_v (7, 9); //This call compiled. They were not actually swapped.
	swap_r (7, 9); //This call can't compiled. Because the type doesn't match.
	const int cx = 7;
	const int cy = 9;
	swap_v (cx, cy); //This call compiled. They were not actually swapped.
	swap_r(cx, cy);  //This call can't compiled. Because the type doesn't match.
	swap_v (7.7, 9.9); //This call compiled. They were not actually swapped.
	swap_r (7.7, 9.9); //This call can't compiled. Because the type doesn't match.
	double dx = 7.7;
	double dy = 9.9;
	swap_v (dx, dy); //This call compiled. They were not actually swapped.
	swap_r(dx, dy);  //This call can't compiled¡£ Because the type doesn't match.
	swap_v (7.7, 9.9); //This call compiled. They were not actually swapped.
	swap_r (7.7, 9.9); //This call can't compiled. Because the type doesn't match.
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "cx = " << cx << endl;
	cout << "cy = " << cy << endl;
	cout << "dx = " << dx << endl;
	cout << "dy = " << dy << endl;
	return 0;
}
