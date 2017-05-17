#include "FileParser.h"

void FileParser::ReadFile()
{
	bool ReturnVal = true;

	ifstream fin(FileName);
	
	try
	{

		if (!fin.good())  {
			//throw an exception if file could not be opened
			throw " Unable top open file " + FileName;			
		}

		// read each line of the file
		while (!fin.eof())
		{
			string LHS, RHS;
			getline(fin, LHS, SEPARATOR);
			getline(fin, RHS);
			//remove spaces from LHS and RHS
			auto space = [](unsigned char const c){return isspace(c);};
			LHS.erase(std::remove_if(LHS.begin(), LHS.end(), space), LHS.end());
			RHS.erase(std::remove_if(RHS.begin(), RHS.end(), space), RHS.end());

			InputContents[LHS] = SplitString(RHS);
		
		}             

		fin.close();
		
	}
	catch(string ex)
	{
		cout << ex;
	}

}

void FileParser::Print()
{
	//the return value is stored in an ordered map so that sorting is not needed
	map<string,int>::iterator it;

	for(it = OutputContents.begin(); it != OutputContents.end(); it++)
	{
		cout << it->first << " = " << it->second << "\n";
	}

}
//Evaluates the expression to get the final sum. 
void FileParser::EvaluateExpression()
{
	map<string,vector<string>>::iterator it;

	map<string,int> ReturnVal;

	int i = 0;
	
	for(it = InputContents.begin(); it != InputContents.end(); it++)
	{
		
		vector<string> contents = it->second;
		contents = Evaluate(contents, InputContents);
		InputContents[it->first] = contents;
		
	}
	//get the final output
	for(it = InputContents.begin(); it != InputContents.end(); it++)
	{
		int sum = 0;
		vector<string> contents = it->second;
		for(int i = 0; i < contents.size(); i++)
		{
			
				sum = sum + std::stoi (contents[i],nullptr,0);
		}
	    OutputContents[it->first] = sum;	
	}	
}


//Evaluates the expression to retreive values for characters from the map
vector<string> FileParser::Evaluate(vector<string>& contents, map<string,vector<string>>& InputContents) 
{
	int sum = 0;
	vector<string> newcontent;
	for(int i = 0; i < contents.size(); i++)
	{
		vector<string> val;
		if(!has_only_digits(contents[i]))
		{
			val = getContents(contents[i],InputContents);			
			newcontent.insert(newcontent.end(),val.begin(),val.end());
		}
		else
		{
			newcontent.push_back(contents[i]);
		}
	}

	return newcontent;
}

//recursively gets ges the value of variables
vector<string> FileParser::getContents(string& cur_token, map<string,vector<string>>& InputContents)
{
	vector<string>cur_values = InputContents[cur_token];
	vector<string> final_ret;

    for(int j = 0; j < cur_values.size(); j++)
	{
		if(!has_only_digits(cur_values[j]))
		{
			vector<string> ret = getContents(cur_values[j],InputContents);
			final_ret.insert(final_ret.end(),ret.begin(),ret.end());
		}
		else
		{
			final_ret.push_back(cur_values[j]);
		}
	}

	return final_ret;
}

//splits a string based on +
vector<string> FileParser::SplitString(string& s) const
{	
	vector<string> values;

	std::string delimiter = "+";
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);
		
		values.push_back(token);		
		s.erase(0, pos + delimiter.length());
	}
	values.push_back(s);
	
	return values;
}

//checks if an expression has only digits.

bool FileParser::has_only_digits(string& s) const
{
		return (s.find_first_not_of( "0123456789" ) == string::npos);
}