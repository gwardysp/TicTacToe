#include "TicTac.h"
#include "gtkmm/button.h"
#include "gtkmm/messagedialog.h"
#include "sigc++/adaptors/bind.h"
#include "sigc++/adaptors/hide.h"
#include "sigc++/functors/mem_fun.h"
#include <cstddef>
#include<gtkmm.h>
TicTac::TicTac()
{
  set_default_size(300,300);
  set_title("Tic Tac Toe");

  for(size_t i=0; i<3; i++)
  {
    for(size_t j=0; j<3; j++)
    {
      buttons[i][j].set_size_request(100,100);
      buttons[i][j].signal_clicked().connect(sigc::bind(
        sigc::mem_fun(*this,&TicTac::onButtonClicked), i, j));
      m_grid.attach(buttons[i][j], i, j);
    }

    
  }

  set_child(m_grid);

  
}


TicTac::~TicTac()
{

}
  
void TicTac::onButtonClicked(int row, int col)
{
  if(!gameEnd && board[row][col] == ' ')
  {
    buttons[row][col].set_label(player == 'X' ? "X":"O");
    board[row][col] = player;

    if(checkWin(player))
    { 
      dialog.reset(new Gtk::MessageDialog(*this, "FFF"));

       
      dialog->set_hide_on_close(true);
      dialog->set_modal(true);
      dialog->signal_response().connect(sigc::hide(
        sigc::mem_fun(*this, &Gtk::Widget::hide)));


      dialog->show();
       
      gameEnd = true;
    }

    if(checkDraw(player))
    {
      dialog.reset(new Gtk::MessageDialog(*this, "FFF"));
      
      dialog->set_hide_on_close(true);
      dialog->set_modal(true);
      dialog->signal_response().connect(sigc::hide(
        sigc::mem_fun(*this, &Gtk::Widget::hide)));      dialog->show();
      gameEnd = true;
    }

    player = (player=='X') ? 'O':'X';
  }

  




}


bool TicTac::checkWin(char player)
{
    for(size_t i=0; i<3; i++)
    {
      if((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
         (board[0][i] == player && board[1][i] == player && board[2][i] == player))
      {
        return true;
      }

      
    }

    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
       (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
       return true;
    }
   return false;
}



bool TicTac::checkDraw(char player)
{
  for(size_t i = 0; i<3; i++)
  {
    for(size_t j = 0; j<3; j++)
    {
      if(board[i][j] == ' '){return false;}
    }
  }

  return true;

}



