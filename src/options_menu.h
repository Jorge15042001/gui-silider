#pragma once

#include <gtkmm.h>
#include <gtkmm/label.h>
#include <gtkmm/notebook.h>

#include "camera_menu.h"

class Menu: public Gtk::Notebook
{
public:
  Menu();
  virtual ~Menu();
private:
  CamMenu m_cam_menu;
  CamMenu m_slider_menu;
  
};
