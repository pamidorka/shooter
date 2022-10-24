#include "ToggleButton.hpp"

ToggleButton::ToggleButton(
        float _x,
        float _y,
        float _width,
        float _height,
        const sf::Font* _font,
        const std::string& _text_enabled,
        const std::string& _text_disabled,
        unsigned int _text_size,
        const ButtonColorSet& _color_enabled,
        const ButtonColorSet& _color_disabled,
        bool _is_enabled)
    : Button(
            _x,
            _y,
            _width,
            _height,
            _font,
            _text_disabled,
            _text_size,
            _color_disabled),
      is_enabled_(_is_enabled),
      text_enabled_(_text_enabled),
      text_disabled_(_text_disabled),
      color_enabled_(_color_enabled),
      color_disabled_(_color_disabled)
{
    UpdateTextAndColors();
}

ToggleButton::~ToggleButton()
{
}

void ToggleButton::UpdateTextAndColors()
{
    SetText(is_enabled_ ? text_enabled_ : text_disabled_);
    SetColorSet(is_enabled_ ? color_enabled_ : color_disabled_);
    RefreshButtonColor();
}

void ToggleButton::Toggle(bool _is_enabled)
{
    is_enabled_ = _is_enabled;
    UpdateTextAndColors();
}

bool ToggleButton::IsEnabled() const
{
    return is_enabled_;
}

const std::string& ToggleButton::GetTextEnabledString() const
{
    return text_enabled_;
}
const std::string& ToggleButton::GetTextDisabledString() const
{
    return text_disabled_;
}
const ButtonColorSet& ToggleButton::GetButtonColorEnabledSet() const
{
    return color_enabled_;
}
const ButtonColorSet& ToggleButton::GetButtonColorDisabledSet() const
{
    return color_disabled_;
}

bool ToggleButton::Update(const sf::Vector2f _mouse_pos, bool _mouse_pressed)
{
    if (Button::Update(_mouse_pos, _mouse_pressed)) {
        Toggle(!is_enabled_);
        return true;
    } else
        return false;
}