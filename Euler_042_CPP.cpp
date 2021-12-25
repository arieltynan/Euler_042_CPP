// Euler_042_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Using words.txt, a 16K text file containing nearly two-thousand common English words, how many are triangle words?


#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> genTriNums(int n)
{
    vector<int> vect;
    int triNum = 1;
    for (int i = 1; i < n; i++)
    {
        triNum = 0.5 * i * (i + 1);
        vect.push_back(triNum);
        cout << triNum << " ";
    }
    return vect;
}

int main()
{
    
    // generate triangle numbers
    int n = 100;
    vector<int> tri = genTriNums(n);
    
    
    ifstream fin;
    string fileName = "p042_words.txt";
    fin.open(fileName.c_str());

    //if file is not found, print error statement
    if (!fin)
    {
        cout << "Cannot open " << fileName << endl;
        exit(1);
    }
    else
        cout << "File is open" << endl;

    string oneString;
    int i = 0;
    while (fin)
    {
        string x;
        fin >> oneString;
        //oneString.push_back(x);
        //cout << oneString << endl; //prints names
    }
    vector<string> vectList; //list of substrings
    stringstream ss(oneString);
    int count = 0;
    while (ss.good()) //split oneString into substrings of each word
    {
        string substr;
        getline(ss, substr, ',');
        substr.erase(remove(substr.begin(), substr.end(), '\"'), substr.end());
        vectList.push_back(substr);
        count++;
        //cout << substr << " ";
    }
    int wordVal = 0;
    int numTriWords = 0; // number of triangle words
    for (int i = 0; i < vectList.size(); i++) //find word val of each substr word
    {
        bool exists = false;
        for (int j = 0; j < vectList[i].size(); j++)
            wordVal = wordVal + (vectList[i][j] - 64); //add values of chars
        //cout << wordVal << " ";
        if (find(tri.begin(), tri.end(), wordVal) != tri.end() == true)       // find wordVal in list of triangle numbers
            exists = true;
        if (exists == true)
        {
            cout << vectList[i] << " " << wordVal << endl;
            numTriWords++;
        }
        wordVal = 0;
    }
    cout << "The number of triangle words is: " << numTriWords << endl;

}
