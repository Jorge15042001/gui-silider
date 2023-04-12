#pragma once
#include <functional>
#include <glibmm/ustring.h>
#include <gtkmm.h>
#include <gtkmm/dropdown.h>
#include <gtkmm/enums.h>
#include <gtkmm/label.h>
#include <optional>
#include <string>
#include <vector>

template <typename T> class DropDownOption : public Gtk::Box {
  Gtk::Label m_label;
  Gtk::DropDown m_dropDown;

  std::vector<T> m_options;
  std::function<void()> callback;

public:
  DropDownOption(const char *label, const std::vector<T> &opts = {})
      : Gtk::Box(Gtk::Orientation::HORIZONTAL, 10), m_label(label, 0) {
    // m_label.set_margin(3);

    m_dropDown.set_expand(true);
    setOptions(opts);

    this->append(m_label);
    this->append(m_dropDown);
    this->set_expand(true);
  }
  ~DropDownOption() override {}

  // void changeCallback();
  void setOptions(const std::vector<T> &options) {
    this->m_options = options;
    auto string_options = Gtk::StringList::create({});
    for (const auto &elemnt : options) {
      string_options->append(std::to_string(elemnt));
    }
    m_dropDown.set_model(string_options);

    m_dropDown.set_selected(0); // Top
  }

  std::optional<std::reference_wrapper<T>> getSelectedElement() {

    auto selected = m_dropDown.get_selected();
    if (selected == GTK_INVALID_LIST_POSITION)
      return std::nullopt;
    return std::optional<std::reference_wrapper<T>>{this->m_options[selected]};
  }

  void setCallback(std::function<void()> func) {
    this->callback = func;
    m_dropDown.property_selected().signal_changed().connect(this->callback);
  }
};
