#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include "draw.h"

using namespace std;

const int MAX_WRONG_GUESSES = 7;
const char VOCAB_FILE[] = "listvocabb2/vocab.txt";

string chooseWord(const char* fileName);
char readAGuess();
bool contains(const string& word, char guess);
void updateGuessedWord(string& guessedWord, const string& word, char guess);

int main()
{

	string word = chooseWord(VOCAB_FILE);
	if (word.length() < 1) {
		cout << "Error reading vocabulary file " << VOCAB_FILE;
		return -1;
	}
	string guessedWord = string(word.length(), '_');
	string WrongGuesses = "";

	do {
		renderGame(guessedWord, WrongGuesses);
		char guess = readAGuess();
		if (contains(word, guess))
			updateGuessedWord(guessedWord, word, guess);
		else {
			WrongGuesses += guess;
		}
	} while (WrongGuesses.length() < MAX_WRONG_GUESSES && word != guessedWord);
    displayFinalResult(WrongGuesses.length() < MAX_WRONG_GUESSES, word);

	return 0;
}
// hàm nhận vào thành chỗi và trả về một chuỗi in thường tương đương
string getLowerCaseString(const string& s)
{
    string temp = s;
    transform(s.begin(), s.end(), temp.begin(), ::tolower);
    return temp;
}
// hàm đọc dữ liệu từ tệp ra một mảng vector và trả về ngẫu nhiên một từ
string chooseWord(const char* fileName)
{
	vector<string> vocabList;
	ifstream file(fileName);
  	if (file.is_open()) {
	    string word;
		while (file >> word) {
            vocabList.push_back(word);
        }
    	file.close();
  	}
  	if (vocabList.size() > 0) {
        srand(time(0));
  		int randomIndex = rand() % vocabList.size();
    	return getLowerCaseString(vocabList[randomIndex]);
	} else return "";
}
// hàm nhận vào kí tự người chơi đoán và trả về kí tự kí tự in thường tương tự
char readAGuess()
{
	char input;
	cout << "Your guess: ";
	cin >> input;
	return tolower(input);
}
//hàm kiểm tra kí tự c có xuất hiện trong chuỗi word không nếu có trả về true nếu không trả về fale
bool contains(const string& word, char c)
{
	return (word.find_first_of(c) != string::npos);
}
// hàm này để cập nhâtj chuỗi guessedWord khi người chơi đoán đúng một kí tự.
void updateGuessedWord(string& guessedWord, const string& word, char guess)
{
	for (int i = 0 ; i < word.length(); i++) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
        }
    }
}
