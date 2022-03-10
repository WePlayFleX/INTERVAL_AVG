#include <iostream>

using namespace std;

const int MAX = 100;

class Distance
{
private:
	int feet;
	float inches;

public:
	Distance()
	{
		feet = 0;
		inches = 0;
	}

	Distance(int ft, float in)
	{
		feet = ft;
		inches = in;
	}

	void getdist()
	{
		cout << "Enter number of feet: ";
		cin >> feet;
		cout << "Enter number of inches: ";
		cin >> inches;
	}

	void showdist()const
	{
		cout << feet << "\'-" << inches << '\"';
	}

	void add_dist(Distance, Distance);
	void div_dist(Distance, int);
};



int main()
{
	Distance distarr[MAX];
	Distance total(0, 0.0), average;
	int count = 0;
	char ch;

	do
	{
		cout << "\nEnter distance ";
		distarr[count++].getdist();
		cout << "\nProceed (y/n)?";
		cin >> ch;
	} while (ch != 'n');

	for (size_t i = 0; i < count; i++)
	{
		total.add_dist(total, distarr[i]);	
	}

	average.div_dist(total, count);
	cout << "\nThe average: ";
	average.showdist();

	cout << endl;

	system("pause");
	return 0;
}

void Distance::add_dist(Distance d2, Distance d3)
{
	inches = d2.inches + d3.inches;
	feet = 0;

	if (inches >= 12.0)
	{
		inches -= 12.0;
		feet++;
	}

	feet += d2.feet + d3.feet;
}

void Distance::div_dist(Distance d2, int divisor)
{
	float fltfeet = d2.feet + d2.inches / 12.0;
	fltfeet /= divisor;
	feet = int(fltfeet);
	inches = (fltfeet - feet) * 12.0;
}