#include <ncurses.h>

using namespace std;

int main()
{
  initscr();
  noecho();

  int height, width, start_y, start_x;
  height = 5;
  width = 30;
  start_y = start_x = 10;

  WINDOW *popup = newwin(height, width, start_y, start_x);
  box(popup, 0, 0);

  mvwprintw(popup, 1, 2, "Deseas guardar partida?");
  mvwprintw(popup, 2, 2, "SI(1)");
  mvwprintw(popup, 3, 2, "NO(2)");
  wrefresh(popup);

  int ch;
  while (ch = wgetch(popup))
  {
    switch (ch)
    {
    case 49:
      wattron(popup, A_STANDOUT);
      mvwprintw(popup, 2, 2, "SI(1)");
      wattroff(popup, A_STANDOUT);
      mvwprintw(popup, 3, 2, "NO(2)");
      wrefresh(popup);
      break;
    case 50:
      wattron(popup, A_STANDOUT);
      mvwprintw(popup, 3, 2, "NO(2)");
      wattroff(popup, A_STANDOUT);
      mvwprintw(popup, 2, 2, "SI(1)");
      wrefresh(popup);
      break;
    default:
      mvwprintw(popup, 2, 2, "SI(1)");
      mvwprintw(popup, 3, 2, "NO(2)");
      break;
    }
  }

  wgetch(popup);
  endwin();

  return 0;
}