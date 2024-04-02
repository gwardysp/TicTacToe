#ifndef TIC_TAC_H
#define TIC_TAC_H


#include "gtkmm/messagedialog.h"
#include "gtkmm/window.h"
#include<gtkmm.h>
class TicTac : public Gtk::Window
{
public:
  TicTac();
  ~TicTac() override;

protected:
  Gtk::Button buttons[3][3];
  Gtk::Grid m_grid;
  char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
  char player = 'X';
  bool gameEnd = false;
  bool checkWin(char player);
  bool checkDraw(char player);
  
  void onButtonClicked(int row,int col);
  
  
  std::unique_ptr<Gtk::MessageDialog> dialog;


};

#endif // !TIC_H

