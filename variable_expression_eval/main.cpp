#include "FileParser.h"

using namespace std;

int main()
{
	string inputfile;

	cout << " Enter the name of the file " << "\n";

	cin >> inputfile;

	FileParser Parser(inputfile);
	Parser.ReadFile();
    Parser.EvaluateExpression();
	Parser.Print();
	

	return 0;
}