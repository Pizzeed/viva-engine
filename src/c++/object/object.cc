#include <viva/application/application.h>
#include <viva/object/object.h>
#include <viva/scene/scene.h>

namespace viva
{
  Object::Object() {}

  Object::~Object() {}

  auto Object::destroy() -> void
  {
    if(not m_scene)
      return;
    m_scene->destroy_object(this);
  }

  auto Object::scene() -> Scene* { return m_scene; }
}  // namespace viva
