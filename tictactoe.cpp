#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <unistd.h> // for usleep function

// Functions of Musical Notes
void sa(int t) {
    std::cout << '\a';
    usleep(t * 1000);
}

void re(int t) {
    std::cout << '\a';
    usleep(t * 1000);
}

void ga(int t) {
    std::cout << '\a';
    usleep(t * 1000);
}

void ma(int t) {
    std::cout << '\a';
    usleep(t * 1000);
}

void pa(int t) {
    std::cout << '\a';
    usleep(t * 1000);
}

void dha(int t) {
    std::cout << '\a';
    usleep(t * 1000);
}

void ni(int t) {
    std::cout << '\a';
    usleep(t * 1000);
}

void Sa(int t) {
    std::cout << '\a';
    usleep(t * 1000);
}
// End of Musical Notes

void printmatrix(int *ptr) {
    std::cout << "                                MATRIX SITUATION\n";
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0)
            std::cout << "                                     ";
        if (ptr[i]) {
            if (ptr[i] == 1)
                std::cout << "X";
            if (ptr[i] == 10)
                std::cout << "O";
        } else {
            if (i < 6)
                std::cout << "_";
            else
                std::cout << " ";
        }
        if (i % 3 < 2)
            std::cout << "|";
        if (i % 3 == 2)
            std::cout << "\n";
    }
    return;
}

int checkmatrix(int *p) {
    if (p[0] + p[1] + p[2] == 3 || p[3] + p[4] + p[5] == 3 || p[6] + p[7] + p[8] == 3)
        return 1;
    else if (p[0] + p[1] + p[2] == 30 || p[3] + p[4] + p[5] == 30 || p[6] + p[7] + p[8] == 30)
        return 10;
    else if (p[0] + p[3] + p[6] == 3 || p[1] + p[4] + p[7] == 3 || p[2] + p[5] + p[8] == 3)
        return 1;
    else if (p[0] + p[3] + p[6] == 30 || p[1] + p[4] + p[7] == 30 || p[2] + p[5] + p[8] == 30)
        return 10;
    else if (p[0] + p[4] + p[8] == 3 || p[2] + p[4] + p[6] == 3)
        return 1;
    else if (p[0] + p[4] + p[8] == 30 || p[2] + p[4] + p[6] == 30)
        return 10;
    else
        return 0;
}

int checkinput(int i) {
    char str[100];
    if (i % 2 == 0)
        std::cout << "Player X , please enter your location number : " << std::endl;
    else
        std::cout << "Player O , please enter your location number : " << std::endl;
    std::cin.getline(str, 100);
    if (str[0] == '\0') {
        std::cout << "PLEASE ENTER SOMETHING...\n";
        usleep(1000 * 1000);
        return 0;
    }
    int len = strlen(str), n = (int)str[0] - 48;
    if (len > 1 || n <= 0 || n > 9) {
        std::cout << "                               !!!INVALID INPUT!!!" << std::endl << "Only single digit positive numbers are allowed." << std::endl;
        std::cout << "'0' , alphabets & special characters are not allowed. Please try AGAIN !" << std::endl;
        usleep(1000 * 1000);
        return 0;
    } else
        return n;
}

int main() {
    // Introduction
    std::cout << "              Welcome to SANKHLA GAMING : The Game of Tic Tac Toe" << std::endl;
    std::cout << "              *****************************************************" << std::endl;
    // Prelude
    sa(200);
    ga(200);
    pa(200);
    sa(200);
    ga(200);
    pa(200);
    sa(200);
    pa(200);
    ga(200);
    sa(200);
    // End of Prelude
    usleep(1000 * 1000);
    std::cout << "Rules and Regulations :" << std::endl;
    std::cout << "1.The game requires two players X & O." << std::endl;
    std::cout << "2.The game consists of a matrix with sections numbered as 1,2,3,4,5... like :" << std::endl;
    std::cout << "  1|2|3    _|_|_" << std::endl << "  4|5|6 OR _|_|_" << std::endl << "  7|8|9     | | " << std::endl;
    std::cout << "3.Alternatively the game will ask for position of X or O from respective player as input." << std::endl;
    std::cout << "4.Only single digit positive numbers are allowed. '0' , alphabets & special characters are not allowed." << std::endl;
    std::cout << "5.You(the players) have to input the location number where you want your X or O." << std::endl;
    std::cout << "6.After every move the situation of the matrix will be displayed." << std::endl;
    std::cout << "7.As soon as any one player manages to have 3 Xs or 3 Os in line (Horizontal/Vertical/Diagonal)..." << std::endl;
    std::cout << "8.He/She WINS THE GAME and the result is displayed automatically." << std::endl;
    std::cout << "So warm up your mental muscles and press any key to begin the game..." << std::endl;
    // End of Instructions
    std::cin.get();
    // The Game
    int ptr[9] = {0};
    printmatrix(ptr);
    // Input
    for (int i = 0; i < 9; i++) {
        int tmp = checkinput(i);
        if (tmp) {
            if (ptr[tmp - 1] != 0) {
                std::cout << "                       !!!OOPS,LOCATION ALREADY OCCUPIED!!!" << std::endl << "Please try AGAIN !" << std::endl;
                usleep(1000 * 1000);
                i--;
                continue;
            }
            if (i % 2 == 0)
                ptr[tmp - 1] = 1;
            else
                ptr[tmp - 1] = 10;
        } else {
            i--;
            continue;
        }
        printmatrix(ptr);
        // Win check
        if (i > 3) {
            int tmp = checkmatrix(ptr);
            if (tmp) {
                if (tmp == 1) {
                    std::cout << std::endl << std::endl;
                    std::cout << "                            *******GAME OVER*******" << std::endl;
                    std::cout << "                            ### X is the WINNER ###" << std::endl;
                    std::cout << "                            ***********************" << std::endl;
                    break;
                }
                if (tmp == 10) {
                    std::cout << std::endl << std::endl;
                    std::cout << "                            *******GAME OVER*******" << std::endl;
                    std::cout << "                            ### O is the WINNER ###" << std::endl;
                    std::cout << "                            ***********************" << std::endl;
                    break;
                }
            } else {
                if (i == 8) {
                    std::cout << std::endl << std::endl;
                    std::cout << "                           ********GAME  OVER********" << std::endl;
                    std::cout << "                           ### THE GAME IS A DRAW ###" << std::endl;
                    std::cout << "                           **************************" << std::endl;
                    break;
                }
            }
        }
    }
    std::cout << "Press ENTER key to exit." << std::endl;
    std::cin.ignore();
    return 0;
}
