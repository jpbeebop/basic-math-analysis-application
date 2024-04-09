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

    // test code
    if(checkColumn(aVectorOfVector[1],columnNumber) && checkRow(aVectorOfVector, rowNumber )){

       // do process

       int AgeColumn = 1;

       int smallest = getMin(aVectorOfVector,AgeColumn);

       cout << "The minimum number is: " << smallest << endl;


       int largest = getMax(aVectorOfVector,AgeColumn);

       cout << "The maximum number is: " << largest << endl;


       double mean = getMean(aVectorOfVector,2);

       cout << "The mean is: " << mean << endl;


       double variance = getVariance(aVectorOfVector, AgeColumn);

       cout << "Variance is: " << variance << endl;


       double standardDeviation = getStandardDeviation(aVectorOfVector, AgeColumn);

       cout << "Standard Deviation is: " << standardDeviation << endl;

       double median = getMedian(aVectorOfVector, AgeColumn);

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
