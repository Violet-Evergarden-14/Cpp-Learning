#include <iostream>

using namespace std;

class MyString
{
public:
	int len;
	char* str;
public:
	MyString();

	MyString(int len)
	{
		this->len = len;
		str = new char[len + 1];
		str[len] = '\0';   //硬性要求，必须封口
	}

	MyString(const char* _str)   //这里不能用str作为传参，不然不知道是谁的str
	{
		this->len = sizeof(_str) / sizeof(char) - 1;   //这里_str最后还是用'\0'封了口的，所以要减一
		str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			*(this->str + i) = *(_str + i);
		}
		*(this->str + len) = '\0';
	}

	MyString(const MyString& another)   //一般就写const MyString& another，安全且可读性好，并且可以直接修改原对象，这和char&用处一样
	{
		this->len = another.len;
		str = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
		{
			*(this->str + i) = *(another.str + i);
		}
	}

	~MyString()
	{
		delete[] str;
	}

	//reload []
	char& operator[] (int i)   //这里需要兼顾“改”这个值的问题，所以要返回引用&（若返回char，则str[i]仅是临时副本，无法直接修改原数组）
	{
		return *(this->str + i);
	}

	//reload ==
	bool operator== (const MyString& another)
	{
		if (this->len != another.len)
		{
			return false;
		} else {
			for (int i = 0; i < len; i++)
			{
				if (*(this->str + i) != *(another.str + i))
				{
					return false;
				}
			}
		}
		return true;
	}

	//reload !=
	bool operator!= (const MyString& another)
	{
		if (this->len != another.len)
		{
			return true;
		} else {
			for (int i = 0; i < len; i++)
			{
				if (*(this->str + i) != *(another.str + i))
				{
					return true;
				}
			}
		}
		return false;
	}

	//reload =
	MyString& operator= (const MyString& another)
	{
		delete[] this->str;
		this->len = another.len;
		this->str = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			*(this->str + i) = *(another.str + i);
		}
		*(this->str + len) = '\0';
		return *this;
	}

	//reload >>
	istream& operator>> (istream& is, MyString& Mstr)
	{
		//释放Mstr
		if (Mstr.str != nullptr)
		{
			delete[] Mstr.str;
			Mstr.str = nullptr;
			Mstr.len = 0;
		}
		
		//传入数据
		char temp_str[4096] = {0}; 
		cin >> temp_str;
		int length = sizeof(temp_str) / sizeof(char) - 1;
		Mstr.len = length;
		Mstr.str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			Mstr.str[i] = temp_str[i];
		}

		return is;
	}

	//reload <<
	
	//reload +
};

int main()
{
	MyString str1("1234567");
	MyString str2(str1);
	str2[0] = '5';
	cout << str2[0] << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << *(str2.str + i);
	}
	cout << endl;
	cout << (str1 == str2) << endl;
	
}