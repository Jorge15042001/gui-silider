#pragma once

#include "drop_down_option.h"

#include <gtkmm.h>

class CamMenu : public Gtk::Box {
public:
  CamMenu();
  ~CamMenu() override;

protected:
  // Signal handlers
  void on_checkbutton_toggled();
  void on_dropdown_position();
  void on_adjustment1_value_changed();
  void on_adjustment2_value_changed();

  // Child widgets:
  DropDownOption<int> m_cam_id;

  Gtk::Box m_main_container;
  Gtk::Box m_VBox2;

  Gtk::Box m_HBox_DropDown;
  Gtk::Box m_HBox_Digits;

  Glib::RefPtr<Gtk::Adjustment> m_adjustment_digits;

  Gtk::Scale m_Scale_Digits;

  Gtk::Separator m_Separator;

  Gtk::CheckButton m_CheckButton;

  Gtk::DropDown m_DropDown_Position;


};
