#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Nucleotide
{
public:
	string ID;
	int Strength;
};

void LoadFile(Nucleotide sequence[], int &nCount)
{
	ifstream fileIn("dna.txt");

	while(!fileIn.eof())
	{
		fileIn >> sequence[nCount].ID;
		fileIn >> sequence[nCount].Strength;
	
		nCount++;
	}

	fileIn.close();
}

void NucleotideReport(Nucleotide sequence[], int nCount)
{
	int countG = 0;
	int countA = 0;
	int countT = 0;
	int countC = 0;

	for(int i=0; i < nCount; i++)
	{
		if (sequence[i].ID == "A") countA++;
		if (sequence[i].ID == "G") countG++;
		if (sequence[i].ID == "T") countT++;
		if (sequence[i].ID == "C") countC++;
	}

	cout << "# of G: " << countG;
	cout << "# of A: " << countA;
	cout << "# of T: " << countT;
	cout << "# of C: " << countC;
}

void PatternSearch(Nucleotide sequence[], int nCount)
{
	string l1;
	cout << "Enter first letter: ";
	cin >> l1;

	string l2;
	cout << "Enter second letter: ";
	cin >> l2;

	string l3;
	cout << "Enter third letter: ";
	cin >> l3;

	bool found = false;

	for(int i=0 ; i < nCount - 2; i++)
	{
		if (sequence[i].ID == l1 && sequence[i+1].ID == l2 && sequence[i+2].ID == l3)
		{
			cout << "Found the sequence at position " << i << endl;
			found = true;
			break;	
		} 
	}
	
	if (found == false) 
	{
		cout << "Sequence cannot be found!" << endl;
	}
}

void StrengthFiltering(Nucleotide sequence[], int nCount)
{
	int minStrength;
	cout << "What is the minimum strength: ";
	cin >> minStrength;

	for(int i=0; i < nCount; i++)
	{
		if (sequence[i].Strength >= minStrength)
		{
			cout << sequence[i].ID;
		}
	}
}

void AverageStrength(Nucleotide sequence[], int nCount)
{
	int sum = 0;
	for(int i=0; i < nCount; i++)
	{
		sum += sequence[i].Strength;
	}
	cout << "The average is " << sum / nCount << "." << endl;
}

int main() 
{
	Nucleotide sequence[100];
	int nCount = 0;

	LoadFile(sequence, nCount);

	while(true)
	{
		cout << endl;
		cout << "1- Nucleotide Report" << endl;
		cout << "2- Pattern Search" << endl;
		cout << "3- Strength Filtering" << endl;
		cout << "4- Average Strength" << endl;
		cout << "0- Exit" << endl;
		cout << "What do you want to do?" << endl;
		int choice;
		cin >> choice;

		if (choice == 1) 
		{
			NucleotideReport(sequence, nCount);
		}
		else if (choice == 2) 
		{
			PatternSearch(sequence, nCount);
		}
		else if (choice == 3) 
		{
			StrengthFiltering(sequence, nCount);
		}
		else if (choice == 4) 
		{
			AverageStrength(sequence, nCount);
		}
		else if (choice == 0) 
		{
			break;
		}
	}

	system("PAUSE");
	return 0;
}