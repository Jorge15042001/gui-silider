#include "options_menu.h"

Menu::~Menu() {}

Menu::Menu() {
  // this->set_size_request(200,-1);

  auto label = Gtk::make_managed<Gtk::Label>("cool button");
  // label->set_expand(true);
  this->set_margin(10);
  this->set_expand(true);

  this->append_page(m_slider_menu,"Slider");
  this->append_page(m_cam_menu,"Camera");
}
