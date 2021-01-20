//preprocessor directive
#include<iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //ASCII art
    std::cout << "\n";
    std::cout << "           __________                                 \n";
    std::cout << "         .'----------`.                              \n";
    std::cout << "         | .--------. |                             \n";
    std::cout << "         | |########| |       __________              \n";
    std::cout << "         | |########| |      /_________ \\             \n";
    std::cout << ".--------| `--------' |------|    --=-- |-------------.\n";
    std::cout << "|        `----,-.-----'      |o ======  |             | \n";
    std::cout << "|       ______|_|_______     |__________|             | \n";
    std::cout << "|      /  %%%%%%%%%%%%  \\                             | \n";
    std::cout << "|     /  %%%%%%%%%%%%%%  \\                            | \n";
    std::cout << "|     ^^^^^^^^^^^^^^^^^^^^                            | \n";
    std::cout << "+-----------------------------------------------------+\n";
    std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n";
    
    //expression statements
    std::cout << std::endl;
    std::cout << "You're a prisoner who is going to break out of a prison cell " << Difficulty;
    std::cout << std::endl;
    std::cout << "You need to enter the correct codes to each door to leave the prison..." << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //declaration statements
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //expression statements
    std::cout << std::endl;
    std::cout << "+ There are three numbers in the code \n";
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your guesses below \n \n";
    std::cout << std::endl;

    //Store player's guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    std::cout << std::endl;
    //std::cout << "+ Your guesses are " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    //std::cout << "+ The sum of your numbers is " << GuessSum << std::endl;
    //std::cout << "+ The product of your numbers is " << GuessProduct << std::endl;


    //check if the player's guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n *** Well done! You passed through the cell! ***";
        return true;
    }
    else
    {
        std::cout << "\n *** You entered the wrong code! Retry! *** ";
        return false;
    }
}

//main function statement
int main()
{
    srand(time(NULL)); //create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaximumDifficulty = 5;

    while (LevelDifficulty <= MaximumDifficulty) //loop level until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any errors
        std::cin.ignore(); //discards the buffer

        if (bLevelComplete)
        {
            //increase the difficulty
            ++LevelDifficulty;
        }
    }
    //return statement
    std::cout << "\n *** You are abcolutely free! ***\n";
    return 0;
}