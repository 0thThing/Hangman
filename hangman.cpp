#include "std_lib_facilities.h"
#include <ctime>

int main(){
    vector<string> words;
    ifstream fin("words_alpha.txt");//the program will read in the words from this file, so make sure the file name is correct
	vector<string> hangman;
	
	string drawing = "   |-|   \n"
				     "     |   \n"
					 "     |   \n"
					 "     |   \n";
	words.push_back(drawing);
	
	drawing = 		 "   |-|   \n"
					 "   ^ |   \n"
					 "     |   \n"
					 "     |   \n";
	words.push_back(drawing);
	
	drawing = 		 "   |-|   \n"
					 "   ^ |   \n"
					 "   O |   \n"
					 "     |   \n"
					 "     |   \n";
	words.push_back(drawing);
	
	drawing = 		 "   |-|   \n"
					 "   ^ |   \n"
					 "   O |   \n"
					 "   | |   \n"
					 "     |   \n";
	words.push_back(drawing);
	
	drawing = 		 "   |-|   \n"
					 "   ^ |   \n"
					 "   O |   \n"
					 "   |-|   \n"
					 "       \n";
	words.push_back(drawing);
	
	drawing = 		 "   |-|   \n"
					 "   ^ |   \n"
					 "   O |   \n"
					 "  -|-|   \n"
					 "     |\n";
	words.push_back(drawing);
	
	drawing = 		 "   |-|   \n"
					 "   ^ |   \n"
					 "   O |   \n"
					 "  -|-|   \n"
					 "   | |   \n";
	words.push_back(drawing);
	
	drawing = 		 "   |-|   \n"
					 "   ^ |   \n"
					 "   O |   \n"
					 "  -|-|   \n"
					 "   | |   \n"
					 "  / ";
	words.push_back(drawing);
	
	drawing = 		 "   |-|   \n"
					 "   ^ |   \n"
					 "   O |   \n"
					 "  -|-|   \n"
					 "   | |   \n"
					 "  / \\";
	words.push_back(drawing);
	
	drawing = 		 "   |-|   \n"
					 "   ^ |   \n"
					 "   O |   \n"
					 "  -|-|   \n"
					 "   | |   \n"
					 "  / \\";
	words.push_back(drawing);
					 
	
	
    while(!fin.eof()){//puts all the words from the file into a vector
        string line;
        getline(fin,line);
        words.push_back(line);
    }
	
	
    srand (time(NULL));
    string guessword = words[rand() % words.size()];//picks the word to be guessed from the vector
    vector<char> guessedLetters;//vector of letters that have been guessed
    int wrongCount = 0;
    int maxWrong = 8;
	int correct=0;//keeps track of the correct guesses
    vector<char> correctLetters(guessword.size(),'_');//vector to be printed out for user to guess from
    char curGuess;
	
    while(wrongCount < maxWrong && correct != correctLetters.size()){
		cout<<"guess a letter"<<endl;
        cin >> curGuess;
		cout <<"the word was "<<guessword<<endl;
		cout <<"you guessed "<<curGuess<<endl;
		
        bool guessed = false;
		
        for(char curLet: guessedLetters){//checks if you have already guessed the letter or not
            if(curLet == curGuess) guessed = true;
        }
		
		guessedLetters.push_back(curGuess);
        bool noGuesses = true;//boolean for if the letter is in the word or not 
        if(!guessed){//has this letter been guessed?? if not enter the loop
        for(int i = 0; i < guessword.size() ; i++){//loops through guessword
            if(guessword[i] == curGuess){//checks if the guess letter is in the guessword
				correctLetters[i] = curGuess;
				correct++;
                noGuesses = false;
            }
        }
        }
		else//if it has been guessed
		{
			cout<<"you have guessed this letter"<<endl;
		}
		
        if(noGuesses){//increments wrong count if the letter is not in the word
            wrongCount++;
        }
		
		cout<<"you have "<<wrongCount<<"out of 8 wrong guesses"<<endl;
		cout<<words[wrongCount]<<endl;
		for (int i=0; i<correctLetters.size();i++)
		{
			cout<<correctLetters[i];
		}
		cout<<" "<<endl;
		cout<<"these are the letters you have guessed already"<<endl;
		for (int i=0; i<guessedLetters.size();i++)
		{
			cout<<guessedLetters[i]<<" ";
		}
		cout<<" "<<endl;
    }//game loop ends here
	//decide upon outcome of game W/L?
	
	if(correct == correctLetters.size())
	{
		cout<<"you won!!!"<<endl;
	}
	else
	{
		cout<<"the word was "<<guessword<<endl;
		cout<<"you lost, Game Over"<<endl;
	}
    return 0;
}



