#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

void displayMarksFrequencyDistribution();
string subjName;
void switchForSubjectSubMenu(string subjectName);
vector<vector<string>> aVectorOfVector;

///////////////////////////////////////////////////////////////////////////////////////////////////#makingvector
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
        /*
       for(auto x: aVector){

          cout << x << endl;
       }
        */
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

///////////////////////////////////////////////////////////////////////////////////////////////////#Display
void displayMenu()
{
    cout << "\t\tMain Menu" << endl;
    cout << "=================================" << endl;
    cout << "  1.\tLoad data from file" <<endl;
    cout << "  2.\tView by subject" <<endl;
    cout << "  3.\tCompare subjects" << endl;
    cout << "  4.\tOverall report" <<endl;
    cout << "  5.\tExit program" <<endl;

}


void displaySubjectMenu()
{
    system("CLS");
    cout << "                View by subject" <<endl;
    cout << "================================" <<endl;
    cout << "  1.   Math" <<endl;
    cout << "  2.   Science" <<endl;
    cout << "  3.   Malay" <<endl;
    cout << "  4.   All Subjects " << endl;
    cout << "  0.   Back to Main Menu" <<endl;
}



int getInputForSubjectSubMenu()
{
    int selection = 0;
    string message = "Please choose from 1-0: ";
    while((cout << message && (!(cin >> selection ))) || (selection!= 0 && selection!= 1 && selection!= 2 && selection!= 3 && selection!= 4 && selection!= 5 && selection!= 6 && selection!= 7 && selection!= 8 && selection!= 9) )
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignore character from input buffer
            cout << "\nInvalid input, try again\n";
        } // input validate, not accepting character eg: a/b but input eg: 4a is still accepted
    return selection;
}




void displaySubjectSubMenu(string subjectName)
{
    system("CLS");
    string name;
    name = subjectName;

    cout << "                "<<name<<endl;
    cout << "================================" <<endl;
    cout << "  1.   Minimum mark" <<endl;
    cout << "  2.   Maximum mark" <<endl;
    cout << "  3.   Median" <<endl;
    cout << "  4.   Mean" <<endl;
    cout << "  5.   Variance" <<endl;
    cout << "  6.   Standard Deviation" <<endl;
    cout << "  7.   Marks Freq. Distribution" <<endl;
    cout << "  8.   Histogram" <<endl;
    cout << "  9.   Above/Below Average" <<endl;
    cout << "  0.   Back to view by subject menu" <<endl;
    switchForSubjectSubMenu(subjectName);


}



int getInputForMainMenu()
{
   int selection = 0;
    string message = "Please choose from 1-0: ";
    while((cout << message && (!(cin >> selection )))||(selection!= 1 && selection!= 2 && selection!= 3 && selection!= 4 && selection!= 5) )
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignore character from input buffer
            cout << "\nInvalid input, try again\n";
        } // input validate, not accepting character eg: a/b but input eg: 4a is still accepted
    return selection;
}



void printTitle()
{
    cout << "Welcome to Academic Report System"<<endl;
    cout << "================================="<<endl;
    system("PAUSE");
    system("CLS");

}


void displayCompareSubjectsMenu()
{
    system("CLS");
    cout << "\t\t\tCompare Subjects"               << endl;

    cout << "=============================================" << endl;

    cout << "\t1. Select Subjects"                          << endl;

    cout << "\t0. Back to Main Menu"                        << endl;


}


void displayOverallReportMenu()
{
    system("CLS");
    cout << "\t\t\tOverall Report"               << endl;

    cout << "=============================================" << endl;

    cout << "\t1. Show data ascendingly"                    << endl;

    cout << "\t2. Show data descendingly"                   << endl;

    cout << "\t3. Generate text file"                   << endl;

    cout << "\t4. Generate html file"                   << endl;

    cout<<  "\t0.  Back to Main Menu"                        << endl;
}



void displayCompareSubjectsSubMenu(string&firstSubject,string&secondSubject)
{
    system("CLS");
    int subject1,subject2;
    cout << "\t\t\tCompare Subjects"               << endl;

    cout << "=============================================" << endl;

    cout << "\t1. Math"                                     << endl;

    cout << "\t2. Malay"                                    << endl;

    cout << "\t3. Science"                                  << endl;

    do{
        cout <<"\tChoose Subject 1: ";
        cin >>subject1;
        cout<< " " <<endl;

        cout<<"\tChoose Subject 2: ";
        cin >>subject2;
        cout<< " " <<endl;
        if(subject1<1 || subject1>3 || subject2<1 || subject2>3 || subject1==subject2)
            cout<< "\tPlease choose from 1 to 3 only and does not repeat the same subjects for both input"<<endl;
      } while(subject1<1 || subject1>3 || subject2<1 || subject2>3 || subject1==subject2);
    if(subject1 == 1)
        firstSubject = "Math";

    if(subject1 == 2)
        firstSubject = "Malay";

    if(subject1 == 3)
        firstSubject = "Science";

    if(subject2 == 1)
        secondSubject = "Math";

    if(subject2 == 2)
        secondSubject = "Malay";

    if(subject2 == 3)
        secondSubject = "Science";

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
int getMax(vector<vector<string>> &aVector, int columnNumber){

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

void swap(vector<string> &firstVector, vector<string> &secondVector, int columnNumber){

    string temp = firstVector[columnNumber];

    firstVector[columnNumber] = secondVector[columnNumber];

    secondVector[columnNumber] = temp;

}

/***
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

        double median = static_cast<double>(firstTerm + secondTerm) / 2; // median is two middle values divide by 2

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



void datacalculation()

{

    int columnNumber1,columnNumber2;//initialize data for furthure process
    vector<int>temp;
    int x,y;
    int sumX=0;
    int sumY=0;
    double x2= 1;
    double y2= 1;
    int sumXandY=0;

    int totalXandY;
    int totalMultiplyXandY=0;
    int totalX2=0;
    double totalY2=0;
    cin>>columnNumber1>>columnNumber2;  //user input

    for (int rowNumber=0;rowNumber<=aVectorOfVector.size();rowNumber++){//for loop for data calculation until student data is calculate finnished
         x=convertStringToInt(aVectorOfVector[rowNumber][columnNumber1]);
         y=convertStringToInt(aVectorOfVector[rowNumber][columnNumber1]);
         sumX=(sumX+x);
         sumY=(sumY+y);
         sumXandY=(x*y);
         totalXandY=(sumX+sumY);
         x2= (x*x);
         y2=(y*y);
         totalX2=(totalX2+x2);
         totalY2=(totalY2+y2);
         totalMultiplyXandY= (totalMultiplyXandY+ sumXandY);
         cout<<x <<"\t"<<y<<"\t"<<sumXandY<<"\t"<<x2<<"\t"<<y2<<endl;
         if(rowNumber==4){//return the data for further process in get linear colleration and pearson regression
            temp.push_back (sumX);
            temp.push_back (sumY);
            temp.push_back (totalMultiplyXandY);
            temp.push_back (totalX2);
            temp.push_back (totalY2);
    }
    }

   /** getlinear colleration and pearson regression- calculate data

    parameter: vector<vector<int>> temp

    cout: linearA,linearB,pearsoncolleration

    name: Tang Ning Kang
    */

    cout<<temp[0] <<"\t"<<temp[1]<<"\t"<<temp[2]<<"\t"<<temp[3]<<"\t"<<temp[4]<<endl;
    double pearsoncolleration=0;
    pearsoncolleration=((aVectorOfVector.size()*temp[2])-(temp[0]*temp[1]))/sqrt(((aVectorOfVector.size()*temp[3])-(temp[0]*temp[0]))*((aVectorOfVector.size()*temp[4])-(temp[1]*temp[1])));
    cout<<pearsoncolleration<<endl;
    int linearA=0;
    int linearB=0;
    linearA =((temp[1]*temp[3])-(temp[0]*temp[3]))/((aVectorOfVector.size()*temp[3])-(temp[0]*temp[0]));
    cout<<linearA<<endl;
    linearB=(aVectorOfVector.size()*temp[2])/(aVectorOfVector.size()*temp[3]-(temp[0]*temp[0]));
    cout<<linearB<<endl;

    }



void printHistogram(vector<int>counterData)
{


   int yaxis =0;
   int xaxis =0;
   int yaxisvalue =20;


    cout<<"-----\nFreq|\n-----"<<endl;

   do   //y axis 分界线
   {
      cout.width(4);
      cout << yaxisvalue << "|" << " ";//print y-axis
      for (int i = 0; i<10; i++)//print for the data frequency
      {
        if (counterData[i] >= yaxisvalue)
        {
            cout << "*        ";//如果大过或一样
        }
        else
        {
            cout << "         " ;//如果小过
        }
      }
      cout << "" << endl;//让他跑去下一line
      yaxisvalue =yaxisvalue-1;


   }
   while(yaxisvalue>yaxis);


    cout << "-----------------------------------------------------------------------------------------------------"<<endl;

    cout<<"   0|0-<10   10-<20   20-<30   30-<40   40-<50   50-<60   60-<70   70-<80   80-<90   90-100 | Marks |"<<endl;
    cout << "-----------------------------------------------------------------------------------------------------";
  }



void datakeeping(int columnNumber)
{
    vector<int>counterData={0,0,0,0,0,0,0,0,0,0};
    int score;
    for(int i =0; i<aVectorOfVector.size();i++){
         int score = convertStringToInt(aVectorOfVector[i][columnNumber]);
         if (score >=0 && score <10)
            counterData[0]+=1;
         else if (score >=10 && score <20)
            counterData[1]+=1;
         else if (score >=20 && score <30)
            counterData[2]+=1;
         else if (score >=30 && score <40)
            counterData[3]+=1;
         else if (score >=40 && score <50)
            counterData[4]+=1;
         else if (score >=50 && score <60)
            counterData[5]+=1;
         else if (score >=60 && score <70)
            counterData[6]+=1;
         else if (score >=70 && score <80)
            counterData[7]+=1;
         else if (score >=80 && score <90)
            counterData[8]+=1;
         else if (score >=90 && score <=100)
            counterData[9]+=1;

}

 printHistogram(counterData);
}

void meanAboveAndBelow(vector<vector<string>>aVectorOfVector,int columnNumber)
{
   double mean = getMean(aVectorOfVector,columnNumber);//get mean from function
   int aboveMean;
   std::vector<string>vAboveMean;//vector defined before data is keep
   std::vector<string>vBelowMean;
   int compareMean;

   cout<<endl<< "Above Mean:"<<endl;
   cout<<"===========" << endl;
   cout<<"|"<<"ID  "<<"|"<<"Mark"<<"|"<<endl;//print the top of table
   cout<<"-----------"<<endl;

   //for loop to keep comparing until the i equal vector size and get data above mean
   for(int i=0;i<aVectorOfVector.size();i++){

        compareMean=convertStringToInt(aVectorOfVector[i][columnNumber]);

        if(compareMean>=mean)  {

            //vAboveMean[j].push_back(aVectorOfVector[i])
            cout<<"|"<<aVectorOfVector[i][0].substr(6, 9)<<"|"<<setw(4)<<aVectorOfVector[i][columnNumber] <<"|"<<endl;
            //print out the id with last 4 digit and keep range for table to insert the data
        }
                                }
    cout<<"==========="<<endl<<endl;
    cout<<"Below Mean:"<<endl;
    cout<<"===========" << endl;
    cout<<"|"<<"ID  "<<"|"<<"Mark"<<"|"<<endl;
    cout<<"-----------"<<endl<< endl;

    //for loop to keep comparing until the i equal vector size and get data below mean
    for(int i=0;i<aVectorOfVector.size();i++){

            compareMean=convertStringToInt(aVectorOfVector[i][columnNumber]);
            //vBelowMean[i].push_back(aVectorOfVector[i])
            if(compareMean<mean)  {
            cout<<"|"<<aVectorOfVector[i][0].substr(6, 9)<<"|"<<setw(4)<<aVectorOfVector[i][columnNumber]<<"|"<<endl;
            //print out the id with last 4 digit and keep range for table to insert the data
                                                   }
                                        }
    cout<<"==========="<<endl;
}


/**
    swapAscendingly - display minimum of all subjects

    parameter: vector<vector<string>> aVectorOfVector

    name: tan yong qi
*/
vector<vector<string>> swapAscendingly(vector<vector<string>> aVectorOfVector, int columnNumber)
{
    int firstNum, secondNum;
    vector<int> shiftCount = {0,1};
    vector<string> temp;

    while (shiftCount[0] != shiftCount[1]){
        for (int i = 0 ; i < aVectorOfVector.size(); i++){
            shiftCount[1]=shiftCount[0];
            for (int j = 0 ; j < i ; ++j){
                firstNum = convertStringToInt(aVectorOfVector[j][columnNumber]);
                secondNum = convertStringToInt(aVectorOfVector[j+1][columnNumber]);
                if (firstNum > secondNum){
                    temp = aVectorOfVector[j];
                    aVectorOfVector[j] = aVectorOfVector[j+1];
                    aVectorOfVector[j+1] = temp;
                    shiftCount[0]+=1;
                    shiftCount[1]=shiftCount[0]+1;
                }
            }
        }
    }
    return aVectorOfVector;
}



/**
    displaySorted_Data_Descendingly - display minimum of all subjects

    parameter: vector<vector<string>> aVectorOfVector

    name: tan yong qi
*/
vector<vector<string>> swapDescendingly(vector<vector<string>> aVectorOfVector, int columnNumber)
{
    int firstNum, secondNum;
    vector<int> shiftCount = {0,1};
    vector<string> temp;

    while (shiftCount[0] != shiftCount[1]){
        for (int i = 0 ; i < aVectorOfVector.size(); i++){
            shiftCount[1]=shiftCount[0];
            for (int j = 0 ; j < i ; ++j){
                firstNum = convertStringToInt(aVectorOfVector[j][columnNumber]);
                secondNum = convertStringToInt(aVectorOfVector[j+1][columnNumber]);
                if (firstNum < secondNum){
                    temp = aVectorOfVector[j];
                    aVectorOfVector[j] = aVectorOfVector[j+1];
                    aVectorOfVector[j+1] = temp;
                    shiftCount[0]+=1;
                    shiftCount[1]=shiftCount[0]+1;
                }
            }
        }
    }
    return aVectorOfVector;
}


/**
    displaySorted_Data_Ascendingly - display minimum of all subjects

    parameter: vector<vector<string>> aVectorOfVector

    name: tan yong qi
*/
void displaySorted_Data_Ascendingly(vector<vector<string>> aVectorOfVector)
{
    int columnNumber;
    cout<< "Please enter column number: ";
    cin>> columnNumber;

    /*ofstream test;
    test.open("data.txt",ios::app);
    */
    // use as a subscript for row of a selected column
    aVectorOfVector = swapAscendingly(aVectorOfVector, columnNumber);
    /*
    for (int i = 0; i<aVectorOfVector.size(); i++){
        for (int j=0; j<aVectorOfVector[i].size(); j++)
        {
            test<<aVectorOfVector[i][j]<<" ";
        }
        test<<"\n";
    }

    test.close();
    */
    for (int i = 0; i<aVectorOfVector.size(); i++){
        cout<<"|";
        for (int j=0; j<aVectorOfVector[i].size(); j++)
        {
            cout<<setw(5)<<aVectorOfVector[i][j]<<"|";
        }
        cout<<"\n";
    }
    system("PAUSE");
}


/**
    displaySorted_Data_Descendingly - display minimum of all subjects

    parameter: vector<vector<string>> aVectorOfVector

    name: tan yong qi
*/
void displaySorted_Data_Descendingly(vector<vector<string>> aVectorOfVector)
{
    int columnNumber;
    cout<< "Please enter column number: ";
    cin>> columnNumber;

    /*ofstream test;
    test.open("data.txt",ios::app);
    */
    // use as a subscript for row of a selected column
    aVectorOfVector = swapDescendingly(aVectorOfVector, columnNumber);
    /*
    for (int i = 0; i<aVectorOfVector.size(); i++){
        for (int j=0; j<aVectorOfVector[i].size(); j++)
        {
            test<<aVectorOfVector[i][j]<<" ";
        }
        test<<"\n";
    }

    test.close();
    */
    for (int i = 0; i<aVectorOfVector.size(); i++){
        cout<<"|";
        for (int j=0; j<aVectorOfVector[i].size(); j++)
        {
            cout<<setw(5)<<aVectorOfVector[i][j]<<"|";
        }
        cout<<"\n";
    }
    system("PAUSE");
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


int calculateFrequency(int score)
{
    vector<vector<string>> aVector;
    //aVector = readCSV(string fn);
    aVector = aVectorOfVector;
    int frequency;
    if (subjName == "Math")
    {
        for  (int i =0; i<aVector.size();i++)
        {
            int getInt;
            getInt = convertStringToInt(aVector[i][2]);
            //cout <<getInt<<endl;
            if (score == getInt)
            {
                frequency +=1;
            }

        }
        return frequency;

    }
    else if (subjName == "Science")
    {
        for  (int i =0; i<aVector.size();i++)
        {
            int getInt;
            getInt = convertStringToInt(aVector[i][3]);
            //cout <<getInt<<endl;
            if (score == getInt)
            {
                frequency +=1;
            }

        }
        return frequency;
    }
    else if (subjName == "Malay")
    {
        for  (int i =0; i<aVector.size();i++)
        {
            int getInt;
            getInt = convertStringToInt(aVector[i][4]);
            //cout <<getInt<<endl;
            if (score == getInt)
            {
                frequency +=1;
            }
        }
        return frequency;
    }
}


void storeResult_Txt()
{
    int miN,maX;
    double median, mean, variance, stdDeviation;

    ofstream result;

    result.open("data.txt",ios::app);

    miN = getMin(aVectorOfVector,3);
    maX = getMax(aVectorOfVector,2);
    median = getMedian(aVectorOfVector,3);
    mean = getMean(aVectorOfVector,3);
    variance = getVariance(aVectorOfVector,3);
    stdDeviation = getStandardDeviation(aVectorOfVector,2);
    vector<double>statistic;
    statistic.push_back(miN);
    statistic.push_back(maX);
    statistic.push_back(median);
    statistic.push_back(mean);
    statistic.push_back(variance);
    statistic.push_back(stdDeviation);

    for (int i =0; i <statistic.size();i++)
    {
        result<<statistic[i] <<endl;
    }
    result.close();
}

std::string getSubjectName(int num)
{
    int choice = num;
    string subjectName;
    if (choice == 1)
    {
        subjectName = "Math";

    }
    else if (choice == 2)
    {
        subjectName = "Science";
    }
    else if (choice == 3)
    {
        subjectName = "Malay";
    }
    return subjectName;
}


void displayMarksFrequencyDistribution()
{
    system("CLS");
    int score;
    int frequency = 0;
    cout<< "Marks Freq. Dist.: "<<subjName<<endl;
    cout<< "=================="<<endl;
    cout<<"|"<<"Mark  "<<"|"<<"Frequency"<<"|"<<endl;
    cout <<"=================="<<endl;
    for (score=0;score<101;score++)
    {
            frequency = calculateFrequency(score);
            cout <<"|"<< setw(5) <<score <<"|"<< setw(3)<<"         "<< frequency<<"|"<<endl;
            frequency=0;
    }
    cout <<"=================="<<endl;
}


///////////////////////////////////////////////////////////////////////////////////////////////////#ReadCSV
/**
    readCSVFile - read a CSV file

    read a CSV file after prompt user to input CSV file name

    name: chengjiapao, ngbeisheng
*/

bool readCSVFile(){
    string fn;
    bool fileAccess;
    cout<<"Please enter filename: ";
    cin >> fn;
    if (!checkIllegalChars(fn) && checkFileExtension(fn)){
    // do process
    string line;

    //vector<vector<string>> aVectorOfVector;

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
        fileAccess = true;
        string columns, header, rows;

        // read frist line for columns
        getline(myfile,columns);

        columnNumber = convertStringToInt(columns);

        //cout << columnNumber << endl;


        // read second line for header
        getline(myfile,header);

        vector<string> headerVector = constructVectors(header);


        // read third line for rows
        getline(myfile,rows);

        rowNumber = convertStringToInt(rows);

        //cout << rowNumber << endl;


       while(getline(myfile,line)){
        // read the rest of the file

                vector<string> aSmallVector = constructVectors(line);

                aVectorOfVector.push_back(aSmallVector);

        }
        cout<< "File loaded successful."<<endl;
        system("PAUSE");
    }

}else{
    // dont do..
    cout << "Wrong format" << endl;
    fileAccess = false;
    system("PAUSE");
    }
}



void switchForSubjectSubMenu(string subjectName)
{
    int ch, columnNumber, smallest, biggest;
    double meanValue, medianValue, varianceValue, stdValue;
    ch = getInputForSubjectSubMenu();

    if (subjectName =="Math"){
        columnNumber = 2;
    } else if (subjectName =="Science"){
        columnNumber = 3;
    } else if (subjectName =="Malay"){
        columnNumber = 4;
    }

    switch(ch)
    {
        case 1:
            system("CLS");
            cout << "Displaying Minimum Mark..." <<endl;
            smallest = getMin(aVectorOfVector,columnNumber);
            cout << "===========================" << endl;
            cout << "|    Subject  |    Min    |" << endl;
            cout << "---------------------------" << endl;
            cout << "|    " << setw(5) << subjectName <<    "    |  " << smallest<< "       |" << endl;
            cout << "===========================" << endl;
            system("PAUSE");
            break;
        case 2:
            system("CLS");
            cout << "Displaying Maximum Mark..." <<endl;
            biggest = getMax(aVectorOfVector,columnNumber);
            cout << "===========================" << endl;
            cout << "|    Subject  |    Max    |" << endl;
            cout << "---------------------------" << endl;
            cout << "|    " << setw(5) << subjectName <<    "    |  " << biggest<< "       |" << endl;
            cout << "===========================" << endl;
            system("PAUSE");
            break;
        case 3:
            system("CLS");
            cout << "Displaying Mean..." <<endl;
            meanValue = getMean(aVectorOfVector,columnNumber);
            cout << "===========================" << endl;
            cout << "|    Subject  |    Mean   |" << endl;
            cout << "---------------------------" << endl;
            cout << "|    " << setw(5) << subjectName <<    "    |  " << meanValue<< "       |" << endl;
            cout << "===========================" << endl;
            system("PAUSE");
            break;
        case 4:
            system("CLS");
            cout << "Displaying Median..." <<endl;
            medianValue = getMedian(aVectorOfVector,columnNumber);
            cout << "===========================" << endl;
            cout << "|    Subject  |   Median  |" << endl;
            cout << "---------------------------" << endl;
            cout << "|    " << setw(5) << subjectName <<    "    |  " << medianValue<< "       |" << endl;
            cout << "===========================" << endl;
            system("PAUSE");
            break;
        case 5:
            system("CLS");
            cout << "Displaying Variance..." <<endl;
            varianceValue = getVariance(aVectorOfVector,columnNumber);
            cout << "===========================" << endl;
            cout << "|    Subject  |  Variance  |" << endl;
            cout << "---------------------------" << endl;
            cout << "|    " << setw(5) << subjectName <<    "    |  " << varianceValue<< "       |" << endl;
            cout << "===========================" << endl;
            system("PAUSE");
            break;
        case 6:
            system("CLS");
            cout << "Displaying Standard Deviation..." <<endl;
            stdValue = getStandardDeviation(aVectorOfVector,columnNumber);
            cout << "====================================" << endl;
            cout << "|    Subject  | Standard Deviation |" << endl;
            cout << "------------------------------------" << endl;
            cout << "|    " << setw(5) << subjectName <<    "    |     " << stdValue << "       |    " << endl;
            cout << "====================================" << endl;
            system("PAUSE");
            break;
        case 7:
            system("CLS");
            cout << "Displaying Marks Freq.Distribution..."<<endl;
            displayMarksFrequencyDistribution();
            system("PAUSE");
            break;
        case 8:
            system("CLS");
            cout << "Displaying Histogram..." <<endl;
            cout<<"Histogram: "<<subjectName<<endl;
            datakeeping(columnNumber);
            system("PAUSE");
            break;
        case 9:
            system("CLS");
            cout << "Displaying Above/Below Average..." <<endl;
            cout<<"Above/Below average: "<< subjectName<<endl;
            meanAboveAndBelow(aVectorOfVector, columnNumber);
            system("PAUSE");
            break;
        case 0:
            displaySubjectMenu();
            break;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////#Main
int fakeMain(int ch){
    system("CLS");
    displayMenu();
    bool fileAccess;
    ch = getInputForMainMenu();
    int selection, option, choiceSubject;
    string firstSubject, secondSubject;
    switch(ch)
    {
        case 1:
            do{
                fileAccess=readCSVFile();
            }while (fileAccess == false);
            break;
        case 2:
            int choice;
            if (fileAccess == false)
            {
                cout<< "\tThe file has not been loaded" <<endl;
                fileAccess = readCSVFile();
            }
            do{

                displaySubjectMenu();

                int selection = 0;

                string message = "Please enter your choice: ";

                while((cout << message && (!(cin >> choice ))) ||
                    (choice!= 1 && choice!= 2 && choice!= 3 && choice!= 4 && choice!= 0) ){

                        cin.clear();

                        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignore character from input buffer

                        cout << "\nInvalid input, try again\n";

                } // input validate, not accepting character eg: a/b but input eg: 4a is still accepted

                if (choice>=1 && choice <=3){

                    subjName = getSubjectName(choice);

                    displaySubjectSubMenu(subjName);
                }

                else if (choice == 4){

                    system("CLS");

                    cout << "Displaying all subjects report...\n"<<endl;

                    displayAllSubjectsReport(aVectorOfVector);

                    system("PAUSE");
                }

            } while (choice != 0);

            break;
            /*do{
                displaySubjectMenu();
                do{
                    cout << "\tPlease choose from 1 - 0 : ";
                    cin >> choice;

                } while (choice<1 && choice>3 && choice!=0);
                if (choice>=1 && choice <=3){
                    subjName = getSubjectName(choice);
                    displaySubjectSubMenu(subjName);
                }
            } while (choice != 0);
            break;*/
        case 3:
            do{
                displayCompareSubjectsMenu();
                do{
                    string message = "Please choose from 1 - 0 : ";

                    while((cout << message && (!(cin >> selection ))) || (selection!= 1 && selection!= 0) ){

                        cin.clear();

                        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignore character from input buffer

                        cout << "\nInvalid input, try again\n";
                    }

                   /* cout << "\tPlease choose from 1 - 0 : ";
                    cin >> selection;
                    cout<< " " <<endl;*/

                } while(selection<1 && selection>1 && selection!=0);
                if (selection==1)
                {
                    displayCompareSubjectsSubMenu(firstSubject,secondSubject);
                }
            } while (selection!=0);
            break;

        case 4:
            do{
                displayOverallReportMenu();
                do{

                    string message = "Please choose from 1 - 0 : ";

                    while((cout << message && (!(cin >> option ))) || (option!= 1 && option!= 2 && option!= 3 && option!= 4 && option!= 0) ){

                        cin.clear();

                        cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignore character from input buffer

                        cout << "\nInvalid input, try again\n";
                    }

                    /*cout<< "\tPlease choose from 1 - 0 : ";
                    cin >> option;
                    cout << " " <<endl;*/

                } while(option<1 && option>4 && option!=0);
                if (option==1)
                {
                    displaySorted_Data_Ascendingly(aVectorOfVector);
                }
                else if(option ==2)
                {
                    displaySorted_Data_Descendingly(aVectorOfVector);
                }
                else if(option ==3)
                {
                    storeResult_Txt();
                    cout << "Store successfully." << endl;
                    system("PAUSE");
                }
                else if(option ==4)
                {
                    //computeIntoHtmlFile();
                }
                else
                    cout<<" Invalid input, please try again: " << endl;
              } while(option!=0);
            break;
        case 5:
            cout << "Exiting the program" << ch << endl;
            exit(0);
            break;
    }
    return ch;
}

int main()
{
    int ch,decision;
    printTitle();
    do{
        decision=fakeMain(ch);
    }while (ch !=5);
    return 0;
}

