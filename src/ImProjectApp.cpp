#include "ImProjectApp.h"
#include "ImWrapper.h"
#include <GLFW/glfw3.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>  
#include <imgui.h>
#include <imgui_internal.h>
#include <implot.h>
#include <Fonts.h>
#include <chrono>

// See "Extremely Important Note" in README https://github.com/epezent/implot
// io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset' and handle ImDrawCmd::VtxOffset
// #define ImDrawIdx unsigned int

static void glfw_error_callback(int error, const char* description) noexcept
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

ImProjectApp::ImProjectApp()
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (glfwInit() == 0) {
        return;
    }

    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac

    // Create window with graphics context
    m_glwin = glfwCreateWindow(1024, 768, "BaseApp", nullptr, nullptr);
    if (m_glwin == nullptr) {
        return;
    }
    glfwMakeContextCurrent(m_glwin);
    glfwSwapInterval(1);  // Enable vsync

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImPlot::CreateContext();

    // Backend
    ImGui::GetIO().BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;
    // Keyboard
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    // Docking
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    // Viewports
    // ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(m_glwin, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Setup Font
    ImGui::GetIO().Fonts->Clear();
    ImFontConfig font_cfg;
    strcpy(font_cfg.Name, "Roboto");
    font_cfg.PixelSnapH = true;
    font_cfg.OversampleH = 5;
    font_cfg.OversampleV = 5;
    font_cfg.FontDataOwnedByAtlas = false;
    ImGui::GetIO().Fonts->AddFontFromMemoryTTF(Roboto_Regular_ttf,
        Roboto_Regular_ttf_len, std::round(16), &font_cfg,
        ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
}

ImProjectApp::~ImProjectApp()
{
}

void ImProjectApp::run()
{
    beforeRun();

    // Main loop
    while (glfwWindowShouldClose(m_glwin) == 0) {
        // Poll and handle events (inputs, window resize, etc.)
        glfwPollEvents();

        // OpenGL frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Resize viewport
        int display_w{0}, display_h{0};
        glfwGetFramebufferSize(m_glwin, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

        // Clear background
        glfwGetFramebufferSize(m_glwin, &m_frameBufferW, &m_frameBufferH);
        glViewport(0, 0, m_frameBufferW, m_frameBufferH);
        glClearColor(0.1, 0.1, 0.1, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // ImGui docking
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

        paint({ float(display_w), float(display_h) });
        ImGui::EndFrame();

        //ImGui::UpdatePlatformWindows();

        // Rendering
        ImGui::Render();
        // finialize the imgui render into draw data, and render it.
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // swap the render/draw buffers so the user can see this frame.
        glfwSwapBuffers(m_glwin);

        /*
        // change the native (host) window size if requested.
        if (newSize.has_value()) {_
            glfwSetWindowSize(window, newSize.value().first, newSize.value().second);
            newSize.reset();
        }*/

    }
}

void ImProjectApp::quit()
{
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  ImPlot::DestroyContext();
  glfwDestroyWindow(m_glwin);
  glfwTerminate();
}

void ImProjectApp::paint(const ImVec2&)
{
    static auto helloLabel = ImWrap::Label("Hello World");
    ImGui::Begin("Welcome Window");
    helloLabel.paint();
    ImGui::End();
}
