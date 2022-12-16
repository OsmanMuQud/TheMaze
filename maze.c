#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
int m = 15, n = 15;
int plx = 0, ply = 0;
//makes random maze// 
void makeCells(bool cells[][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rand() % 10 < 5)
            {
                cells[i][j] = true;
                continue;
            }
            cells[i][j] = false;
        }
    }
    cells[0][0] = false;
    cells[m - 1][n - 1] = false;
}
//displays the cells as ascii character
void showCells(bool cells[][n])
{
    system("cls");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == ply && j == plx)
            {
                printf("\033[0;31m* "); //red astrisk
                printf("\033[0m");      //sets back the color to default
                continue;
            }
            if (i == m - 1 && j == n - 1) // last element
            {
                printf("\033[0;33mO ");
                printf("\033[0m");
                continue;
            }
            if (cells[i][j])
            {
                printf("# "); //walls
            }
            else
            {
                printf(". "); //empty space
            }
        }
        printf("\n");
    }
}
//maps the keys to the corresponding movement
bool move(char c, bool cells[][n])
{
    if (c == 'd' || c == 'D')
    {
        if ((plx + 1 < n) && !(cells[ply][plx + 1]))
        {
            plx++;
        }
    }
    else if (c == 'a' || c == 'A')
    {
        if ((plx - 1 >= 0) && !(cells[ply][plx - 1]))
        {
            plx--;
        }
    }
    else if (c == 'w' || c == 'W')
    {
        if ((ply - 1 >= 0) && !(cells[ply - 1][plx]))
        {
            ply--;
        }
    }
    else if (c == 'x' || c == 'X')
    {
        if ((ply + 1 < m) && !(cells[ply + 1][plx]))
        {
            ply++;
        }
    }
    else if (c == 'c' || c == 'C')
    {
        if ((ply + 1 < m && plx + 1 < n) && !(cells[ply + 1][plx + 1]))
        {
            ply++;
            plx++;
        }
    }
    else if (c == 'z' || c == 'Z')
    {
        if ((ply + 1 < m && plx - 1 >= 0) && !(cells[ply + 1][plx - 1]))
        {
            ply++;
            plx--;
        }
    }
    else if (c == 'q' || c == 'Q')
    {
        if ((ply - 1 >= 0 && plx - 1 >= 0) && !(cells[ply - 1][plx - 1]))
        {
            ply--;
            plx--;
        }
    }
    else if (c == 'e' || c == 'E')
    {
        if ((ply - 1 >= 0 && plx + 1 < n) && !(cells[ply - 1][plx + 1]))
        {
            ply--;
            plx++;
        }
    }
    else if (c == 'r' || c == 'R')
    {
        makeCells(cells);
        showCells(cells);
        ply = 0;
        plx = 0;
        return false;
    }
    return true;
}
//recieves the charwise input from the user and moves the astriks simultaniously
void playChar(bool cells[][n])
{
    while (true)
    {
        char c = getch();
        bool movem = move(c, cells);
        showCells(cells);
        printf("This is the EASY mode here you can move the * one move at a time.\n");
        if (ply == m - 1 && plx == n - 1 || !movem)
        {
            break;
        }
    }
}
//recieves the whole solution then executes char wise
void playSent(bool cells[][n])
{
    char c[1000];
    int i = 0;
    scanf("%s", &c);
    while (c[i] != '\0')
    {
        if (!move(c[i++], cells))
        {
            break;
        };
        showCells(cells);
    }
}
void main()
{
    while (true)
    {
        ply = 0;
        plx = 0;
        char mode = '\0';
        //THIS DISPLAYS THE MENU
        do
        {
            system("cls");
            printf("\n\033[33m");
            printf("\033[33m#       #  \033[35m   ##      \033[31m#########   \033[32m#########\n");
            printf("\033[33m# #    ##  \033[35m  #  #     \033[31m       #    \033[32m#        \n");
            printf("\033[33m#  #  # #  \033[35m #    #    \033[31m     #      \033[32m#########\n");
            printf("\033[33m#   #   #  \033[35m########   \033[31m   #        \033[32m#        \n");
            printf("\033[33m#       #  \033[35m#      #   \033[31m #          \033[32m#        \n");
            printf("\033[33m#       #  \033[35m#      #   \033[31m#########   \033[32m#########\n\033[0m");
            printf("Enter a solution for the maze.\nAssume you are the s key and then press surrounding keys to move to that cell.\nYou are the astrisk and you have to reach \033[33mO\033[0m.");

            printf("\n\n\t Q W E\n");
            printf("\t A \033[31mS \033[0mD\n");
            printf("\t Z X C\n\n");
            printf("USE THESE KEYS TO MOVE TO THE NEXT CELL");
            printf("\n\n");

            printf("\nselect difficulty level\n");
            printf("\tEasy Mode(e)\n\tHard Mode(h)\n");
            scanf("%c", &mode);
        } while (!(mode == 'e' || mode == 'E' || mode == 'h' || mode == 'H'));
        //initalizes all
        srand(time(NULL));
        bool cells[m][n];
        makeCells(cells);
        showCells(cells);
        int tries = 3;
        //hard mode game
        if (mode == 'h' || mode == 'H')
        {
            // printf("Enter the number of tries: ");
            // scanf("%d", &tries);
            printf("This is the HARD mode here you have to write the complete string of the solution and see if it works.\n");
            for (int i = 0; i < tries; i++)
            {
                printf("%d tries left.\n", tries - i);
                playSent(cells);
                printf("This is the HARD mode here you have to write the complete string of the solution and see if it works.\n");
                if (ply == m - 1 && plx == n - 1)
                {
                    break;
                }
            }
        }
        //easy mode game
        if (mode == 'e' || mode == 'E')
        {
            printf("This is the EASY mode here you can move the * one move at a time.\n");
            playChar(cells);
        }
        //checks if the player won
        if (ply == m - 1 && plx == n - 1)
        {
            printf("Well done you won.(Press 'r' to continue to new game.)");
        }
        else
        {
            printf("Try again.(Press 'r' to continue to new game.)");
        }
        //restart
        if (getch() != 'r')
        {
            break;
        }
    }
}