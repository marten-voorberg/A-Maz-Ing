const int FPS = 25;
const int Skip = 1000 / FPS;

  next_game_tick += SKIP_TICKS;
  sleep_time = next_game_tick - GetTickCount();
  if (sleep_time >= 0) {
    sf::sleep( sf::milliseconds(sleep_time) );
  } else {
    // Shit, we are running behind!
  }