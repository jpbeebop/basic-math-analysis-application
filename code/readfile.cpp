#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility> //pair
#include <stdexcept> //run_time error
#include <iomanip>
#include <cmath>
using namespace std;

vector<pair <string, vector<float>>> read_csv(string data.csv){
// read a csv file into vector of <string, vector<float> pairs
//each pair represents <column name, column values>

//define variable
string line, colname;
int mark;

vector<pair <string, vector<float>>> result; //create a vector to store the result

ifstream assignment(data.csv);

if (assignment.is_open())
    runtime_error("Cannot open file");

//read the names of column
if (assignment.good()){
    getline(assignment,line); //extract the first line of the file
    stringstream ss(line); //create a stringstream from line

    //extract each column name
    while(getline(ss, colname, ',')){
        result.pushback({colname, vector<float> {}});
    }
}

//read the data line by line
while (getline(assignment,line)){
    stringstream ss(line); //create a stringstream from line
    int colIndex = 0;

    while (ss >> mark){
        result.at(colIndex).second.push_back(mark);
        if (ss.peek() == ',') ss.ginore();
        coldIndex++;
    }

}

assignment.close();

return result;

}

/*void readFile(){


    ifstream inputFile("data.csv");
    //string fileLine;

    string numberOfColumns, line2, numberOfRows, line4, line5, line6, line7;

    string token, token2;


    while(inputFile >> numberOfColumns >> line2 >> numberOfRows >> line4 >> line5 >> line6 >> line7 || !inputFile.eof()){


        cout << numberOfColumns << endl;
        cout << line2 << endl;
        cout << numberOfRows << endl;
        cout << line4 <<  endl;
        cout << line5 << endl;
        cout << line6 << endl;
        cout << line7 << endl;

        vector<string> aRow;

        string temp;

        int index;

        cout << getLastColumn(line4) << endl;


       for(auto x : line4){


            if(x != ',')
                temp += x;

            else if(x == ','){
                aRow.push_back(temp);
                temp = "";
            }


       }


       aRow.push_back(getLastColumn(line4));

        for(auto x : aRow){
            cout << x << endl;
        }



       /*if(id.find(';') != string::npos){
        cout << "yes" << endl;
       }*/


 /*   }

} */

int main()
{
  vector<pair<string, vector<float>>> data.csv = read_csv("data.csv");






    return 0;
}
