#include <iostream>
#include <string>
#include <random>
#include <unordered_map>

int main()
{
    bool playing = true;
    std::string userMoveStr, playAgain;
    int playerWins = 0, compWins = 0, compMove, userMove, result;
    typedef std::unordered_map<int, std::string> moveMap;
    moveMap moves = { {1, "Rock"}, {2, "Paper"}, {3, "Scissors"} };

    // Initialize random number generator
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 3); // define the range

    std::cout << "Добро пожаловать!" << std::endl;

    while(playing)
    {
        std::cout << "Введите 1, чтобы сыграть в Камень, 2, чтобы сыграть в Бумагу, и 3, чтобы сыграть в Ножницы.!: ";
        getline(std::cin, userMoveStr);

        while(!(userMoveStr == "1" || userMoveStr == "2" || userMoveStr == "3"))
        {
            std::cout << "Неизвестная команда! Пожалуйста, попробуйте еще раз..." << std::endl;
            std::cout << "Введите 1, чтобы сыграть в Камень, 2, чтобы сыграть в Бумагу, и 3, чтобы сыграть в Ножницы.!: ";
            getline(std::cin, userMoveStr);
        }

        // Convert the user move from a string to an integer
        userMove = std::stoi(userMoveStr);

        // Create random integer in range [1,3] to simulate the computer selecting a move
        compMove = distr(eng);

        result = userMove - compMove;

        if(result == 0)
            std::cout << "Игра в галстук!" << std::endl;
        else if(result == 1 || result == -2)
        {    
            std::cout << "Поздравляю, вы выиграли!" << std::endl;
            playerWins++;
        } else
        {
            std::cout << "Извини ты проиграл!" << std::endl;
            compWins++;
        }

        std::cout << "Твой ход: " << moves[userMove] << " // Компьютерный ход: " << moves[compMove] << std::endl;
        std::cout << "(Игрок: " << playerWins << " | Компьютер: " << compWins << ")" << std::endl;
        std::cout << "Играть снова? [д/н]: ";
        getline(std::cin, playAgain);
        
        while(!(playAgain == "y" || playAgain == "n"))
        {
            std::cout << "Неизвестная команда! Пожалуйста, попробуйте еще раз..." << std::endl;
            std::cout << "Играть снова? [д/н]: ";
            getline(std::cin, playAgain);      
        }

        if(playAgain == "n")
            playing = false;
    }

    return 0;
}