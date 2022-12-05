#pragma once

#include <backends/imgui_impl_glfw.h>

class ImProjectApp
{
public:
    ImProjectApp();
    virtual ~ImProjectApp();

    void run();
    void quit();

protected:
    virtual void beforeRun() {}
    virtual void paint(const ImVec2& mainWindowSize);

private:
    GLFWwindow* m_glwin = nullptr;

    int m_frameBufferW{1024};
    int m_frameBufferH{768};
};


