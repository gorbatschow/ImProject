#include <imapp.h>
#include <imwrap.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class ProjectApp : public ImApp::MainWindow {
  struct Ui {
    ImWrap::Button btn{"Push"};
    ImWrap::CheckBox flag{"Check"};
    ImWrap::ComboBox<bool> combo{"Select"};
    ImWrap::ValueLabel<int> label{"Display One %d"};
    ImWrap::Slider<float> slider{"Slide"};
    ImWrap::SpinBox<int> spin{"Spin"};

    Ui() {
      combo.setValueList({{true, "Yes"}, {false, "No"}});
      label.setValue(1);
    }
  };
  Ui ui;

  void paint() override {
    ImGui::Begin("Widget");
    ui.btn.paint();
    ui.flag.paint();
    ui.combo.paint();
    ui.label.paint();
    ui.slider.paint();
    ui.spin.paint();
    ImGui::End();
  }
};

int main(int argc, char **argv) {
  ProjectApp app;
  app.run();

  return 0;
}
