#include <gtkmm.h>
#include <iostream>
#include <gtkmm/button.h>
class MyWindow : public Gtk::Window {
public:
  MyWindow();
  protected:
    Gtk::Button m_button;
    void on_button_clicked(){
        std::cout << "The Button was clicked." << std::endl;
    }
};

MyWindow::MyWindow() {
   auto pmap = Gtk::make_managed<Gtk::Image>("info.xpm");
  auto label = Gtk::make_managed<Gtk::Label>("cool button");
  label->set_expand(true);

  //Put them in a Box:
  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  hbox->append(*pmap);
  hbox->append(*label);

  //And put that Box in the button:
  m_button.set_child(*hbox);

  set_title("Pixmap'd buttons!");

  m_button.signal_clicked().connect( sigc::mem_fun(*this,
              &MyWindow::on_button_clicked) );

  m_button.set_margin(10);
  set_child(m_button);
  
}

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("org.gtkmm.example");
  return app->make_window_and_run<MyWindow>(argc, argv);
}
