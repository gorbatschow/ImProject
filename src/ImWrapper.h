#pragma once
#include <imgui.h>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

namespace ImWrap {

// BasicElement
// -----------------------------------------------------------------------------
    class BasicElement {
    public:
        BasicElement() { }
        virtual ~BasicElement() { }

        virtual void paint() {
            ImGui::PushID(this);
            if (!std::isnan(_width))
                ImGui::SetNextItemWidth(_width);
            paintElement();
            ImGui::PopID();
        }

        virtual bool handle() { return false; }
        inline void setWidth(const float& w) { _width = w; }

    protected:
        virtual void paintElement() { }

        float _width{std::numeric_limits<float>::quiet_NaN()};
        std::string _label{"##"};
    };

// ValueElement
// -----------------------------------------------------------------------------
    template <class T>
    class ValueElement : public BasicElement {
    public:
        ValueElement() { }
        virtual ~ValueElement() override { }
        virtual void paintElement() override { }

        virtual void setCurrValue(const T& value) {
            _currValue = value;
        }

        virtual bool handle() const {
            const auto changed = _changed;
            _changed = false;
            return changed;
        }

        inline const T& currValue() const { return _currValue; }

    protected:
        T _currValue;
        mutable bool _changed{false};
    };

// Label
// -----------------------------------------------------------------------------
    class Label : public BasicElement {
    public:
        Label(const std::string& label) {
            _label = label;
        }

        virtual ~Label() override { }

        virtual void paintElement() override {
            ImGui::Text("%s", _label.c_str());
        }
    };

// Button
// -----------------------------------------------------------------------------
    class Button : public BasicElement {
    public:
        Button(const std::string& label) {
            _label = label;
        }

        virtual ~Button() override { }

        virtual void paintElement() override {
            _triggered = ImGui::Button(_label.c_str());
        }

        virtual bool handle() override {
            const bool trig = _triggered;
            _triggered = false;
            return trig;
        }

    protected:
        bool _triggered{false};
    };

// Combo
// -----------------------------------------------------------------------------
    template <class T>
    class Combo : public ValueElement<T> {
    public:
        Combo() { }

        Combo(const std::string& label) {
            ValueElement<T>::_label = label;
        }

        virtual ~Combo() override {}

        virtual void paintElement() override {
            if (ImGui::BeginCombo(ValueElement<T>::_label.c_str(),
                                  _valueList[_currIndex].second.c_str())) {
                for (size_t i = 0; i != _valueList.size(); ++i) {
                    if (ImGui::Selectable(_valueList[i].second.c_str(),
                                          i == _currIndex)) {
                        _currIndex = i;
                        ValueElement<T>::_currValue = _valueList[i].first;
                        ValueElement<T>::_changed = true;
                    }
                }
                ImGui::EndCombo();
            }
        }

        virtual void setCurrValue(const T& value) override {
            for (size_t i = 0; i != _valueList.size(); ++i) {
                if (_valueList[i].first == value) {
                    _currIndex = i;
                    ValueElement<T>::_currValue = value;
                    break;
                }
            }
        }

    protected:
        std::vector<std::pair<T, std::string> > _valueList;
        size_t _currIndex{0};
    };


// CheckBox
// -----------------------------------------------------------------------------
    class CheckBox : public ValueElement<bool> {
    public:
        CheckBox() {
            _currValue = false;
        }

        CheckBox(const std::string& label) {
            _label = label;
            _currValue = false;
        }

        virtual ~CheckBox() override { }

        virtual void paintElement() override {
            _changed = ImGui::Checkbox(_label.c_str(), &_currValue);
        }
    };

// SpinBox
// -----------------------------------------------------------------------------
    template <class T>
    class SpinBox : public ValueElement<T> {
    public:
        SpinBox() {
            ValueElement<T>::_currValue = {};
        }

        SpinBox(const std::string &label) {
            ValueElement<T>::_currValue = {};
            ValueElement<T>::_label = label;
        }

        virtual ~SpinBox() override { }

        void paintElement() override {
            paintSpinBox();
            ValueElement<T>::_currValue =
                    ValueElement<T>::_currValue > _limits.first ?
                        ValueElement<T>::_currValue : _limits.first;
            ValueElement<T>::_currValue =
                    ValueElement<T>::_currValue < _limits.second ?
                        ValueElement<T>::_currValue : _limits.second;
        }

        inline void setValueLimits(const std::pair<T,T>& limits) {
            _limits = limits;
        }

    private:
        std::pair<T,T> _limits{std::numeric_limits<T>::min(),
                               std::numeric_limits<T>::max()};

        void paintSpinBox() {}
    };

    template<>
    inline void SpinBox<int>::paintSpinBox() {
        _changed = ImGui::InputInt(_label.c_str(), &_currValue);
    }
}

