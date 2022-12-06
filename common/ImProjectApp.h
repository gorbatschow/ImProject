#pragma once
class GLFWwindow;

class ImProjectApp {
public:
  ImProjectApp();
  virtual ~ImProjectApp();

  void run();
  void quit();

protected:
  virtual void beforeRun() {}
  virtual void paint(int w, int h);

private:
  GLFWwindow *m_glwin = nullptr;

  int _frameBufferW{};
  int _frameBufferH{};
};
