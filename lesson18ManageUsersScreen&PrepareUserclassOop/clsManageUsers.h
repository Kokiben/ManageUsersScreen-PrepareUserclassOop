#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsManageUsers : protected clsScreen
{
private:
	enum enManageUsersMenueOption{eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6};
	static short ReadManageUserMenueOption()
	{
		cout << setw(37) << left << "" << "choose what do you want to do ? 1 to 6";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6, "ENter number between 1 and 6");
		return choice;
	}
	static void _GoBackToManageUsersMenue()
	{
		cout << "\n Press any key to go Back to Manage Users Mneue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowAllListUsers()
	{}
	static void _ShowAddNewUsersScreen()
	{}
	static void _ShowDeleteUserScreen()
	{}
	static void _ShowUpDateUserScreen()
	{}
	static void _ShowFindUserScreen()
	{}

	static void _PerformManageUsersMenueOptions(enManageUsersMenueOption ManageUsersMenueOptions)
	{
		switch (ManageUsersMenueOptions)
		{
		case enManageUsersMenueOption::eListUsers:
		{
			system("cls");
			_ShowAllListUsers();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eUpdateUser:
		{
			system("cls");
			_ShowUpDateUserScreen();
			_GoBackToManageUsersMenue();
				break;

		}
		case enManageUsersMenueOption::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eMainMenue:
		{
			//do nothing here the main screen will handl it :-);

		}
		}
	}




public:
	static void ShowManageUsersMenue()
	{
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");
		
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "\tManage Users Manue";
		cout << setw(37) << left << "" << "\n==========================================\n";
		cout << setw(37) << left << "" << "\t[1] All list users. \n";
		cout << setw(37) << left << "" << "\t[2] Add New User. \n";
		cout << setw(37) << left << "" << "\t[3] Dlelete User. \n";
		cout << setw(37) << left << "" << "\t[4] Update User . \n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerformManageUsersMenueOptions((enManageUsersMenueOption)ReadManageUserMenueOption());
	}
};

