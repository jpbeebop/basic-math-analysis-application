#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <cmath>
using namespace std;


/**
    findLastComma - find and return last comma position in a string

    find the last comma position in a string and return the position as
    an integer.

    parameter: string aString

    return: int position

    name: chengjiapao

*/
int findLastComma(string aString){

    int position;

    for(int i = 0; i < aString.length()-1; ++i){

        if(aString[i] == ',')
            position = i;  // record the the comma
    }

    return position;
}


/**
    getLastColumn - find and return last column before the last comma in a record string

    parameter: string aString

    return: string lastColumn

    name: chengjiapao
*/
string getLastColumn(string aString){

    string lastColumn;

    //i is the position of the last comma
    for(int i = findLastComma(aString)+1; i < aString.length(); ++i){

        lastColumn += aString[i]; //string after the last column is stored in lastColumn string
    }

    return lastColumn;

}


/**
    constructVectors - construct a complete vector by concatenation

    concatenate data into temp until a comma, push back temp into vector

    parameter: string aString

    return: aVector, tableHeaderVector

    name: chengjiapao
*/
vector<string> constructVectors(string aString){

    string temp;

    vector<string> aVector;

    vector<string> tableHeaderVector;

        for(auto x : aString){

            // if char x != comma, concatenate x to temp
            if(x != ',')

                temp += x;

            // if char x == comma, string temp is put into aVector
            else if(x == ','){

                aVector.push_back(temp);

                temp = "";
            }

        }

        // get the last column string to complete aVector
        aVector.push_back(getLastColumn(aString));

        for(auto x: aVector){

            cout << x << endl;
        }

    return aVector; // return the complete vector containing digit

}


/**
    checkColumn - check if number of column in csv file match the format

    parameter: vector<string> &aVector , int columnNumber

    return: columnNumber as aVector.size()

    name: chengjiapao
*/
bool checkColumn(vector<string> &aVector, int columnNumber){

    return aVector.size() == columnNumber;
}


/**
    checkRow - check if number of row in csv file match the format

    parameter: vector<string> &aVector , int rowNumber

    return: rowNumber as (aVector.size()-1)

    name: chengjiapao
*/
bool checkRow(vector<vector<string>> &aVector, int rowNumber){

    return (aVector.size() - 1) == rowNumber;
}


/**
    convertStringToInt - convert a string into integer

    parameter: string astring

    return: aNum

    name: chengjiapao
*/
int convertStringToInt(string aString){

    int aNum;

    stringstream aStream(aString);

    aStream >> aNum;

    return aNum;

}


/**
    getMin - find the minimum value in a column

    parameter: vector<vector<string>> &aVector , int columnNumber

    return: smallest

    name: chengjiapao
*/
int getMin(vector<vector<string>> &aVector, int columnNumber){

    int smallest = convertStringToInt(aVector[1][columnNumber]);

    for(int i = 1; i <= aVector.size()-1; ++i){

        if(convertStringToInt(aVector[i][columnNumber]) < smallest)

            smallest = convertStringToInt(aVector[i][columnNumber]);
    }

    return smallest;
}


/**
    getMax - find the maximum value in a column

    parameter: vector<vector<string>> &aVector , int columnNumber

    return: largest

    name: chengjiapao
*/
int getMax(vector<vector<string>> & aVector, int columnNumber){

    int largest = convertStringToInt(aVector[1][columnNumber]);

    for (int i = 1 ; i <= aVector.size()-1; ++i){

        if(convertStringToInt(aVector[i][columnNumber]) > largest)

            largest = convertStringToInt(aVector[i][columnNumber]);
    }

    return largest;
}


/**
    getMean - find the mean of a column

    find the total value of the column,

    divide it with (size of the column minus one) to get mean

    parameter: vector<vector<string>> aVector , int columnNumber

    return: mean

    name: chengjiapao
*/
double getMean(vector<vector<string>> &aVector, int columnNumber){

    int total = 0;

    for (int i = 1; i<= aVector.size()-1; ++i){

        total += convertStringToInt(aVector[i][columnNumber]);
    }

    double mean = static_cast<double>(total) / (aVector.size()-1); //cast int total to double total

    cout << setprecision(2) << showpoint <<fixed;

    return mean;

}

void swap(vector<string> firstVector, vector<string>secondVector, int columnNumber){

    string temp = firstVector[columnNumber];

    firstVector[columnNumber] = secondVector[columnNumber];

    secondVector[columnNumber] = temp;

}


void sortVectorAscendingly(vector<vector<string>> &aVector, int columnNumber){

    int maxElement;

    int index;

    for (maxElement = aVector.size()-1; maxElement > 0; maxElement--){

        cout << "maxElement: " << maxElement << endl;

        for (index = 1 ; index <= maxElement ; ++index){

            cout << endl;

            cout << "index: " << index << endl;

            int firstData = convertStringToInt(aVector[index][columnNumber]);

            int secondData = convertStringToInt(aVector[index+1][columnNumber]);

            if (firstData > secondData)

                swap(aVector[index], aVector[index+1],columnNumber);

                cout << convertStringToInt(aVector[index][columnNumber]) << " ";

        }

        cout <<endl << endl;

        //cout << convertStringToInt(aVector[index][columnNumber]) << " ";


    }

    cout << endl;

    for (int index = 1 ; index <= aVector.size()-1; ++index){

        cout << convertStringToInt(aVector[index][columnNumber]) << " ";

    }

}


/**
    getVariance - find the variance of a column

    get the mean, minus each value in each column with mean,

    compute each value raise to the base exponent of 2, add all value

    parameter: vector<vector<string>> aVector , int columnNumber

    return: variance

    name: chengjiapao
*/
double getVariance(vector<vector<string>> &aVector, int columnNumber){

    double variance, vectorElement;

    double mean = getMean(aVector, columnNumber); //get mean from the getMean function

    for (int i = 1; i <= aVector.size()-1; ++i){

        vectorElement = convertStringToInt(aVector[i][columnNumber]) - mean; //each value minus mean

        variance += pow(vectorElement,2); //raise the value to base exponent of 2

    }

    variance = variance/ (aVector.size()-1); //divide with (size of vector minus 1)

    return variance;

}


/**
    getStandardDeviation - find the standard deviation of a column

    get the variance, compute the square root of the variance

    parameter: vector<vector<string>> aVector , int columnNumber

    return: standard deviation

    name: chengjiapao
*/
double getStandardDeviation(vector<vector<string>> &aVector, int columnNumber){

    double standardDeviation;

    double variance = getVariance(aVector, columnNumber);

    standardDeviation = sqrt(variance); // standard deviation is the square root of variance

    return standardDeviation;

}


/**
    readCSV - read a CSV file

    read a CSV file after prompt user to input CSV file name

    name: chengjiapao
*/
void readCSV(){

    string line, csvItem;

    vector<vector<string>> aVectorOfVector;

    ifstream myfile("data.csv");

    int lineNumber = 0;

    int firstLine = 1; //this line shows the number of column

    int thirdLine = 3; //this line shows the number of row

    int columnNumber;

    int rowNumber;

    if(myfile.is_open()){

        while(getline(myfile,line)){


            lineNumber++;


            if(lineNumber == firstLine){

                columnNumber = convertStringToInt(line);

            }


            if(lineNumber == thirdLine){

                rowNumber = convertStringToInt(line);
            }


            if(lineNumber != firstLine && lineNumber != thirdLine){

                aVectorOfVector.push_back(constructVectors(line));

            }

        }
    }

    cout << "Column : " << columnNumber << " Row number: " << rowNumber << endl;

    cout << "check column: " << checkColumn(aVectorOfVector[1],columnNumber) << endl; //check format of column number

    cout << "check rows: " << checkRow(aVectorOfVector, rowNumber) << endl; //check format of row number


    if(checkColumn(aVectorOfVector[1],columnNumber) && checkRow(aVectorOfVector, rowNumber )){

       // do process

       int AgeColumn = 1;

       int smallest = getMin(aVectorOfVector,AgeColumn);

       cout << "The minimum number is: " << smallest << endl;


       int largest = getMax(aVectorOfVector,AgeColumn);

       cout << "The maximum number is: " << largest << endl;


       double mean = getMean(aVectorOfVector,AgeColumn);

       cout << "The mean is: " << mean << endl;


       double variance = getVariance(aVectorOfVector, AgeColumn);

       cout << "Variance is: " << variance << endl;


       double standardDeviation = getStandardDeviation(aVectorOfVector, AgeColumn);

       cout << "Standard Deviation is: " << standardDeviation << endl;


       cout << endl << "hi"<< endl;

       //sortVectorAscendingly(aVectorOfVector, 2);

       cout << "hi"<< endl;


    }
    else{

      // exit to menu (cout menu)
    }
}


int main()
{

    readCSV();

    return 0;

}
