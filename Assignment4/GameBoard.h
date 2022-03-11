#if !defined(GAMEBOARD_H)
#define GAMEBOARD_H

#include <iostream>
#include <string>

class GameBoard
{
    public:
        GameBoard();
        GameBoard(GameBoard &g);
        ~GameBoard();

        void InitCopyGrid(GameBoard originalBoard);
        void InitGridOfKnownSize(int numOfRows, int numOfCols);
        void InitFileGrid(int numOfRows, int numOfCols);
        void InitGridRand();

        int GetNumRows();
        int GetNumCols();
        char GetCharAt(int row, int col);

        void ChangeCurrElementPos(int row, int col, char c);

        void DisplayGrid();

    private:
        int numRows = 0;
        int numColumns = 0;
        
        char **someGrid;
        //char **copyGrid;

        void InitNumRowsAndColumns();

        double CheckValidInitWorldPop(double population);
        void DensityPlacement(double popDensity);
};

#endif