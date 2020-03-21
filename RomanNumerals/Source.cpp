#include <iostream>
#include <string>
#include <stack>
#include <sstream>


using namespace std;

int convertNumer(string numerals)
{
	char I = 1;
	char V = 5;
	char X = 10;
	char L = 50;
	char C = 100;
	int D = 500;
	int M = 1000;

	int i = static_cast<int>(I);
	int v = static_cast<int>(V);
	int x = static_cast<int>(X);
	int l = static_cast<int>(L);
	int c = static_cast<int>(C);
	int d = static_cast<int>(D);
	//int m = static_cast<int>(M);
	
	stack<int> romanStack;
	
	istringstream iss(numerals);
	
	stack<int> addStack;

	int numOne = 0;
	int numTwo = 0;
	int total = 0;
	int temp = 0;
	
	for (int i = 0; i < numerals.size(); ++i)         //StringStream and find matching values for each numeral
	{
		if (numerals[i] == 'I')
		{
			romanStack.push(I);
		}
		else if (numerals[i] == 'V')
		{
			romanStack.push(V);
		}
		else if (numerals[i] == 'X')
		{
			romanStack.push(X);
		}
		else if (numerals[i] == 'L')
		{
			romanStack.push(L);
		}
		else if (numerals[i] == 'C')
		{
			romanStack.push(C);
		}
		else if (numerals[i] == 'D')
		{
			romanStack.push(D);
		}
		else if (numerals[i] == 'M')
		{
			romanStack.push(M);
		}

		numOne = romanStack.top();  //Add numerals onto a stack
		romanStack.pop();
		addStack.push(numOne);


		

		
	}
	for (unsigned int j = 0; j < addStack.size(); ++j)
	{
		if (addStack.size() == 1)     //If only one in stack, output it
		{
			return numOne;
		}
		else if (addStack.size() % 2 == 1)        //If three, do different comparison
		{
			numOne = addStack.top();
			addStack.pop();
			numTwo = addStack.top();
			addStack.pop();
			int num3 = addStack.top();
			addStack.pop();
			
			if (num3 >= numTwo)
			{
				temp += num3;
				if (numTwo >= numOne)
				{
					temp += numTwo + numOne;
				}
				else if (numOne > numTwo && (numTwo % 10 == 1))  //Test for valid division
				{
					temp += numOne - numTwo;
				}
				else
				{
					cerr << "Error: Not Possible" << endl;
					return -5;
				}
			}
			else if (num3 < numTwo)
			{
				temp += numTwo - num3;
				temp += numOne;
			}

		}
		else                //Else, still compare
		{
			numOne = addStack.top();
			addStack.pop();
			numTwo = addStack.top();
			addStack.pop();

			if (numTwo >= numOne)
			{
				temp = numTwo + numOne;
			}
			else if (numOne > numTwo ) //&& (numTwo % 10 == 1))  //Test for valid division
			{
				temp = numOne - numTwo;
			}
			else  
			{
				cerr << "Error: Not Possible";
				return -5;
				
			}
		}
		total += temp;
	}



	return total;
}






int main()
{

	string userNumer;
	
	
	cout << "Enter the Roman Numerals you would like to calculate:" << endl;
	getline(cin, userNumer);              //Get Input
	try {
		//convertNumer(userNumer);
		if ((convertNumer(userNumer) == -5) && userNumer != "I" && userNumer != "V" && userNumer != "X" && userNumer != "L" && userNumer != "C" && userNumer != "D" && userNumer != "M")
		{
			string userError = " Invalid Operation or Input";
			throw userError;
		}
		else
		{
			cout << "The Roman Numerals " << userNumer << " is equal to: " << convertNumer(userNumer);
		}
	}
	catch (string userError)
	{
		cout << userError;
	}
	




}

