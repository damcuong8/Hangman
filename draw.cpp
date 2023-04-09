#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
// hàm xóa màn hình bằng cách in ra nhiều dòng trắng.
void clearScreen() {
    const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}

const string FIGURE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };
// hàm để vẽ giao diện game
void renderGame(const string& guessedWord, const string& wrongGuesses)
{
    clearScreen();
	int wrongGuessCount = wrongGuesses.length();
	cout << FIGURE[wrongGuessCount] << endl;
	cout << "Secret word: " << guessedWord << endl;
	if (wrongGuessCount > 0) {
		cout << "You've made " << wrongGuessCount << " wrong ";
		cout << (wrongGuessCount == 1 ? "guess" : "guesses");
		cout << ": " << wrongGuesses << endl;
	}

}
// hàm lưu trữ hình vẽ khi win và trả về lần lượt các hình mỗi khi hàm được gọi
const string& getNextDancingMan() {
    const static string figure[] = {
    "     O     \n"
    "    /|\\   \n"
    "    | |    \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "    \\O/   \n"
    "     |     \n"
    "    / \\   \n",
    "   __O__   \n"
    "     |     \n"
    "    / \\   \n",
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "    O      \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "      O    \n"
    "    /|\\   \n"
    "    / \\   \n" ,
    "     O     \n"
    "    /|\\   \n"
    "    / \\   \n" ,


    };
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}
//hàm trả về lưu trữ hình vẽ khi thua và trả về lần lượt các hình mỗi khi hàm được gọi
const string& getNextHangMan() {
    const static string figure[] = {
    "   ------------+    \n"
    "   |    /           \n"
    "   |    O      \n"
    "   |   /|\\    \n"
    "   |   / \\    \n"
    "   |        \n"
    " -----      \n" ,
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n",
    "   ------------+     \n"
    "   |      \\         \n"
    "   |      O          \n"
    "   |     /|\\        \n"
    "   |     / \\        \n"
    "   |      \n"
    " -----    \n",
    "   ------------+     \n"
    "   |     |           \n"
    "   |     O           \n"
    "   |    /|\\         \n"
    "   |    / \\         \n"
    "   |        \n"
    " -----      \n"
    };
    const static int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);//số lượng hình vẽ
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}
// hàm đưa ra kết quả cuối cùng
void displayFinalResult(bool won, const string& word) {
    while (true) {
        clearScreen();
        if (won)
            cout << "Congratulations! You win!" << endl;
        else
            cout << "You lost. The correct word is " << word << endl;
        cout << (won ? getNextDancingMan() : getNextHangMan());
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
