#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;


void showMenu()
{
    cout << "\tWelcome to Academic Report System" << endl;

    cout << "\t=================================" << endl << endl << endl;

    cout << "\t*****  Load file to proceed  ****" << endl;

    cout << "\tEnter file name: ";

}


void showSubmenu()
{
    cout << "     Welcome to Academic Report System"       << endl;

    cout << "============================================" << endl;

    cout << "\t1. \tCompute Statistics"                    << endl;

    cout << "\t2. \tGenerate HTML report"                  << endl;

    cout << "\t3. \tExit"                                  << endl;

    cout << "============================================" << endl;

}


void showComputeStatisticsMenu()
{
    cout << "            Compute Statistics"             << endl;

    cout << "==========================================" << endl;

    cout << "\t1.View by Subject"                        << endl;

    cout << "\t2.View all Subjects Report"               << endl;

    cout << "\t3.Compare Subjects"                       << endl;

}


void showSubjectsList()
{
    cout << "          Subjects List  "          << endl;

    cout << "==================================" << endl;

    cout << "\t1. Mathematics"                   << endl;

    cout << "\t2. Science"                       << endl;

    cout << "\t3. Bahasa Melayu"                 << endl;

    cout << "\t0. Back to Main Menu"             << endl;
}


void showTypesOfStatistics()
{
    cout << "\t\tTypes of statistics"                         << endl;

    cout << "===============================================" << endl;

    cout << "\t1. Minimum mark"                               << endl;

    cout << "\t2. Maximum mark"                               << endl;

    cout << "\t3. Median"                                     << endl;

    cout << "\t4. Mean"                                       << endl;

    cout << "\t5. Variance"                                   << endl;

    cout << "\t6. Standard deviation"                         << endl;

    cout << "\t7. Marks Frequency Distribution"               << endl;

    cout << "\t8. Plot Histogram"                             << endl;

    cout << "\t9. Marks Above/ Below mean"                    << endl;

    cout << "\t0. Back to View by Subject"                    << endl;

    cout << "===============================================" << endl;
}


void showCompareSubjectsMenu()
{
    cout << "               Compare Subjects"               << endl;

    cout << "=============================================" << endl;

    cout << "\t1. Linear Regression"                        << endl;

    cout << "\t2. Pearson's correlation"                    << endl;

    cout << "\t0. Back to Compute Statistics"               << endl;

}


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

    construct and return a complete vector

    parameter: string aString

    return: aVector

    name: chengjiapao
*/
vector<string> constructVectors(string aString){

    string temp;

    vector<string> aVector;

         for(auto x : aString){

            // if char x != comma, concatenate x to temp
            if(x != ',')

                temp += x;

            // if char x == comma, string temp is push into aVector
            else if(x == ','){

                aVector.push_back(temp);

                temp = "";
            }


        }

        // push back the mark in the last column to complete aVector
       aVector.push_back(getLastColumn(aString));

       for(auto x: aVector){

          cout << x << endl;
       }

        return aVector; // return the complete vector

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

    return: rowNumber

    name: chengjiapao
*/
bool checkRow(vector<vector<string>> &aVector, int rowNumber){

    return aVector.size() == rowNumber;
}


/**
    checkIllegalChars - check if filename contains illegal special character

    parameter: string fn

    return: true/ false

    name: chengjiapao, ngbeisheng
*/
bool checkIllegalChars(string fn)
{
    int temp = 0;

    for (int i = 0; i<= fn.size(); ++i){

        if (fn[i] == '\\' || fn[i] == '/' || fn[i] == ':' || fn[i] == '?' || fn[i] == '*' || fn[i] == '<' || fn[i] == '>' || fn[i] == '|' || fn[i] == '"' )

            temp = temp +1; // if found illegal character, add temp by 1

    }

    if (temp >= 1)

        return true;

    else

        return false;

}


/**
    checkFileExtension - check if file extension is csv format

    parameter: string fn

    return: true/ false

    name: chengjiapao, ngbeisheng
*/
bool checkFileExtension(string fn)
{
    /*
        * find the index of the occurence of "."
        * add the index by 1 (indicate the index of "csv")
    */

    if (fn.substr(fn.find_last_of(".")+1) == "csv")

        return true; // if "csv" is in the string, return true

    else

        return false; // if "csv" is not in the string, return false
}


/**
    convertStringToInt - convert a string into integer using sstream

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
    getMin - find and return the minimum value in a column

    parameter: vector<vector<string>> &aVector , int columnNumber

    return: smallest

    name: chengjiapao, ngbeisheng
*/
int getMin(vector<vector<string>> &aVector, int columnNumber){

    int smallest = convertStringToInt(aVector[0][columnNumber]); //set the first column as the smallest value

    for(int i = 1; i <= aVector.size()-1; ++i){

        if(convertStringToInt(aVector[i][columnNumber]) < smallest)

            smallest = convertStringToInt(aVector[i][columnNumber]);
    }

    return smallest;

}


/**
    getMax - find and return the maximum value in a column

    parameter: vector<vector<string>> &aVector , int columnNumber

    return: largest

    name: chengjiapao, ngbeisheng
*/
int getMax(vector<vector<string>> & aVector, int columnNumber){

    int largest = convertStringToInt(aVector[0][columnNumber]); //set the first column as the largest value

    for (int i = 1 ; i <= aVector.size()-1; ++i){

        if(convertStringToInt(aVector[i][columnNumber]) > largest)

            largest = convertStringToInt(aVector[i][columnNumber]);
    }

    return largest;
}


/**
    getMean - compute and return the average(mean) value of a column

    find the total of the column, divide with number of the column to get mean

    parameter: vector<vector<string>> aVector , int columnNumber

    return: mean

    name: chengjiapao
*/
double getMean(vector<vector<string>> &aVector, int columnNumber){

    int total = 0;

    for (int i = 0; i<= aVector.size()-1; ++i){

        total += convertStringToInt(aVector[i][columnNumber]);
    }


    double mean = static_cast<double>(total) / (aVector.size()); //cast int data type to double data type

    cout << setprecision(2) << showpoint <<fixed;

    return mean;

}


/**
    swap - swap the value of two variables

    parameter: vector<string> &firstVector, vector<string> &secondVector, int columnNumber

    name: chengjiapao
*/
void swap(vector<string> &firstVector, vector<string> &secondVector, int columnNumber){

    string temp = firstVector[columnNumber];

    firstVector[columnNumber] = secondVector[columnNumber];

    secondVector[columnNumber] = temp;

}


/**
    sortMarksAscendingly - sort the values of selected column ascendingly by bubble sort

    parameter: vector<vector<string>> &aVector, int columnNumber

    name: chengjiapao

*/
void sortMarksAscendingly(vector<vector<string>> &aVector, int columnNumber){

    int maxElement;

    int index; // use as a subscript for row of a selected column

    for (maxElement = aVector.size()-1; maxElement > 0; maxElement--){

        for (index = 0 ; index < maxElement ; ++index){

            int firstData = convertStringToInt(aVector[index][columnNumber]);

            int secondData = convertStringToInt(aVector[index+1][columnNumber]);

            if (firstData > secondData)

                swap(aVector[index], aVector[index+1],columnNumber);

        }

    }

}

/**
    getMedian - find and return the median of selected column

    sort the values ascendingly,

    if number of column is even, return median as the average of the two middle values,

    if number of column is odd, return median as the middle value.

    parameter: vector<vector<string>> &aVector, int columnNumber

    return: median / secondTerm

    name: chengjiapao
*/
double getMedian(vector<vector<string>> &aVector, int columnNumber)
{
    sortMarksAscendingly(aVector, columnNumber); // arrange the number ascendingly

    int size = aVector.size();

    int firstTerm = convertStringToInt(aVector[(size / 2) - 1][columnNumber]);

    int secondTerm = convertStringToInt(aVector[(size + 2) / 2 - 1][columnNumber]);

    // if the number of column is even
    if(size % 2 == 0){

        double median = static_cast<double>(firstTerm + secondTerm) / 2 ; // median is two middle values divide by 2

        return median;

    }

    else // if the number of column is odd

        return secondTerm; // the middle value is the median

}


/**
    getVariance - compute and return the variance of a column

    get the mean, minus the value in each column with mean,

    add all value that are raised to the base exponent of 2, divide by number of column

    parameter: vector<vector<string>> aVector , int columnNumber

    return: variance

    name: chengjiapao
*/
double getVariance(vector<vector<string>> &aVector, int columnNumber)
{

    double variance, vectorElement;

    double mean = getMean(aVector, columnNumber); //get mean from the getMean function

    for (int i = 0; i <= aVector.size()-1; ++i){

        vectorElement = convertStringToInt(aVector[i][columnNumber]) - mean; // minus the value with mean

        variance += pow(vectorElement,2); //raise value to base exponent of 2

    }

    variance = variance/ aVector.size(); //divide by number of column

    return variance;

}


/**
    getStandardDeviation - compute and return the standard deviation of a column

    get the variance, compute its square root

    parameter: vector<vector<string>> aVector , int columnNumber

    return: standard deviation

    name: chengjiapao
*/
double getStandardDeviation(vector<vector<string>> &aVector, int columnNumber)
{

    double standardDeviation;

    double variance = getVariance(aVector, columnNumber); //get variance from the getVariance function

    standardDeviation = sqrt(variance); // standard deviation is the square root of variance

    return standardDeviation;

}


/**
    displaySubjectsHeader - display subject header

    parameter: vector<vector<string>> &aVector

    name: chengjiapao
*/
void displaySubjectsHeader(vector<vector<string>> &aVector)
{
    vector<string> subjectsHeader{" Mathematics", "    Science", "    Bahasa Melayu"};

    cout << "\t\t\t|";

    for (int i = 0; i<= subjectsHeader.size()-1; ++i){

         cout << subjectsHeader[i] << "  ";
    }

    cout << endl << "============================================================================="<< endl;


}


/**
    displayMinimumVector - display minimum of all subjects

    parameter: vector<vector<string>> &aVector

    name: chengjiapao
*/
void displayMinimumVector(vector<vector<string>> &aVector)
{

    cout << "Minimum \t\t|";

    vector<int> minimumVector;

    for (int i = 0; i < aVector.size()-1; ++i){

        minimumVector.push_back(getMin(aVector, i+2));

        if (i <=2){

            cout << "  " << minimumVector[i] << "\t\t   " ;
        }
    }

    cout << endl << "-----------------------------------------------------------------------------"<< endl;

}


/**
    displayMaximumVector - display maximum of all subjects

    parameter: vector<vector<string>> &aVector

    name: chengjiapao
*/
void displayMaximumVector(vector<vector<string>> &aVector)
{
    cout << "Maximum \t\t|";

    vector<int> maximumVector;

    for (int i = 0; i < aVector.size()-1; ++i){

        maximumVector.push_back(getMax(aVector, i+2));

        if (i <=2){

            cout << "  " << maximumVector[i] << "\t\t   " ;
        }
    }

    cout << endl << "-----------------------------------------------------------------------------"<< endl;

}


/**
    displayMeanVector - display mean of all subjects

    parameter: vector<vector<string>> &aVector

    name: chengjiapao
*/
void displayMeanVector(vector<vector<string>> &aVector)
{
    cout << "Mean \t\t\t|";

    vector<double> meanVector;

    for (int i = 0; i < aVector.size()-1; ++i){

        meanVector.push_back(getMean(aVector, i+2));

        if (i <=2){

            cout << "  " << meanVector[i] << "          " ;
        }
    }

    cout << endl << "-----------------------------------------------------------------------------"<< endl;

}


/**
    displayMedianVector - display median of all subjects

    parameter: vector<vector<string>> &aVector

    name: chengjiapao
*/
void displayMedianVector(vector<vector<string>> &aVector)
{
    cout << "Median \t\t\t|";

    vector<double> medianVector;

    for (int i = 0; i < aVector.size()-1; ++i){

        medianVector.push_back(getMedian(aVector, i+2));

        if (i <=2){

            cout << "  " << medianVector[i] << "          " ;
        }
    }

    cout << endl << "-----------------------------------------------------------------------------"<< endl;

}


/**
    displayVarianceVector - display variance of all subjects

    parameter: vector<vector<string>> &aVector

    name: chengjiapao
*/
void displayVarianceVector(vector<vector<string>> &aVector)
{
    cout << "Variance \t\t|";

    vector<double> varianceVector;

    for (int i = 0; i < aVector.size()-1; ++i){

        varianceVector.push_back(getVariance(aVector, i+2));

        if (i <=2){

            cout << "  " << varianceVector[i] << "\t   " ;
        }
    }

    cout << endl << "-----------------------------------------------------------------------------"<< endl;

}


/**
    displayStandardDeviationVector - display Standard Deviation of all subjects

    parameter: vector<vector<string>> &aVector

    name: chengjiapao
*/
void displayStandardDeviationVector(vector<vector<string>> &aVector)
{
    cout << "Standard Deviation \t|";

    vector<double> standardDeviationVector;

    for (int i = 0; i < aVector.size()-1; ++i){

        standardDeviationVector.push_back(getStandardDeviation(aVector, i+2));

        if (i <=2){

            cout << "  " << standardDeviationVector[i] << "           " ;
        }
    }

    cout << endl << "-----------------------------------------------------------------------------"<< endl;

}


/**
    displayAllSubjectsReport - display all statistics of all subjects

    parameter: vector<vector<string>> &aVector

    name: chengjiapao
*/
void displayAllSubjectsReport(vector<vector<string>> &aVector)
{
       displaySubjectsHeader(aVector);

       displayMinimumVector(aVector);

       displayMaximumVector(aVector);

       displayMeanVector(aVector);

       displayMedianVector(aVector);

       displayVarianceVector(aVector);

       displayStandardDeviationVector(aVector);

}


/**
    displayTable_NumberAboveMean - display the marks that are lower than the mean in a table

    parameter: vector<vector<string>> &aVector, int columnNumber

    name:
*/
void displayTable_NumberAboveMean(vector<vector<string>> &aVector, int columnNumber)
{
    double mean = getMean(aVector, columnNumber);

    int IdColumnNumber = 0;

    cout << "Mean : " << mean << endl;

    cout << "Above mean: " << endl;

    cout << "======================" << endl;

    cout << "|    ID    |   Mark  |" << endl;

    cout << "|----------|---------|" << endl;

    for (int i = 0; i <= aVector.size()-1; ++i){

        if (convertStringToInt(aVector[i][columnNumber]) > mean ) //if mark is higher than mean

            // display the id and marks of student
            cout << "| " << convertStringToInt(aVector[i][IdColumnNumber]) << " |    "
            << convertStringToInt(aVector[i][columnNumber]) << "   |"<< endl;
    }

    cout << "======================" << endl;

}


/**
    displayTable_NumberBelowMean - display the marks that are lower than the mean in a table

    parameter: vector<vector<string>> &aVector, int columnNumber

    name:
*/
void displayTable_NumberBelowMean(vector<vector<string>> &aVector, int columnNumber)
{
    double mean = getMean(aVector, columnNumber);

    int IdColumnNumber = 0;

    cout << "Mean : " << mean << endl;

    cout << "Below mean: " << endl;

    cout << "======================" << endl;

    cout << "|    ID    |   Mark  |" << endl;

    cout << "|----------|---------|" << endl;

    for (int i = 0; i <= aVector.size()-1; ++i){

        if (convertStringToInt(aVector[i][columnNumber]) < mean ) //if mark is lower than mean

            // display the id and marks of student
            cout << "| " << convertStringToInt(aVector[i][IdColumnNumber]) << " |    "
            << convertStringToInt(aVector[i][columnNumber]) << "   |"<< endl;
    }

    cout << "======================" << endl;

}


/**
    getPearsonCorrelation - compute the pearson's correlation of two selected subjects

    display the data and pearson's correlation of two subjects

    parameter: vector<vector<string>> &aVector, int columnNumber1, int columnNumber2

    name:
*/
double getPearsonCorrelation(vector<vector<string>> &aVector, int columnNumber1, int columnNumber2)
{
    int numberOfStudents = aVector.size();

    double totalOfSubject1 = 0, totalOfSubject2 = 0, totalOfSqrOfSubject1 = 0, totalOfSqrOfSubject2 = 0, totalOfMultOfSubject1_Subject2 = 0;

    cout << "==================================================" << endl;

    cout << "X \tY \tXY \t    X^2 \t   Y^2" << endl;

    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i <= aVector.size()-1; ++i){

        double subject1 = convertStringToInt(aVector[i][columnNumber1]);

        double subject2 = convertStringToInt(aVector[i][columnNumber2]);

        double sqrOfSubject1 = pow(subject1, 2);

        double sqrOfSubject2 = pow(subject2, 2);

        double multOfSubject1_Subject2 = subject1 * subject2;

        cout << subject1 << "\t" << subject2 << "\t" << multOfSubject1_Subject2 << "\t    " << sqrOfSubject1 << "\t" << sqrOfSubject2 << endl;

        totalOfSubject1 += subject1;

        totalOfSubject2 += subject2;

        totalOfSqrOfSubject1 += sqrOfSubject1;

        totalOfSqrOfSubject2 += sqrOfSubject2;

        totalOfMultOfSubject1_Subject2 += multOfSubject1_Subject2;

    }
    cout << "--------------------------------------------------" << endl;

    cout << totalOfSubject1 << "\t" << totalOfSubject2 << "\t" <<  totalOfMultOfSubject1_Subject2

    << "    " << totalOfSqrOfSubject1 << "    " << totalOfSqrOfSubject2 << "\t"  << endl;

    cout << "==================================================" << endl << endl;

    double pearsonCorrelation = ( numberOfStudents * totalOfMultOfSubject1_Subject2 - totalOfSubject1 * totalOfSubject2 )

    / sqrt( (numberOfStudents * totalOfSqrOfSubject1 - totalOfSubject1 * totalOfSubject1 )

    * (numberOfStudents * totalOfSqrOfSubject2 - totalOfSubject2 * totalOfSubject2) );

    cout << "r = (" << numberOfStudents << "*" << totalOfMultOfSubject1_Subject2 << " - " << totalOfSubject1 << "*" << totalOfSubject2 << ")"

    << " / " << "sqrt( (" << numberOfStudents << "*" << totalOfSqrOfSubject1 << " - " << totalOfSubject1 << "*" << totalOfSubject1 << ")"

    << " * " << " (" << numberOfStudents << "*" << totalOfSqrOfSubject2 <<  " - " << totalOfSqrOfSubject2 << "*" << totalOfSqrOfSubject2 << ") )\n"

    << "  = " << pearsonCorrelation << endl;

}


/**
    getLinearRegression - compute the linear regression of two selected subjects

    display the data and linear regression of two subjects

    parameter: vector<vector<string>> &aVector, int columnNumber1, int columnNumber2

    name:
*/
void getLinearRegression(vector<vector<string>> &aVector, int columnNumber1, int columnNumber2)
{
    int numberOfStudents = aVector.size();

    double totalOfSubject1 = 0, totalOfSubject2 = 0, totalOfSqrOfSubject1 = 0, totalOfSqrOfSubject2 = 0, totalOfMultOfSubject1_Subject2 = 0;

    cout << "==================================================" << endl;

    cout << "X \tY \tXY \t    X^2 \t   Y^2" << endl;

    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i <= aVector.size()-1; ++i){

        double subject1 = convertStringToInt(aVector[i][columnNumber1]);

        double subject2 = convertStringToInt(aVector[i][columnNumber2]);

        double sqrOfSubject1 = pow(subject1, 2);

        double sqrOfSubject2 = pow(subject2, 2);

        double multOfSubject1_Subject2 = subject1 * subject2;

        cout << subject1 << "\t" << subject2 << "\t" << multOfSubject1_Subject2 << "\t    " << sqrOfSubject1 << "\t" << sqrOfSubject2 << endl;

        totalOfSubject1 += subject1;

        totalOfSubject2 += subject2;

        totalOfSqrOfSubject1 += sqrOfSubject1;

        totalOfSqrOfSubject2 += sqrOfSubject2;

        totalOfMultOfSubject1_Subject2 += multOfSubject1_Subject2;

    }
    cout << "--------------------------------------------------" << endl;

    cout << totalOfSubject1 << "\t" << totalOfSubject2 << "\t" <<  totalOfMultOfSubject1_Subject2

    << "    " << totalOfSqrOfSubject1 << "    " << totalOfSqrOfSubject2 << "\t"  << endl;

    cout << "==================================================" << endl << endl;

    double slope = (numberOfStudents * totalOfMultOfSubject1_Subject2 - totalOfSubject1 * totalOfSubject2)

    / (numberOfStudents * totalOfSqrOfSubject1 - totalOfSubject1 * totalOfSubject1);

    double intercept = (totalOfSubject2 * totalOfSqrOfSubject1 - totalOfSubject1 * totalOfMultOfSubject1_Subject2)

    / (numberOfStudents * totalOfSqrOfSubject1 - totalOfSubject1 * totalOfSubject1);

    cout << "a = (" << totalOfSubject2 << "*" << totalOfSqrOfSubject1 << " - " << totalOfSubject1 << "*"

    << totalOfMultOfSubject1_Subject2 << ") / (" << numberOfStudents << "*" << totalOfSqrOfSubject1 << " - "

    << totalOfSubject1 << "*" << totalOfSubject1 << ") \n  = " << intercept << endl;

    cout << "b = (" << numberOfStudents << "*" << totalOfMultOfSubject1_Subject2 << " - "

    << totalOfSubject1 << "*" << totalOfSubject2 << ") / ("

    << numberOfStudents << "*" << totalOfSqrOfSubject1 << " - " << totalOfSubject1 << "*" << totalOfSubject1

    << ") \n" << "  = " << slope << endl;

    cout << "y = a + bx \n" << "  = " << intercept << " + " << slope << "x" << endl;
}


/**
    readCSV - read a CSV file

    read a CSV file after prompt user to input CSV file name

    name: chengjiapao, ngbeisheng
*/
void readCSV(string fn){

    string line;

    vector<vector<string>> aVectorOfVector;

    vector<string> headerVector;

    //ifstream myfile("data.csv");

    ifstream myfile(fn);

    string columns;

    int lineNumber = 0;

    int lineNumForNumOfColumns = 1; //this line shows the number of column

    int lineNumForNumOfRows = 3; //this line shows the number of row

    int lineNumForHeader = 2;

    int columnNumber;

    int rowNumber;

    if(myfile.is_open()){

        string columns, header, rows;

        // read frist line for columns
        getline(myfile,columns);

        columnNumber = convertStringToInt(columns);

        cout << columnNumber << endl;


        // read second line for header
        getline(myfile,header);

        vector<string> headerVector = constructVectors(header);


        // read third line for rows
        getline(myfile,rows);

        rowNumber = convertStringToInt(rows);

        cout << rowNumber << endl;


       while(getline(myfile,line)){
        // read the rest of the file

                vector<string> aSmallVector = constructVectors(line);

                aVectorOfVector.push_back(aSmallVector);

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


       double mean = getMean(aVectorOfVector,2);

       cout << "The mean is: " << mean << endl;


       double variance = getVariance(aVectorOfVector, 3);

       cout << "Variance is: " << variance << endl;


       double standardDeviation = getStandardDeviation(aVectorOfVector, 3);

       cout << "Standard Deviation is: " << standardDeviation << endl;

       double median = getMedian(aVectorOfVector, 2);

       cout << "Median is: : " << median << endl;

       displayTable_NumberAboveMean(aVectorOfVector, AgeColumn);

       cout << endl;

       displayTable_NumberBelowMean(aVectorOfVector, AgeColumn);

       cout << endl;

       //displayMarkFrequencyDistribution(aVectorOfVector, 2); problem now

       cout << endl;

       displayAllSubjectsReport(aVectorOfVector);

        cout << endl;

        //displayComparisonOfTwoSubjects(aVectorOfVector, 2,3);
        getPearsonCorrelation(aVectorOfVector, 2, 3);

        cout << endl;

        getLinearRegression(aVectorOfVector, 2, 3);

    }

    else{

      // exit to menu (cout menu)
    }


}


int main()
{

    string filename;

    showMenu();

    cin >> filename;

    if (!checkIllegalChars(filename) && checkFileExtension(filename)){

        // do process
        readCSV(filename);

    }

    else

        // dont do..
        cout << "Wrong format" << endl;

    return 0;

}
