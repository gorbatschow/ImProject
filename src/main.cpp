#include "ImApplication.h"
#include <imw.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class ProjectApp : public ImApplication {
  struct Ui {
    Imw::Button btn{"Push"};
    Imw::CheckBox flag{"Check"};
    Imw::ComboBox<bool> combo{"Select"};
    Imw::ValueLabel<int> label{"Display One %d"};
    Imw::Slider<float> slider{"Slide"};
    Imw::SpinBox<int> spin{"Spin"};

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
