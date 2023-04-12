#include "camera_menu.h"

#include <array>
#include <gtkmm/enums.h>
#include <iostream>

namespace
{
struct PositionTypeStruct
{
  Gtk::PositionType position;
  Glib::ustring text;
};

const std::array<PositionTypeStruct, 4> positionTypes =
{
  PositionTypeStruct{Gtk::PositionType::TOP,    "Top"},
  PositionTypeStruct{Gtk::PositionType::BOTTOM, "Bottom"},
  PositionTypeStruct{Gtk::PositionType::LEFT,   "Left"},
  PositionTypeStruct{Gtk::PositionType::RIGHT,  "Right"}
};

} // anonymous namespace

void callback1 (){std::cout<<"Hello there!"<<std::endl;}

CamMenu::CamMenu()
:
  m_main_container(Gtk::Orientation::VERTICAL, 0),
  m_VBox2(Gtk::Orientation::VERTICAL, 20),
  m_HBox_DropDown(Gtk::Orientation::HORIZONTAL, 10),
  m_HBox_Digits(Gtk::Orientation::HORIZONTAL, 10),

  // Value, lower, upper, step_increment, page_increment, page_size:
  // Note that the page_size value only makes a difference for
  // scrollbar widgets, and the highest value you'll get is actually
  // (upper - page_size).
  m_adjustment_digits( Gtk::Adjustment::create(1.0, 0.0, 5.0, 1.0, 2.0) ),

  m_Scale_Digits(m_adjustment_digits),

  // A checkbutton to control whether the value is displayed or not:
  m_CheckButton("Gain auto", 0),


  m_cam_id("Camera Id", {0,2,4})

{
  // set_title("range controls");
  // set_size_request(300, 350);


  append(m_main_container);
  m_main_container.append(m_VBox2);
  m_VBox2.set_expand(true);
  m_VBox2.set_valign(Gtk::Align::START);
  m_VBox2.set_margin(10);

  //cam id:
  m_cam_id.setOptions({1,2,3,4});
  m_cam_id.set_expand(true);
  m_cam_id.setCallback([this]{
      std::cout << this->m_cam_id.getSelectedElement()->get() <<std::endl;
      });
  m_VBox2.append(m_cam_id);

  //CheckButton:
  m_CheckButton.set_active();
  m_CheckButton.signal_toggled().connect( sigc::mem_fun(*this,
    &CamMenu::on_checkbutton_toggled) );
  m_VBox2.append(m_CheckButton);

  //Position DropDown:
  //Create the StringList:
  auto string_list = Gtk::StringList::create({});
  m_DropDown_Position.set_model(string_list);

  // Fill the DropDown's list model:
  for (const auto& positionType : positionTypes)
    string_list->append(positionType.text);

  m_VBox2.append(m_HBox_DropDown);
  m_HBox_DropDown.append(*Gtk::make_managed<Gtk::Label>("Scale Value Position:", 0));
  m_HBox_DropDown.append(m_DropDown_Position);
  m_DropDown_Position.property_selected().signal_changed().connect(
    sigc::mem_fun(*this, &CamMenu::on_dropdown_position));
  m_DropDown_Position.set_selected(0); // Top
  m_DropDown_Position.set_expand(true);

  //Digits:
  m_HBox_Digits.append(*Gtk::make_managed<Gtk::Label>("Scale Digits:", 0));
  m_Scale_Digits.set_digits(0);
  m_Scale_Digits.set_expand(true);
  m_adjustment_digits->signal_value_changed().connect(sigc::mem_fun(*this,
    &CamMenu::on_adjustment1_value_changed));
  m_HBox_Digits.append(m_Scale_Digits);

  //Page Size:
  m_VBox2.append(m_HBox_Digits);

}

CamMenu::~CamMenu()
{
}

void CamMenu::on_checkbutton_toggled()
{
}

void CamMenu::on_dropdown_position()
{
  const auto selected = m_DropDown_Position.get_selected();
  if (selected == GTK_INVALID_LIST_POSITION)
    return;

  const auto postype = positionTypes[selected].position;
}

void CamMenu::on_adjustment1_value_changed()
{
  const double val = m_adjustment_digits->get_value();
}

void CamMenu::on_adjustment2_value_changed()
{
  // Note that we don't have to emit the "changed" signal
  // because gtkmm does this for us.
}

