#include <viva/engine-core/application/application.h>
#include <viva/engine-core/object/object.h>
#include <viva/engine-core/scene/scene.h>

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
