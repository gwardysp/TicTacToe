#include "TicTac.h"
#include <gtkmm-4.0/gtkmm/application.h>

int main (int argc, char *argv[]) 
{
  auto app = Gtk::Application::create("com.gwardys.tic");
  
  return app->make_window_and_run<TicTac>(argc, argv);
}
