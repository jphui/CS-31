//
//  main.cpp
//  Bunco
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Die.h"
#include "Player.h"
#include "Pig.h"


void clearScreen( );
bool handleComputerPlay( cs31::Pig & game );
void display( cs31::Pig & game, std::string message="", bool checkForGameOver=false );

int mainC()
{
	using namespace std;
	using namespace cs31;

	Die d;
	Player p;
	Board board, b1;
	Pig game;
	// test code for Die
	for (int i = 1; i <= 100; i++)
	{
		d.roll();
		int value = d.getValue();
		assert(value >= 1 && value <= 6);
	}
	// test code for Player

	assert(p.getScore() == 0);
	assert(p.getTotal() == 0);
	assert(p.roll(6) == 6);
	assert(p.getScore() == 6);
	assert(p.roll(5) == 5);
	assert(p.getScore() == 11);
	p.endTurn();
	assert(p.getScore() == 0);
	assert(p.getTotal() == 11);
	assert(p.roll(4) == 4);
	assert(p.getScore() == 4);
	assert(p.roll(5) == 5);
	assert(p.getScore() == 9);
	assert(p.roll(6) == 6);
	assert(p.getScore() == 15);
	p.endTurn();
	assert(p.getScore() == 0);
	assert(p.getTotal() == 26);
	assert(p.roll(4) == 4);
	assert(p.getScore() == 4);
	assert(p.roll(5) == 5);
	assert(p.getScore() == 9);
	assert(p.roll(1) == 1);
	assert(p.getScore() == 0);
	assert(p.getTotal() == 26);

	// test code for Board
	assert(board.getComputerTotal() == 0);
	assert(board.getHumanTotal() == 0);
	assert(board.getRolledValue() == 0);
	assert(board.getComputerScore() == 0);
	assert(board.getHumanScore() == 0);
	assert(board.isHumanWinner() == false);
	assert(board.isHumanTurn() == true);
	assert(board.isGameOver() == false);
	board.setComputerTurn();
	board.setComputerTotal(1);
	board.setComputerScore(2);
	board.setHumanTurn();
	board.setHumanScore(3);
	board.setHumanTotal(4);
	board.setRolledValue(7);
	assert(board.getComputerTotal() == 1);
	assert(board.getHumanTotal() == 4);
	assert(board.getRolledValue() == 7);
	assert(board.getComputerScore() == 2);
	assert(board.getHumanScore() == 3);
	assert(board.isHumanWinner() == false);
	assert(board.isHumanTurn() == true);
	assert(board.isGameOver() == false);
	// test code for b1 - board's should accept values passed to them 
	b1.setComputerTurn();
	b1.setComputerTotal(21);
	b1.setComputerScore(22);
	b1.setHumanTurn();

	// no changes allowed if it isn't your turn...
	b1.setComputerTotal(50);
	b1.setComputerScore(50);
	assert(b1.getComputerTotal() == 21);
	assert(b1.getComputerScore() == 22);
	b1.setHumanScore(23);
	b1.setHumanTotal(24);
	b1.setRolledValue(27);
	b1.setRolledValue(250);
	b1.setGameOver(true);
	b1.markComputerAsWinner();
	assert(b1.getComputerTotal() == 21);
	assert(b1.getHumanTotal() == 24);
	assert(b1.getRolledValue() == 250);
	assert(b1.getComputerScore() == 22);
	assert(b1.getHumanScore() == 23);
	assert(b1.isHumanWinner() == false);
	assert(b1.isHumanTurn() == true);
	assert(b1.isGameOver() == true);

	// no board changes allowed if the game is over...
	b1.setComputerTurn();
	b1.setComputerTotal(50);
	b1.setComputerScore(50);
	b1.setRolledValue(50);
	assert(b1.getComputerTotal() == 21);
	assert(b1.getComputerScore() == 22);
	assert(b1.getRolledValue() == 250);



	// test code for Game
	assert(game.isGameOver() == false);
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER);
	game.humanPlay(5);
	game.humanEndTurn();
	game.computerPlay(5);
	game.computerEndTurn();
	assert(game.isGameOver() == false);
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER);
	game.humanPlay(5);
	game.humanPlay(5);
	game.humanPlay(5);
	game.humanEndTurn();
	assert(game.isGameOver() == false);
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER);
	game.computerPlay(5);
	game.computerPlay(5);
	game.computerPlay(5);
	assert(game.isGameOver() == false);
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::GAMENOTOVER);
	game.humanPlay(5);
	game.humanPlay(6);
	game.humanEndTurn();
	assert(game.isGameOver() == true);
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME);

	// once the game is over, scores can't be changed
	game.computerPlay(6);
	game.computerPlay(6);
	game.computerPlay(6);
	game.computerEndTurn();
	assert(game.isGameOver() == true);
	assert(game.determineGameOutcome() == Pig::GAMEOUTCOME::HUMANWONGAME);

	cout << "all tests passed!" << endl;
	return 0;

}


int main()
{
    using namespace cs31;
    using namespace std;
    
    clearScreen();
    
    Pig game;
    int human;
    std::string action, message = "(r)oll (e)ndturn (q)uit: ";
    display( game, message, false );

    
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                return 0;
            case 'r':
            case 'R':
                human = game.humanPlay();
                cout << "human rolled:" << human << endl;
                if (human == 1)
                {
                    game.humanEndTurn();
                    display( game );
                    do
                    {
                        if (handleComputerPlay( game ))
                            break;
                    } while (game.computerKeepRolling());
                    game.computerEndTurn();
                    display( game, message, true );
                }
                break;
            case 'e':
            case 'E':
                game.humanEndTurn();
                cout << game.display(  ) << endl;
                do
                {
                    if (handleComputerPlay( game ))
                        break;
                }
                while( game.computerKeepRolling());
                game.computerEndTurn();
                display( game, message, true );
                break;
        }
        
    } while( !game.isGameOver() );
    
    return( 0 );
}



bool handleComputerPlay( cs31::Pig & game )
{
    using namespace std;
    
    bool result( false );
	if (!game.isGameOver()) {
		int computer = game.computerPlay();
		cout << "computer rolled:" << computer << endl;
		if (computer == 1)
		{
			result = true;
		}
	}
    return( result );
}


void display( cs31::Pig & game, std::string message, bool checkForGameOver )
{
    using namespace std;

	if (!game.isGameOver() || game.determineGameOutcome() == cs31::Pig::COMPUTERWONGAME)
	{
		cout << game.display(message) << endl;
	}
    
    if (checkForGameOver)
    {
        game.isGameOver();
    }
}



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif

