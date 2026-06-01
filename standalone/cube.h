#pragma once

#include <viva/material/material.h>
#include <viva/mesh/mesh.h>
#include <viva/utils/types.h>

#include <glm/ext/vector_float3.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class Cube : public viva::Mesh
{
 public:
  Cube(viva::Material* material, int size = 3);
  virtual ~Cube();

 protected:
  virtual auto tick(f32 const delta) -> void override {}

 private:
  u32 m_size;
};
