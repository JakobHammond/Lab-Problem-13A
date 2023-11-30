//
//  main.cpp
//  please
//
//  Created by Jakob Hammond on 11/30/23.
//

#include <iostream>
#include <fstream>
using namespace std;

void pressEnterToContinue(void);
int main(void) {

    while(true){
        int letterAmounts[26];
        double letterFrequencies[26];
        ifstream lab3;
        string word;
        string fileName;
        cout << "Enter filename: ";
        cin >> fileName;
        lab3.open(fileName);
        int countletters=0;
        char character,prevchar = 0;
        
        for(int i = 0; i < 26; i++){
            letterAmounts[i] = 0;
        }
        
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
                
                for(int i = 0; i < 26; i++){
                    if(character == 65 + i || character == 97 + i) letterAmounts[i] += 1;
                }
                
            }
            
            prevchar = character;
        }
        
        for(int i = 0; i < 26; i++){
            letterFrequencies[i] = (double) letterAmounts[i] / countletters * 100;
        }
        
        cout << "\nTotal number of letters: " << countletters << endl;
        printf("Frequencies: \n");
        
        for(int i = 0; i < 26; i++){
            printf("\'%c\': %f\n", i + 65, letterFrequencies[i]);
        }
            
        pressEnterToContinue();
        
        
        
        lab3.close();
    }
}

void pressEnterToContinue(void){
    char c;
    cout << "Press Enter to continue...";
    cin.ignore(1024, '\n');
    do{cin.get(c); }while(c != '\n' && c != EOF);
    return;
}
