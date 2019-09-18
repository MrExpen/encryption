#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

string letters = "\t\n !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~‘‹’“”«¹";

int myfind(char c)
{
	for (int i = 0; i < letters.length(); i++)
	{
		if (letters.at(i) == c)
			return i;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string file_name_in = "in.txt";
	string file_name_out = "out.txt";
	string text;
	string buffer;
	ifstream fin;
	ofstream fout;
	char k;

	fin.open(file_name_in);
	getline(fin, text);
	while (!fin.eof())
	{
		getline(fin, buffer);
		text += "\n" + buffer;
	}
	fin.close();

	string Password;
	cout << "Password: ";
	getline(cin, Password);

	fout.open(file_name_out);

	for (int i = 0; i < text.length(); i++)
	{
		k = letters.at((myfind(text.at(i)) + myfind(Password.at(i % Password.length()))) % letters.length());

		fout << k;
	}
	fout.close();
}