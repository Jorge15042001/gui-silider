#pragma once

#include <gtkmm.h>
#include <gtkmm/box.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/frame.h>

class FrameHolder : public Gtk::Box{
public:
  FrameHolder();
  virtual ~FrameHolder();
private:
  Gtk::Frame m_container;
  Gtk::DrawingArea m_frame;
};
