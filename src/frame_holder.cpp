#include "frame_holder.h"
#include <gtkmm/enums.h>

FrameHolder::FrameHolder(){
  m_container.set_label("Camera live view");
  m_container.set_label_align(Gtk::Align::START);
  m_container.set_child(m_frame);
  m_container.set_expand(true);
  m_container.set_margin(10);

  m_frame.set_expand(true);
  
  this->append(m_container);

}
FrameHolder::~FrameHolder(){}
