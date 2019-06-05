#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

class DVD{
    string serialNum;
    string name;
    string genre;
    public:
        void print();
        void setValues(string serialNum, string name, string genre);
        string getSerialNum();
        string getName();
        string getGenre();
};

void DVD::print(){
    cout << "DVD#" << serialNum << endl;
    string nameOutput = "Name: "+name;
    string genreOutput = "Genre: "+genre;
    cout << nameOutput << endl;
    cout << genreOutput << endl;
}

void DVD::setValues(string serialNum1, string name1, string genre1){
    serialNum = serialNum1;
    name = name1;
    genre = genre1;
}

string DVD::getSerialNum(){
    return serialNum;
}

string DVD::getGenre(){
    return genre;
}

string DVD::getName(){
    return name;
}



int main(){
    ifstream inFile;
    inFile.open("test.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    DVD dvdSet[10];
    string line, serialNum, name, genre;
    int i = 0;

    while (getline(inFile, line)){
        char *end;
        strtol(line.c_str(), &end, 10);

        if (*end==0){
            serialNum = line;
            getline(inFile, line);
            name = line;
            getline(inFile, line);
            genre = line;
            DVD dvd;
            dvd.setValues(serialNum, name, genre);
            dvdSet[i] = dvd;
            i += 1;
        }
    }

    for (int i = 0; i<10; i++){
        dvdSet[i].print();
    }

    return 0;
}