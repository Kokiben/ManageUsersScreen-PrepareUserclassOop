#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include  "clsTotalBalancesScreen.h"



class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenueOptions{eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eMainMenue = 4};
	static short ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "choose what do you want to do ? 1 to 4? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 4, "Enter number between 1 and 4?");
		return Choice;
	}
	static void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "\tPress any key to go back to transaction menue...";
		system("pause>0");
		ShowTransactionMenue();
	}

	static void _ShowDepositScreen()
	{ 
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{ 
		clsWithdrawScreen::ShowWithdrawScreen();

	}
	static void _ShowTotalBalanceScreen()
	{ 
		clsTotalBalancesScreen::ShowTotalBalance();
	}
	static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions TransactionsMenueOptions)
	{
		switch (TransactionsMenueOptions)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;

		}
		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case enTransactionsMenueOptions::eTotalBalance:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_ShowTotalBalanceScreen();
			break;
		}
		case enTransactionsMenueOptions::eMainMenue:
		{
			//do nothing here the main screen will handle it :-)
		}
		}
	}



public:
	static void ShowTransactionMenue()
	{
		_DrawScreenHeader("\t Transactions Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\tTransaction Menue \n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance .\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue. \n";
		cout << setw(37) << left << "" << "===================================\n";

		_PerformTransactionsMenueOptions((enTransactionsMenueOptions)ReadTransactionsMenueOption());
	}
};

