#include <gtkmm.h>
#include <iostream>
#include <gtkmm/button.h>

#include "options_menu.h"
#include "frame_holder.h"



class MyWindow : public Gtk::Window {
public:
  MyWindow();

protected:
  Gtk::Box m_main_box;
  Menu m_menu;
  FrameHolder m_frame_holder;
    
};

MyWindow::MyWindow():
  m_main_box(Gtk::Orientation::HORIZONTAL,5)
{
  set_title("Slider Controller");

  

  m_main_box.append(m_menu);
  m_main_box.append(m_frame_holder);

  this->set_child(m_main_box);
  
}

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.example");
  return app->make_window_and_run<MyWindow>(argc, argv);
}
