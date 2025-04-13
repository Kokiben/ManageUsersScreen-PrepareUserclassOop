#pragma once
#include <iostream>
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTiltle = "")
	{
		cout << "\t\t\t\t\t\t ______________________________________________\n";
		cout << "\n\t\t\t\t\t\t " << Title;
		if (SubTiltle != "")
		{
			cout << "\n\t\t\t\t\t " << SubTiltle;
		}
		cout << "\n\t\t\t\t\t_______________________________________________\n\n";
	}
};

