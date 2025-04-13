#pragma once
#include <iomanip>
#include <iostream>
#include <string>
//#include "clsBankClient.h"
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>

class clsUser: public clsPerson
{
private:
	enum enMode{EmptyMode = 0, UpdateMode = 1, AddNewMode = 3};

	enMode _Mode;

	string _UserName;
	string _Pincode;
	int _Permissions;
	bool _MarkedForDelete = false;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);
		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

	}

	static string _ConvertUserObjectToLine(clsUser User, string seperator = "#//#")
	{
		string stRecordUser = "";

		stRecordUser += User.FirstName + seperator;
		stRecordUser += User.LastName + seperator;
		stRecordUser += User.Email + seperator;
		stRecordUser += User.Phone + seperator;
		stRecordUser += User.UserName + seperator;
		stRecordUser += User.Pincode + seperator;
		stRecordUser += to_string(User.Permissions);
		return stRecordUser;
	}

	static vector<clsUser> _LoadUserObjectFromFile()
	{
		vector <clsUser> vUser;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUser.push_back(User);
			}
			MyFile.close();
		}
		return vUser;


	}
	static void _SaveUserObjecttoFile(vector <clsUser> vUser)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsUser User : vUser)
			{
				if (User.MarkedForDelete() == false)
				{
					DataLine = _ConvertUserObjectToLine(User);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector<clsUser> _vUser;
		_vUser = _LoadUserObjectFromFile();

		for (clsUser& U : _vUser)
		{

			if (U.UserName == UserName)
			{
				U = *this;

			}
		}
		_SaveUserObjecttoFile(_vUser);
	}
	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();

		}

	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	static clsUser _GetEmptyUserObejct()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


public:
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string PinCode, int Permissons) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;

		_UserName = UserName;
		_Pincode = PinCode;
		_Permissions = Permissons;
	}
	bool _IsEmpty()
	{
		return (_Mode = enMode::EmptyMode);
	}
	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}
	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;
	void SetPassword(string Pincode)
	{
		_Pincode = Pincode;
	}
	string GetPassword()
	{
		return _Pincode;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Pincode;
	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	static clsUser Find(string UserName)
	{
		vector<clsUser> vUser;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObejct();
	}
	static clsUser Find(string UserName, string Pincode)
	{
		vector<clsUser> vUser;
		fstream MyFIle;
		MyFIle.open("Users.txt", ios::in);
		if (MyFIle.is_open())
		{
			string Line;
			while (getline(MyFIle, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Pincode == Pincode)
				{
					MyFIle.close();
					return User;
				}
			}
			MyFIle.close();
		}
		return _GetEmptyUserObejct();
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (_IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}
		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
		}
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User._IsEmpty());
	}
	bool Delete()
	{
		vector<clsUser> _vUser;
		_vUser = _LoadUserObjectFromFile();

		for (clsUser& U : _vUser)
		{
			if (U.UserName == _UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}
		_SaveUserObjecttoFile(_vUser);
		*this = _GetEmptyUserObejct();
		return true;

	}
	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}
	static vector <clsUser> GetUserList()
	{
		return _LoadUserObjectFromFile();
	}
};

