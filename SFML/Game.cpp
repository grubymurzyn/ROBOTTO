#include "Game.h"

Game::Game(void)
{
	state = END;
	if (!font.loadFromFile("data/Digital_tech.otf"))
	{

		return;
	}
	window.create(VideoMode(1280, 720), "Robotto", Style::Close);
	View camera(Vector2f(640, 360), Vector2f(1280, 720));
	window.setView(camera);
	state = GAME_OVER;
}


Game::~Game()
{
}
void Game::runGame()
{
	while (state != END)
	{
		switch (state)
		{
		case GameState::MENU:
			menu();
			break;
		case GameState::GAME:
			single();
			break;
		case GameState::HIGHSCORES:
			highScores();
			break;
		case GameState::GAME_OVER:
			endScreen();
			break;
		}
	}
}
void Game::menu()
{	
	Text title("Robotto", font, 80);
	title.setStyle(Text::Italic);
	title.setColor(Color::Black);
	title.setPosition(1280 / 2 - title.getGlobalBounds().width / 2, 20);

	const int ile = 3;

	Text tekst[ile];

	string str[] = { "Play","Highscores", "Exit" };
	for (int i = 0; i<ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(65);

		tekst[i].setString(str[i]);
		tekst[i].setPosition(1280 / 2 - tekst[i].getGlobalBounds().width / 2, 250 + i * 120);
	}

	while (state == MENU)
	{
		Vector2f mouse(Mouse::getPosition(window));
		Event event;

		while (window.pollEvent(event))
		{
			//Wciœniêcie ESC lub przycisk X
			if (event.type == Event::Closed || event.type == Event::KeyPressed &&
				event.key.code == Keyboard::Escape)
				state = END;

			//klikniêcie PLAY
			else if (tekst[0].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = GAME;
			}
			else if (tekst[1].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = HIGHSCORES;
			}
			//klikniêcie EXIT
			else if (tekst[2].getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				state = END;
			}
		}
		for (int i = 0; i < ile; i++){
			if (tekst[i].getGlobalBounds().contains(mouse))
				tekst[i].setColor(Color::White);
			else tekst[i].setColor(Color::Black);

			window.clear(Color(181, 181, 181));

			window.draw(title);
			for (int i = 0; i < ile; i++){
				window.draw(tekst[i]);
			}
			window.display();
		}
	}
}
void Game::single()
{
	Engine engine(window);
	score = engine.runEngine(window);
	state = GAME_OVER;
}

void Game::endScreen()
{	

	View camera(Vector2f(640, 360), Vector2f(1280, 720));
	window.setView(camera);

	Text title("KONIEC GRY", font, 100);
	title.setColor(Color::Black);
	title.setPosition(1280 / 2 - title.getGlobalBounds().width / 2, 30);

	Text button("PRZEJDZ DO TABELI", font, 80);
	button.setPosition(1280 / 2 - button.getGlobalBounds().width / 2, 500);

	const int ile = 3;

	Text tekst[ile];
	Text displayedName;
	displayedName.setFont(font);
	displayedName.setCharacterSize(80);
	displayedName.setColor(Color::Black);


	string name;
	ostringstream ss;
	ss << score;
	string wynik = ss.str();
	string str[] = { "TWOJ WYNIK", wynik , "WPISZ SWOJ NICK" };
	for (int i = 0; i<ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(62);
		tekst[i].setColor(Color::Black);
		tekst[i].setString(str[i]);
		tekst[i].setPosition(1280 / 2 - tekst[i].getGlobalBounds().width / 2, 200 + i * 60);
	}

	while (state == GAME_OVER)
	{
		Vector2f mouse(Mouse::getPosition(window));
		Event event;

		while (window.pollEvent(event))
		{
			//Wciœniêcie ESC lub przycisk X
			if (event.type == sf::Event::TextEntered)
			{
				// Handle ASCII characters only
				if (event.text.unicode < 128 && event.text.unicode != 8)
				{	
					name.push_back(event.text.unicode);
					cout << name << endl;
					displayedName.setString(name);
				}
				else if (event.text.unicode==8 && name.length() >0) {
					name.pop_back();
					cout << name << endl;
					displayedName.setString(name);
				}
			}else if (event.type == Event::Closed || event.type == Event::KeyPressed &&
				event.key.code == Keyboard::Escape)
				state = END;

			else if (button.getGlobalBounds().contains(mouse) &&
				event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
			{
				Score fullScore;
				fullScore.Add(name, score);
				HighScores highscores;
				highscores.Add(fullScore);
				highscores.Save();
				state = HIGHSCORES;
			}
		}
			if (button.getGlobalBounds().contains(mouse))
				button.setColor(Color::White);
			else button.setColor(Color::Black);

			displayedName.setPosition(1280 / 2 - displayedName.getGlobalBounds().width / 2, 400);
			window.clear(Color(181,181,181));
			window.draw(displayedName);
			window.draw(button);
			window.draw(title);
			for (int i = 0; i < ile; i++){
				window.draw(tekst[i]);
			}
			window.display();
		
	}
}

void Game::highScores(){
	View camera(Vector2f(640, 360), Vector2f(1280, 720));
	Vector2f mouse(Mouse::getPosition(window));
	window.setView(camera);
	Event event;

	Text title("HIGHSCORES", font, 80);
	Text button("PRZEJDZ DO MENU", font, 62);
	HighScores highscores;
	//TUTAJ DOKONCZYC
	title.setColor(Color::Black);
	button.setColor(Color::Black);
	button.setPosition(1280 / 2 - button.getGlobalBounds().width / 2, 500);
	title.setPosition(1280 / 2 - title.getGlobalBounds().width / 2, 70);

	while (window.pollEvent(event))
	{
		//Wciœniêcie ESC lub przycisk X
		if (event.type == Event::Closed || event.type == Event::KeyPressed &&
			event.key.code == Keyboard::Escape)
			state = END;

		else if (button.getGlobalBounds().contains(mouse) &&
			event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
		{
			state = MENU;
		}
	}

	if (button.getGlobalBounds().contains(mouse))
		button.setColor(Color::White);
	else button.setColor(Color::Black);

	window.clear(Color(181, 181, 181));
	window.draw(button);
	window.draw(title);

	window.display();
}
