#include <iostream>
#include <ctime>
#include <conio.h>
#include <iomanip>

class Task1
{
public:
    static const int row = 2, col = 5;
    int status = 0, dieCount = 0;
    int dice1 = rand() % 6 + 1, dice2 = rand() % 6 + 1, dice3 = rand() % 6 + 1, dice4 = rand() % 6 + 1, dice5 = rand() % 6 + 1;
    
    int diceBoard[row][col]
    {
        {dice1, dice2, dice3, dice4, dice5},
        {status, status, status, status, status}
    };

    bool diceRoll = true;

public:
    void arraySolution()
    {
        printBoard();
        holdChoice();
    }

    void printBoard()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                std::cout << "|" << diceBoard[i][j] << "|";
            }
            std::cout << "\n";
        }
    }
    
    void holdChoice()
    {
        while (diceRoll == true)
        {
            std::cout << "\nPlease type the number of the dice you would like to reroll.\n";
            for (int i = 0; i < col; i++)
            {
                switch (_getch())
                {
                case '1':
                    diceBoard[1][0] = 1;
                    break;
                case '2':
                    diceBoard[1][1] = 1;
                    break;
                case '3':
                    diceBoard[1][2] = 1;
                    break;
                case '4':
                    diceBoard[1][3] = 1;
                    break;
                case '5':
                    diceBoard[1][4] = 1;
                }
                system("cls");
                printBoard();
            }

            for (int i = 0; i < col; i++)
            {
                if (diceBoard[1][i] == 1)
                {
                    diceBoard[0][i] = rand() % 6 + 1;

                }
                else if (diceBoard[1][i] == 0)
                {
                    dieCount++;
                }
                diceBoard[1][i] = 0;
            }

            std::cout << "\n";
            printBoard();

            if (dieCount == col)
            {
                diceRoll = false;
            }
            else
            {
                dieCount = 0;
            }
        }
        std::cout << "\nThese are your final die. Feel free to roll again.\n\n";
    }
};

class Task2
{
public:
    static const int row = 4, col = 4;

    int abilities[row][col]
    {
        {9, 21, 5, 8},
        {1, 3, 62, 1},
        {4, 2, 5, 8},
        {1, 23, 6, 1},
    };
public:
    /* One can see the next last character, increases by one for each row, and the
    last character increase by 4 for each colum, because an integer is 4 bytes. */
    void printArrayAddress()
    {
        std::cout << "The array's address in memory:\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                std::cout << &abilities[i][j] << " ";
            }
            std::cout <<std::endl;
        }
    }
};

int main()
{
    srand(std::time(nullptr));

    Task1 t1;
    Task2 t2;

    t1.arraySolution();
    t2.printArrayAddress();
}

