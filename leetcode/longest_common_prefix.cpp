//Write a function to find the longest common prefix string amongst an array of strings.

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

int Compare(string, string);

int main()
{
	string values[] = {"a","b"};

	int n = sizeof(values)/sizeof(values[0]);
 
    sort(values, values+n);

	string tocompare = values[0];
	int min_len = tocompare.length();
	for(int i = 1; i < n; i++)
	{
		string cur_val = values[i];
		int len = 0;
		int j = 0;
		while(tocompare[j] == cur_val[j])
		{
			len++;
			j++;

			if(j == tocompare.length())
			{
				break;
			}
		}

		min_len = (len < min_len) ? len : min_len;
	}

	string longest = tocompare.substr(0,min_len);

}

int Compare(string base_str, string cur_val)
{
	int len = 0;
	int j = 0;

	while(base_str[j] == cur_val[j])
	{
		len++;
		j++;

		if(j == base_str.length())
		{
			break;
		}
	}
	return len;
}