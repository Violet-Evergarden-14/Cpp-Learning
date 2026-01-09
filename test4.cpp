#include <iostream>
#include <string>
#include <sstream>
using namespace std;

enum Gender
{
	Male,
	Female
};

enum Major
{
	Computer,
	Math,
	Economics
};

class Date
{
private:
	/* data */
public:
	int year;
	int month;
	int day;
};

class Person
{
protected:
	int id;
	string name;
	Gender gender;
	Date birthday;
public:
	Person()   //default function
	{
		id = 0;
		name = "";
		gender = Male;

		Date date;
		date.year = 2020;
		date.month = 1;
		date.day = 1;
		birthday = date;
	}
	
	Person(int _id, string _name, Gender _gender, Date _birthday)
	{
		id = _id;
		name = _name;
		gender = _gender;
		birthday = _birthday;
	}

	void toPrint()
    {
        cout << "Person(" <<//
             "id:" << id << //
             ", name:" << name <<//
             ", gender:" <<   (gender==Male?"Male":"Female")  <<//
             ", birthday:" << birthday.year <<"-" << birthday.month << "-"<< birthday.day <<//
             ")" << endl;
    }

	void setID( int _id)
    {
        this->id = _id;
    }
    int getID()
    {
        return id;
    }

    void setName(string _name)
    {
        this->name = _name;
    }
    string getName()
    {
        return name;
    }

    void setGender(Gender _gender)
    {
        this->gender = _gender;
    }
    Gender getGender()
    {
        return gender;
    }

    void setBirthday(Date _birthday)
    {
        this->birthday = _birthday;
    }
    Date getBirthday()
    {
        return birthday;
    }

};

class Department
{
public:
    int id;
    string name;

    string toString()
    {
        stringstream str_stream;
        str_stream << "(DEPT ID:"  << id//
                   << "; NAME: " <<  name << ")";

        return str_stream.str();
    }
};
