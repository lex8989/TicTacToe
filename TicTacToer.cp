#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };

int checkwin();
void board();
void playAgainstAI();

int main()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    system("Color 7C");
cout << "'########:'####::'######::'########::::'###:::::'######::'########::'#######::'########:" << endl;
cout << "... ##..::. ##::'##... ##:... ##..::::'## ##:::'##... ##:... ##..::'##.... ##: ##.....::" << endl;
cout << "::: ##::::: ##:: ##:::..::::: ##:::::'##:. ##:: ##:::..::::: ##:::: ##:::: ##: ##:::::::" << endl;
cout << "::: ##::::: ##:: ##:::::::::: ##::::'##:::. ##: ##:::::::::: ##:::: ##:::: ##: ######:::" << endl;
cout << "::: ##::::: ##:: ##:::::::::: ##:::: #########: ##:::::::::: ##:::: ##:::: ##: ##...::::" << endl;
cout << "::: ##::::: ##:: ##::: ##:::: ##:::: ##.... ##: ##::: ##:::: ##:::: ##:::: ##: ##:::::::" << endl;
cout << "::: ##::::: ##:: ##::: ##:::: ##:::: ##.... ##: ##::: ##:::: ##:::: ##:::: ##: ##:::::::" << endl;
cout << "::: ##::::'####:. ######::::: ##:::: ##:::: ##:. ######::::: ##::::. #######:: ########:" << endl;
cout << ":::..:::::....:::......::::::..:::::..:::::..:::......::::::..::::::.......:::........::" << endl;

    int player = 1, i, choice;
    cout << "Enter 1 to play against another player, or 2 to play against the AI: ";
    int gameMode;
    cin >> gameMode;

    if (gameMode == 1) {
        do {
            board();
            player = (player % 2) ? 1 : 2;

            cout << "Player " << player << ", enter a number:  ";
            cin >> choice;

            char mark = (player == 1) ? 'X' : 'O';

            if (choice == 1 && square[1] == '1')
                square[1] = mark;
            else if (choice == 2 && square[2] == '2')
                square[2] = mark;
            else if (choice == 3 && square[3] == '3')
                square[3] = mark;
            else if (choice == 4 && square[4] == '4')
                square[4] = mark;
            else if (choice == 5 && square[5] == '5')
                square[5] = mark;
            else if (choice == 6 && square[6] == '6')
                square[6] = mark;
            else if (choice == 7 && square[7] == '7')
                square[7] = mark;
            else if (choice == 8 && square[8] == '8')
                square[8] = mark;
            else if (choice == 9 && square[9] == '9')
                square[9] = mark;
            else {
                cout << "Invalid move ";
                player--;
                cin.ignore();
                cin.get();
            }
            i = checkwin();
            player++;
        } while (i == -1);

        board();

        if (i == 1)
            cout << "==>\aPlayer " << --player << " wins! ";
        else
            cout << "==>\aGame draw! ";
    }
    else {
        // Play against AI mode
        playAgainstAI();
    }

    cin.ignore();
    cin.get();
    return 0;
}

void playAgainstAI() {
    int player = 1, i, choice;
    char mark;
    do {
        board();
        player = (player % 2) ? 1 : 2;

        if (player == 1) {
            cout << "Player " << player << ", enter a number:  ";
            cin >> choice;
        }
        else {
            // AI's turn
            do {
                srand(time(NULL));
                choice = rand() % 9 + 1;
            } while (square[choice] == 'X' || square[choice] == 'O');
            cout << "AI chooses " << choice << endl;
        }

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
        else {
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();
        player++;
    } while (i == -1);
    board();

    if (i == 1)
        cout << "==>\aPlayer " << --player << " wins! ";
    else
        cout << "==>\aGame draw! ";
}

int checkwin() {
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

void board() {
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;


    cout << "" << endl;
}
