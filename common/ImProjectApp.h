#pragma once
#include <imgui.h>
#include <string>
class GLFWwindow;

class ImProjectApp {
public:
  ImProjectApp(const std::string &title = "Dear ImGui GLFW+OpenGL3");
  virtual ~ImProjectApp();

  int run();

protected:
  virtual void beforeLoop() {}
  virtual void paint();
  virtual void beforeQuit() {}

private:
  std::string _windowTitle{};
  GLFWwindow *_glfwWindow{nullptr};
  int _displayW{}, _displayH{};
  ImVec4 _clearColor{0.45f, 0.55f, 0.60f, 1.00f};

  int init();
  void loop();
  void quit();

  static void onGlfwError(int error, const char *description) noexcept;
};
