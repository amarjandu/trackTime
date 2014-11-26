#include<iostream>
#include<fstream>
#include<iomanip>
#include "Racer.h"
#include "BinarySearchTree.h"
#include "HashedDictionary.h"
#include "LinkedList.h"


using namespace std;

const int MAX_ENTRIES = 200;

bool readFile(HashedDictionary<string, Racer>* dict, string *&stringPtr, 
			  string &inputFileName, int &numElem);
void display(Racer &rc);


int main()
{
    HashedDictionary<string, Racer>* racerDictionary = new HashedDictionary<string, Racer>();
	string inputFile;
	string inputStr;
	string *stringArr = nullptr;
	int numElem = 0;
	bool boolVar = false;
	int tempCount = 0;

	if(readFile(racerDictionary, stringArr, inputFile, numElem))
	  racerDictionary->traverse(display);

  return 0;
}



void display(Racer &rc)
{
	cout << rc.getName() << endl;
	cout << rc.getIdNum() << endl;
	cout << rc.getCircuitName() << endl;
	cout << rc.getDate() << endl;
	cout << rc.getFinishTime() << endl << endl;
}


// The readFile function has three reference parameters.
// The function saves the filename of the file it opens to the
// reference string parameter (in case saving file on exit needs to be 
// implemented). The function creates a string array of the data 
// contained in the input text file and then sets the reference
// string pointer variable to point to that array. The number of
// elements saved to the string array is saved to the int reference
// parameter. The function returns true if the file is read and false
// if the file fails to open or the string array is empty.
bool readFileHash(HashedDictionary<string, Racer>* dict, string *&stringPtr, 
				  string &inputFileName, int &numElem)
{
	ifstream inFile;
	string readString;
	bool notEmpty = false;
	string *stringArr = new string[MAX_ENTRIES]();
	int i = 0;

	inFile.open("inputRacer.txt");
	if(!inFile)
	{
		cout << "Error opening racer.txt Closing...\n";
		return notEmpty;
	}
	else
		inputFileName = "inputRacer.txt";
	while(getline(inFile, readString) && i < MAX_ENTRIES)
	{
		stringArr[i] = readString;
		Racer *newRacer = new Racer(stringArr[i]);
		++i;
		if(getline(inFile, readString) && i < MAX_ENTRIES)
		{
			stringArr[i] = readString;
			newRacer->setIdNum(stringArr[i]);
			++i;
		}
		if(getline(inFile, readString) && i < MAX_ENTRIES)
		{
			stringArr[i] = readString;
			newRacer->setCircuitName(stringArr[i]);
			++i;
		}
		if(getline(inFile, readString) && i < MAX_ENTRIES)
		{
			stringArr[i] = readString;
			newRacer->setDate(stringArr[i]);
			++i;
		}
		if(getline(inFile, readString) && i < MAX_ENTRIES)
		{
			stringArr[i] = readString;
			newRacer->setFinishTime(stringArr[i]);
			++i;
		}
		dict->add(newRacer->getIdNum(), *newRacer);
	}

	if(stringArr[0].empty())
		return notEmpty;
	else
		notEmpty = true;


	stringPtr = stringArr;
	numElem = i;
	return notEmpty;
}
