#include <GLFW/glfw3.h>
//#include "C:/libs/glfw-3.4/include/GLFW/glfw3.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

// Platform-specific header for native handle
#if defined(_WIN32)
    #define GLFW_EXPOSE_NATIVE_WIN32
    #include <GLFW/glfw3native.h>
#endif

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "bgfx Window", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Get native window handle
    bgfx::PlatformData pd{};
    pd.nwh = glfwGetWin32Window(window); // Windows-specific

    bgfx::Init init;
    init.type = bgfx::RendererType::Count; // Auto-select
    init.platformData = pd;
    init.resolution.width = 800;
    init.resolution.height = 600;
    init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(init);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
        bgfx::setViewRect(0, 0, 0, 800, 600);
        bgfx::touch(0);
        bgfx::frame();

        glfwSwapBuffers(window); // Not strictly required for bgfx
    }

    bgfx::shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
