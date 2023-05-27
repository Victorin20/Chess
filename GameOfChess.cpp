#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace sf;
using namespace std;

#pragma warning(disable: 4244)
#pragma warning(disable: 6292)
#pragma warning(disable: 4018)
#pragma warning(disable: 6289)

void draw(RenderWindow& window)
{
    bool white = true;

    RectangleShape board(Vector2f(100, 100));

    for (int k(0); k < 8; k++)
    {

        for (int f(0); f < 8; f++)
        {
            if (white)board.setFillColor(Color::White);
            else board.setFillColor(Color(0, 0, 255));
            board.setPosition(k * 100, f * 100);
            window.draw(board);
            white = !white;
        }
        white = !white;
    }

}

int makeMoveQueen(int board[], const int size, const string& colorRound)
{
    vector<int> positions;
    int searchPiece = 0;

    if (colorRound == "white")searchPiece = 1;
    if (colorRound == "black")searchPiece = -1;

    for (int k(0); k < size; k++)
    {
        if (board[k] == searchPiece)
        {
            board[k] = 0;
            //up move diagonal right 
            for (int f(k); f > 0; f -= 7)
            {
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }

                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

            //down move diagonal left
            for (int f(k); f > 0; f += 7)
            {
                if (f >= 63)break;
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }

                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

            //down move diagonal right
            for (int f(k); f < 63; f += 9)
            {
                if (f >= 63)break;
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }

                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

            //up move diagonal left
            for (int f(k); f > 0; f -= 9)
            {
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }

                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

            //up move 
            for (int f(k); f > 0; f -= 8)
            {
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }

                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

            //down move
            for (int f(k); f < size; f += 8)
            {
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }
                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

            // ------> movement
            for (int f(k); f % 8 < 7; f++)
            {
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }
                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }

                if (f % 8 == 6 && board[f - 1] >= 0)
                {
                    positions.push_back(f + 1);
                    break;
                }
            }

            // <--- movement
            for (int f(k); f % 8 < 7; f--)
            {
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }
                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }

                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }

                if (f % 8 == 6 && board[f - 1] >= 0)
                {
                    positions.push_back(f - 1);
                    break;
                }

            }


        }
    }
    if (positions.size() > 0)return positions[rand() % positions.size()];
    else return 0;
}

int makeMoveBishop(int board[], const int size, const string& colorRound)
{
    vector<int> positions;
    int searchPiece = 0;

    if (colorRound == "white")searchPiece = 2;
    if (colorRound == "black")searchPiece = -2;

    for (int k(0); k < size; k++)
    {
        if (board[k] == searchPiece)
        {
            board[k] = 0;
            //up move diagonal right 
            for (int f(k); f > 0; f -= 7)
            {
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }

                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

            //down move diagonal left
            for (int f(k); f > 0; f += 7)
            {
                if (f >= 63)break;
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }

                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

            //down move diagonal right
            for (int f(k); f < 63; f += 9)
            {
                if (f >= 63)break;
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }

                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

            //up move diagonal left
            for (int f(k); f > 0; f -= 9)
            {
                if (board[f] == 0)
                {
                    positions.push_back(f);
                }

                if (board[f] < 0 && colorRound == "white")
                {
                    positions.push_back(f);
                    break;
                }
                else if (board[f] > 0 && colorRound == "black")
                {
                    positions.push_back(f);
                    break;
                }
            }

        }
    }

    if (positions.size() > 0)return positions[rand() % positions.size()];
    else return 0;
}

int makeMoveKnight(int board[], const int size, const string& colorRound)
{
    vector<int> positions;
    int searchPiece = 0;

    if (colorRound == "white")searchPiece = 3;
    if (colorRound == "black")searchPiece = -3;

    for (int k(0); k < size; k++)
    {
        if (board[k] == searchPiece)
        {
            board[k] = 0;

            if (k + 6 < 64)positions.push_back(k + 6);
            if (k + 10 < 64)positions.push_back(k + 10);
            if (k + 15 < 64)positions.push_back(k + 15);
            if (k + 17 < 64)positions.push_back(k + 17);
            if (k - 6 >= 0)positions.push_back(k - 6);
            if (k - 10 >= 0)positions.push_back(k - 10);
            if (k - 15 >= 0)positions.push_back(k - 15);
            if (k - 17 >= 0)positions.push_back(k - 17);

        }
    }

    return positions[rand() % positions.size()];
}


int checkWinner(int board[], const int size)
{
    vector<int> whiteWhinner;
    vector<int> blackWhinner;

    for (int k(0); k < size; k++)
    {
        if (board[k] < 0)blackWhinner.push_back(1);
        if (board[k] > 0)whiteWhinner.push_back(1);
    }
    if (blackWhinner.size() == 0)return 1;
    if (whiteWhinner.size() == 0)return -1;
    return 0;
}

int main()
{
    const int width(800), heigth(850);
    const int square(100);

    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(width, heigth), "Chess");
#pragma region initialisation   
    Texture boardTexture, blackBishopTexture, whiteBishopTexture, blackKnightTexture, whiteKnightTexture,
        whiteQueenTexture, blackQueenTexture;

    boardTexture.loadFromFile("images/board.png");
    blackBishopTexture.loadFromFile("images/bishop_b.png");
    whiteBishopTexture.loadFromFile("images/bishop_w.png");
    blackKnightTexture.loadFromFile("images/knight_b.png");
    whiteKnightTexture.loadFromFile("images/knight_w.png");
    blackQueenTexture.loadFromFile("images/queen_b.png");
    whiteQueenTexture.loadFromFile("images/queen_w.png");

    Sprite whiteBishop(whiteBishopTexture), blackBishop(blackBishopTexture);
    Sprite whiteKnight(whiteKnightTexture), blackKnight(blackKnightTexture);
    Sprite whiteQueen(whiteQueenTexture), blackQueen(blackQueenTexture);


    RectangleShape startButton(Vector2f(400, 50));
    startButton.setFillColor(Color::Green);
    startButton.setPosition(0, 800);

    RectangleShape pauseButton(Vector2f(400, 50));
    pauseButton.setFillColor(Color::Yellow);
    pauseButton.setPosition(400, 800);


    Font font;
    font.loadFromFile("sprites/ARLRDBD.TTF");

    Text startText, pauseText, winnerText;
    startText.setFont(font);
    pauseText.setFont(font);
    winnerText.setFont(font);

    startText.setCharacterSize(30);
    pauseText.setCharacterSize(30);
    winnerText.setCharacterSize(100);

    startText.setFillColor(Color::Black);
    pauseText.setFillColor(Color::Black);
    winnerText.setFillColor(Color::Black);

    startText.setPosition(100, 800);
    pauseText.setPosition(500, 800);
    winnerText.setPosition(200, heigth / 2);


    startText.setString("Start");
    pauseText.setString("Pause");


#pragma endregion initialisation


    auto board = new int[64];

    for (int k(0); k < 64; k++)
    {
        board[k] = 0;
    }

    board[0] = 1;
    board[1] = 2;
    board[2] = 3;
    board[56] = -1;
    board[57] = -2;
    board[58] = -3;


    bool startGame = false;
    bool makeMove = false;
    bool gameOver = false;

    Vector2f randomVector;

    Clock clock;
    float timer(0), delay(0.1f);

    vector<int> table;

    string roundColor = "white";

    bool once = false;
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)window.close();
        }
        float time = clock.getElapsedTime().asSeconds();
        timer += time;
        clock.restart();

        int randomPiece = rand() % 6 + 1;

        bool WhitequeenEliminated = true;
        bool WhiteknightEliminated = true;
        bool WhitebishopEliminated = true;
        bool BlackqueenEliminated = true;
        bool BlackknightEliminated = true;
        bool BlackbishopEliminated = true;

        for (int k(0); k < 64; k++)
        {
            if (board[k] == 1)WhitequeenEliminated = false;
            if (board[k] == 2)WhitebishopEliminated = false;
            if (board[k] == 3)WhiteknightEliminated = false;
            if (board[k] == -1)BlackqueenEliminated = false;
            if (board[k] == -2)BlackbishopEliminated = false;
            if (board[k] == -3)BlackknightEliminated = false;

        }


        if (Mouse::isButtonPressed(Mouse::Left) && startButton.getGlobalBounds().contains(pos.x, pos.y))
        {
            startGame = true;
        }

        if (Mouse::isButtonPressed(Mouse::Left) && pauseButton.getGlobalBounds().contains(pos.x, pos.y))
        {
            startGame = false;
        }

        int winner = checkWinner(board, 64);
        if (winner > 0) {
            winnerText.setString("white wins !");
            gameOver = true;
        }
        else if (winner < 0) {
            winnerText.setString("black wins !");
            gameOver = true;
        }

        if (startGame && !gameOver)
        {
            if (timer > delay)
            {
                if (roundColor == "white" && !WhitequeenEliminated && randomPiece == 1)
                {
                    board[makeMoveQueen(board, 64, "white")] = 1;
                }

                if (roundColor == "white" && !WhitebishopEliminated && randomPiece == 2)
                {
                    board[makeMoveBishop(board, 64, "white")] = 2;
                }

                if (roundColor == "white" && !WhiteknightEliminated && randomPiece == 3)
                {
                    board[makeMoveKnight(board, 64, "white")] = 3;
                }
                if (roundColor == "black" && !BlackqueenEliminated && randomPiece == 4)
                {
                    board[makeMoveQueen(board, 64, "black")] = -1;
                }
                if (roundColor == "black" && !BlackbishopEliminated && randomPiece == 5)
                {
                    board[makeMoveBishop(board, 64, "black")] = -2;
                }
                if (roundColor == "black" && !BlackknightEliminated && randomPiece == 6)
                {
                    board[makeMoveKnight(board, 64, "black")] = -3;

                }

                if (roundColor == "white")roundColor = "black";
                else roundColor = "white";

                timer = 0;
            }

        }

        window.clear();

        draw(window);

        for (int k(0); k < 64; k++)
        {
            switch (board[k])
            {
            case 1:
                window.draw(whiteQueen);
                whiteQueen.setPosition(k % 8 * 100, k / 8 * 100);
                break;
            case 2:
                window.draw(whiteBishop);
                whiteBishop.setPosition(k % 8 * 100, k / 8 * 100);
                break;
            case 3:
                window.draw(whiteKnight);
                whiteKnight.setPosition(k % 8 * 100, k / 8 * 100);
                break;
            case -1:
                window.draw(blackQueen);
                blackQueen.setPosition(k % 8 * 100, k / 8 * 100);
                break;
            case -2:
                window.draw(blackBishop);
                blackBishop.setPosition(k % 8 * 100, k / 8 * 100);
                break;
            case -3:
                window.draw(blackKnight);
                blackKnight.setPosition(k % 8 * 100, k / 8 * 100);
                break;


            }
        }

        window.draw(startButton);
        window.draw(pauseButton);
        window.draw(startText);
        window.draw(pauseText);
        window.draw(winnerText);


        window.display();
    }

}
