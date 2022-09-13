#include <string>
#include <fstream>
#include <iostream>
#include<algorithm>
#include<map>


void count(const std::string const& s, std::map<char,int> & counter)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		auto found = counter.find(s[i]);
		if (found != counter.end())
		{
			found->second = 1;
		}
		else 
		{
			counter.insert(std::make_pair(s[i], 0));
		}

	}


}

void charToBracket(std::string & s , const std::map<char, int> const& counter)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		auto found = counter.find(s[i]);
		if (found->second == 1)
		{
			s[i] = ')';
		}
		else 
		{
			s[i] = '(';
		}
	}
}

//��� ���������� ������ ���������� ������� ���� "in.txt" � ������ ���� �������� ������
int main()
{
	std::ifstream infs;
	std::ofstream offs;
	std::string s;
	std::map<char,int> counter;


	infs.open("in.txt");
	if (infs.is_open())
	{
		getline(infs, s);
		infs.close();
		//���������� � ������� ��������
		std::transform(s.begin(), s.end(), s.begin(), tolower);
		//������� ��������
		count(s, counter);
		//�������������� �������� � �������
		charToBracket(s, counter);
	}


	offs.open("out.txt");
	offs << s;
	offs.close();
	return 0;
}