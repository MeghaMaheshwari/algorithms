#ifndef FILEPARSER_H
#define FILEPARSER_H

#include<stdio.h>
#include<string>
#include<fstream>
#include<map>
#include<sstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;


class FileParser
{
    private :

		//input Filename
		string FileName;

		//delimeter to separate RHS and LHS
		static const char SEPARATOR = '=';

		map<string,vector<string>> InputContents;

		map<string,int> OutputContents;


		vector<string> SplitString(string& ) const;
		
		bool has_only_digits(string& ) const;

		//evaluates the expression
		vector<string> Evaluate(vector<string>& , map<string,vector<string>>&);

		vector<string> getContents(string&, map<string,vector<string>>&);

		//copy constructor intentionally made private and not implemented to prohibit usage
		FileParser(const FileParser &);

		//assigment operator intentionally made private and not implemented to prohibit usage
		FileParser &operator=(const FileParser &);


	public:
		//default constructor
		FileParser(){};
		//overloaded constructor
		FileParser(string name) : FileName(name){};
		//destructor
		~FileParser(){};
		// Function to read the file line by line
		void ReadFile();

		void EvaluateExpression();

		void Print();

		

};

#endif