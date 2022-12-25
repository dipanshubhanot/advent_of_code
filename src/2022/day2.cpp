#include "2022/tasks.h"
#include "2022/day2.h"

void day2(std::string &filename)
{
    // file must exist
    ASSERT(std::filesystem::exists(filename), "Given file does not exist: " << filename);

    // read input, process by each line
    std::ifstream instream;
    instream.open(filename);
    int scoreUsingPlayMethod = 0;
    int scoreUsingOutcomeMethod = 0;
    while (!instream.eof())
    {
        RockPaperScissorRound round{};
        instream >> round;
        int roundScorePlayMethod = round.scoreRoundUsingPlaymethod();
        int roundScoreOutcomeMethod = round.scoreRoundUsingOutcomeMethod();
        scoreUsingPlayMethod += roundScorePlayMethod;
        scoreUsingOutcomeMethod += roundScoreOutcomeMethod;
        instream.get(); // gets rid of the new line character
    }
    instream.close();

    std::cout << "Total score after following plan: " << scoreUsingPlayMethod << "(Play Method) " << scoreUsingOutcomeMethod << "(Outcome Method)" << std::endl;
}