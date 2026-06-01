#pragma once

#include <GLFW/glfw3.h>
#include <viva/camera/camera.h>
#include <viva/object/object.h>
#include <viva/utils/types.h>

#include <memory>
#include <string>

namespace viva
{
  class Scene;
}  // namespace viva

namespace viva
{
  class Application
  {
   public:
    Application(Application const&) = delete;
    Application(Application&&) = delete;
    auto operator=(Application const&) = delete;
    auto operator=(Application&&) = delete;
    ~Application();

    static auto get() -> Application*;
    auto with_width(u32 const width) -> Application*;
    auto with_height(u32 const height) -> Application*;
    auto with_title(std::string const& title) -> Application*;
    auto init() -> void;
    auto run_graphics_loop() -> void;

    auto window() -> GLFWwindow* const;

    auto current_scene() -> std::shared_ptr<Scene> const&;
    auto set_current_scene(std::shared_ptr<Scene> const& scene) -> void;
    auto set_current_scene(std::shared_ptr<Scene>&& scene) -> void;

   private:
    Application();
    auto init_graphics() -> void;
    auto cleanup() -> void;
    static auto framebuffer_size_callback(GLFWwindow* window, int width, int height) -> void;

    std::shared_ptr<Scene> m_current_scene = nullptr;
    GLFWwindow* m_window;
    u32 m_window_width = 800;
    u32 m_window_height = 600;
    std::string m_window_title = "New Application";
  };
}  // namespace viva
