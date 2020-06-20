//
//  Pig.cpp
//  Pig
//
//

#include "Pig.h"
#include <iostream>
using namespace std;

namespace cs31
{
    Pig::Pig()
    {
        
    }
    
    // stringify this Game by stringifying this Game's Board
    std::string Pig::display( std::string msg )
    {
        using namespace std;
        std::string s = mBoard.display();
        s = s + msg;
        
        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Pig!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Pig!\n";
            }
        }
        return( s );
    }
    
    // TODO: let the human player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    // once you have a rolled amount, inform the board that it is now
    // the human's turn, set the board's rolled value and update the board's
    // human score accordingly
    int Pig::humanPlay( int amount )
    {
		int amountrolled = mHuman.roll(amount); //this line already handles scoring
		mBoard.setHumanTurn();
		mBoard.setRolledValue(amountrolled);

		if (amountrolled == 1) {
			humanEndTurn();
		}

		mBoard.setHumanScore(mHuman.getScore());
        return( amountrolled );
    }
    
    // inform the human Player that their turn has ended
    // update the board's human total
    void Pig::humanEndTurn()
    {
        mHuman.endTurn(); //handles the scoring for the person
		mBoard.setHumanTotal(mHuman.getTotal());
    }
    
    // TODO: let the computer player play
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    // once you have a rolled amount, inform the board that it is now
    // the computer's turn, set the board's rolled value and update the board's
    // computer score accordingly
    int Pig::computerPlay( int amount )
    {
		int amountrolled = mComputer.roll(); //this line already handles scoring

		mBoard.setComputerTurn();
		mBoard.setRolledValue(amountrolled);

		if (amountrolled == 1) {
			computerEndTurn();
		}

		mBoard.setComputerScore(mComputer.getScore());
		return(amountrolled);
    }
    
    // when keeprolling returns true, the computer will keep rolling
    // this method implements a 60% chance to keep rolling...
    // unless the score plus the existing total >= SCORENECESSARYTOWIN
    bool Pig::computerKeepRolling() const
    {
        bool result( false );
        Die d( 5 );
        d.roll();
        if (d.getValue() >= 3)
        {
            result = true;
        }
        if (mComputer.getScore() + mComputer.getTotal() >= SCORENECESSARYTOWIN)
        {
            // stop...
            result = false;
        }
        return( result );
    }
    
    // inform the computer Player that their turn has ended
    // update the board's computer total
    void Pig::computerEndTurn()
    {
        mComputer.endTurn();
        mBoard.setComputerTotal( mComputer.getTotal() );
    }
    
    // TODO: determine the game outcome at this moment
    Pig::GAMEOUTCOME  Pig::determineGameOutcome( ) const
    {
		// first player to 30 wins!   which is the value of    SCORENECESSARYTOWIN

		int compSum = mBoard.getComputerTotal(); //+ mBoard.getComputerScore();
		int humanSum = mBoard.getHumanTotal(); //+ mBoard.getHumanScore();

		if (( compSum >= SCORENECESSARYTOWIN) || (humanSum >= SCORENECESSARYTOWIN)) {
			if (compSum > humanSum) {
				return GAMEOUTCOME::COMPUTERWONGAME;
			}
			else if (compSum < humanSum) {
				return GAMEOUTCOME::HUMANWONGAME;
			}
			else
				cerr << "This should never run!" << endl; //TIE
		}
        return(GAMEOUTCOME::GAMENOTOVER);
    }
    
    // TODO: determine if the game is over
    // if it has, return true and inform the board that the game is over and
    // inform the board that the Human won or the Computer won, accordingly
    bool Pig::isGameOver()
    {
		if (determineGameOutcome() != GAMEOUTCOME::GAMENOTOVER) {
			if (determineGameOutcome() == GAMEOUTCOME::COMPUTERWONGAME) {
				mBoard.markComputerAsWinner();
				mBoard.setGameOver(true);
				return true;
			}
			else if (determineGameOutcome() == GAMEOUTCOME::HUMANWONGAME) {
				mBoard.markHumanAsWinner();
				mBoard.setGameOver(true);
				return true;
			}
			else
				cerr << "This should never run!" << endl;
		}
		return false;
    }

}
