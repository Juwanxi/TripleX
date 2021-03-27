#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room... \nEnter the correct codes to continue... \n\n";

}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code 
   const int CodeA = rand() % Difficulty + Difficulty;
   const int CodeB = rand() % Difficulty + Difficulty;
   const int CodeC = rand() % Difficulty + Difficulty;

   const int CodeSum = CodeA + CodeB + CodeC;
   const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the ternimal 
    std::cout << "There are 3 numbers in the code";
    std::cout << "\nThe codes add-up to: " << CodeSum;
    std::cout << "\nThe codes mulltiply to give: " << CodeProduct << std::endl;

    // Store players guess 
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
   
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    // Check if the players guess is correct 
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
    {
        std::cout << "\nYou're in! Go to the next level. \n";
        return true;
    }
    else
    {
        std::cout << "\nYou've been busted! \nTry again";
        return false;
    }

} 

int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;
    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are cleared 
    {
        bool bLevelCleared = PlayGame(LevelDifficulty);
         std::cin.clear(); // Clear any errors
         std::cin.ignore(); // Discards the buffer

         if (bLevelCleared)
         {
             ++LevelDifficulty;
         }
         
    }
   
    std::cout << "\n*** Congrats! You've hacked into NASA! Now return to base ASAP! ***\n";
    return 0;
}