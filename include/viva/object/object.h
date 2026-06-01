#pragma once

#include <viva/utils/types.h>

#include <memory>
#include <type_traits>

namespace viva
{
  class Scene;

  class Object
  {
   public:
    Object();
    virtual ~Object();
    virtual auto tick(f32 const delta) -> void = 0;
    virtual auto destroy() -> void;
    virtual auto clone(bool on_scene = false) -> std::shared_ptr<Object> = 0;

    auto scene() -> Scene*;

   protected:
    Scene* m_scene = nullptr;

    friend class Scene;
  };

  template <class T>
  concept ObjectDerived = std::is_base_of_v<Object, T>;
}  // namespace viva
