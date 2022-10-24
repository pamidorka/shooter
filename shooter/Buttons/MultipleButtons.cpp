#include "MultipleButtons.hpp"

MultipleButtons::MultipleButtons() : active_button_id_(-1)
{
}

void MultipleButtons::AddButton(ToggleButton& _button)
{
    buttons_.push_back(_button);
}

const ToggleButton& MultipleButtons::GetButton(size_t _id) const
{
    if (_id >= buttons_.size()) {
        throw std::out_of_range("Index is out of range");
    }

    return buttons_[_id];
}

void MultipleButtons::SetActiveButtonId(int _id)
{
    active_button_id_ = _id;

    for (size_t i = 0; i < buttons_.size(); i++) {
        buttons_[i].Toggle(i == (size_t)_id);
    }
}

int MultipleButtons::GetActiveButtonId() const
{
    return active_button_id_;
}

bool MultipleButtons::Update(sf::Vector2f _mouse_pos, bool _mouse_pressed)
{
    bool result = false;
    for (size_t i = 0; i < buttons_.size(); i++) {
        if (buttons_[i].Update(_mouse_pos, _mouse_pressed)) {
            active_button_id_ = i;
            result = true;
        }
    }

    SetActiveButtonId(active_button_id_);
    return result;
}

void MultipleButtons::Render(sf::RenderTarget* _target)
{
    for (size_t i = 0; i < buttons_.size(); i++) {
        buttons_[i].Render(_target);
    }
}

size_t MultipleButtons::ButtonCount() const
{
    return buttons_.size();
}