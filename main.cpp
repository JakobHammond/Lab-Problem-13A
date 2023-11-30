//
//  main.cpp
//  please
//
//  Created by Jakob Hammond on 11/30/23.
//

#include <iostream>
#include <fstream>
using namespace std;

int countLetters(fstream fileName);
int main(void) {
/*
    int totalLetters = 0;
    string fileName;
    int letterAmounts[26];
    double letterFrequencies[26];
    
    for(int i = 0; i < 26; i++) letterAmounts[i] = 0;
    
    cout << "Enter filename: ";
    cin >> fileName;
    ifstream fileStream(fileName);
    
    char ch;
    fileStream.open(fileName);
    if(!fileStream){
        cout << "kys" << endl;
        return 1;
    }
    
    while(fileStream.get(ch) && !fileStream.eof()){
        if(isalpha(ch)){
            totalLetters++;
        }
        
    }
    cout << totalLetters;
    */
 
    while(true){
        ifstream lab3;
        string word;
        string fileName;
        cout << "Enter filename: ";
        cin >> fileName;
        lab3.open(fileName);
        int countletters=0,countnum=0,countpunc=0,countspace=0,words=0,line=0;
        char character,prevchar = 0;
        if(!lab3)
        {
            cout << "Could not open file" << endl;
            return 1;
        }
        while(lab3.get(character) && !lab3.eof())
        {
            if(isalpha(character))
            {
                countletters++;
            }
            if (isdigit(character))
            {
                countnum++;
            }
            if (ispunct(character))
            {
                countpunc++;
                if (isalpha(prevchar))
                {
                    words++;
                }
            }
            if (isspace(character))
            {
                countspace++;
                if (isalpha(prevchar))
                {
                    words++;
                }
            }
            if(character=='\n')
            {
                line++;
            }
            prevchar = character;
        }
        cout << "There are " << countletters << " letters." << endl;
        cout << "There are " << countnum << " numbers." << endl;
        cout << "There are " << countpunc << " punctuations." << endl;
        cout << "There are " << countspace << " spaces." << endl;
        cout << "There are " << words << " words." << endl;
        cout << "There are " << line << " sentences." << endl;
        lab3.close();
    }
}

