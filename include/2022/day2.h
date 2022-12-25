#include <iostream>

enum RPSMove
{
    ROCK,
    PAPER,
    SCISSOR
};

struct RockPaperScissorRound
{
    /// @brief Parses a string of type "[Move] [Move]"
    /// and creats a round from it
    /// @return
    friend std::istream &operator>>(std::istream &is, RockPaperScissorRound &rpsRound)
    {
        char c;
        c = is.get();
        rpsRound.opponentMove_ = rpsRound.parseChar(c);
        c = is.get(); // discard the space
        c = is.get();
        rpsRound.userMove_ = rpsRound.parseChar(c);
        return is;
    }

    int scoreRoundUsingPlaymethod()
    {
        return getScoreForShape(userMove_) + getScoreForMatch(userMove_, opponentMove_);
    }

    int scoreRoundUsingOutcomeMethod()
    {
        switch (userMove_)
        {
        case RPSMove::ROCK:
        {
            auto loser = getLoserAgainst(opponentMove_);
            return 0 + getScoreForShape(loser);
        }
        case RPSMove::PAPER:
        {
            return 3 + getScoreForShape(opponentMove_);
        }
        case RPSMove::SCISSOR:
        {
            auto winner = getWinnerAgainst(opponentMove_);
            return 6 + getScoreForShape(winner);
        }
        }
    }

private:
    RPSMove parseChar(char &c)
    {
        switch (c)
        {
        case 'A':
        case 'X':
            return RPSMove::ROCK;
        case 'B':
        case 'Y':
            return RPSMove::PAPER;
        case 'C':
        case 'Z':
            return RPSMove::SCISSOR;
        default:
            ASSERT(false, "INVALID move : " << c);
        }
    }

    RPSMove getWinnerAgainst(RPSMove &move)
    {
        switch (move)
        {
        case RPSMove::ROCK:
            return RPSMove::PAPER;
        case RPSMove::PAPER:
            return RPSMove::SCISSOR;
        case RPSMove::SCISSOR:
            return RPSMove::ROCK;
        }
    }

    RPSMove getLoserAgainst(RPSMove &move)
    {
        switch (move)
        {
        case RPSMove::ROCK:
            return RPSMove::SCISSOR;
        case RPSMove::PAPER:
            return RPSMove::ROCK;
        case RPSMove::SCISSOR:
            return RPSMove::PAPER;
        }
    }

    int getScoreForMatch(RPSMove &player, RPSMove &opponent)
    {
        if (player == getWinnerAgainst(opponent))
            return 6;
        else if (player == getLoserAgainst(opponent))
            return 0;
        else
            return 3;
    }

    int getScoreForShape(RPSMove &move)
    {
        switch (move)
        {
        case RPSMove::ROCK:
            return 1;
        case RPSMove::PAPER:
            return 2;
        case RPSMove::SCISSOR:
            return 3;
        }
    }

    RPSMove opponentMove_;
    RPSMove userMove_;
};