#include "ImProjectApp.h"
#include "ImWrapper.h"
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <chrono>
#include <imfonts.h>
#include <imgui.h>
#include <imgui_internal.h>
#include <implot.h>

// Based on Dear ImGui example "Dear ImGui: standalone example application for
// GLFW + OpenGL 3, using programmable pipeline"
// https://github.com/ocornut/imgui/blob/master/examples/example_glfw_opengl3/main.cpp

// See "Extremely Important Note" in README https://github.com/epezent/implot
// io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset' and handle
// ImDrawCmd::VtxOffset #define ImDrawIdx unsigned int

ImProjectApp::ImProjectApp(const std::string &title) : _windowTitle(title) {}
// -----------------------------------------------------------------------------
ImProjectApp::~ImProjectApp() {}
// -----------------------------------------------------------------------------
int ImProjectApp::run() {
  const auto initStatus = init();
  if (initStatus != 0)
    return initStatus;
  beforeLoop();
  loop();
  beforeQuit();
  quit();

  return 0;
}
// -----------------------------------------------------------------------------
void ImProjectApp::paint() {
  static auto helloLabel = ImWrap::Label("Hello World");
  ImGui::Begin("Welcome Window");
  helloLabel.paint();
  ImGui::End();
}
// -----------------------------------------------------------------------------
int ImProjectApp::init() {
  // Setup window
  glfwSetErrorCallback(onGlfwError);
  if (glfwInit() == 0) {
    return 1;
  }

// Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
  // GL ES 2.0 + GLSL 100
  const char *glsl_version = "#version 100";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
  // GL 3.2 + GLSL 150
  const char *glsl_version = "#version 150";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // Required on Mac
#else
  // GL 3.0 + GLSL 130
  const char *glsl_version = "#version 130";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+
  // only glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // 3.0+ only
#endif

  // Create window with graphics context
  _glfwWindow = glfwCreateWindow(1280, 720, _windowTitle.c_str(), NULL, NULL);
  if (_glfwWindow == NULL)
    return 1;
  glfwMakeContextCurrent(_glfwWindow);
  glfwSwapInterval(1); // Enable vsync

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  // Backend
  io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;
  // Docking
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  // Viewport
  // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
  // Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  // Gamepad
  // Keyboard Controls io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();
  // ImGui::StyleColorsLight();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(_glfwWindow, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

  // Setup Font
  ImGui::GetIO().Fonts->Clear();
  ImFontConfig font_cfg;
  strcpy(font_cfg.Name, "Roboto");
  font_cfg.PixelSnapH = true;
  font_cfg.OversampleH = 5;
  font_cfg.OversampleV = 5;
  font_cfg.FontDataOwnedByAtlas = false;
  ImGui::GetIO().Fonts->AddFontFromMemoryTTF(
      Roboto_Regular_ttf, Roboto_Regular_ttf_len, std::round(16), &font_cfg,
      ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());

  return 0;
}
// -----------------------------------------------------------------------------
void ImProjectApp::loop() {
  // Main loop
  while (glfwWindowShouldClose(_glfwWindow) == 0) {
    // Poll and handle events (inputs, window resize, etc.)
    glfwPollEvents();

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // ImGui docking
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(),
                                 ImGuiDockNodeFlags_PassthruCentralNode);
    paint();

    // Rendering
    ImGui::Render();
    glfwGetFramebufferSize(_glfwWindow, &_displayW, &_displayH);
    glViewport(0, 0, _displayW, _displayH);
    glClearColor(_clearColor.x * _clearColor.w, _clearColor.y * _clearColor.w,
                 _clearColor.z * _clearColor.w, _clearColor.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(_glfwWindow);
  }
}
// -----------------------------------------------------------------------------
void ImProjectApp::quit() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  ImPlot::DestroyContext();
  glfwDestroyWindow(_glfwWindow);
  glfwTerminate();
}
// -----------------------------------------------------------------------------
void ImProjectApp::onGlfwError(int error, const char *description) noexcept {
  fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}
