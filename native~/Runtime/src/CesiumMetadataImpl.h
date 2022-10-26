#pragma once

#include <CesiumGltf/AccessorView.h>
#include <CesiumGltf/Model.h>
#include <DotNet/CesiumForUnity/MetadataProperty.h>
#include <DotNet/System/String.h>
#include <DotNet/System/Array1.h>
#include <unordered_map>
#include <DotNet/UnityEngine/GameObject.h>

namespace DotNet::CesiumForUnity {
class CesiumMetadata;
}

namespace DotNet::UnityEngine {
class Transform;
}

namespace CesiumForUnityNative {

using AccessorType = std::variant<
    CesiumGltf::AccessorView<CesiumGltf::AccessorTypes::SCALAR<int8_t>>,
    CesiumGltf::AccessorView<CesiumGltf::AccessorTypes::SCALAR<uint8_t>>,
    CesiumGltf::AccessorView<CesiumGltf::AccessorTypes::SCALAR<int16_t>>,
    CesiumGltf::AccessorView<CesiumGltf::AccessorTypes::SCALAR<uint16_t>>,
    CesiumGltf::AccessorView<CesiumGltf::AccessorTypes::SCALAR<uint32_t>>,
    CesiumGltf::AccessorView<CesiumGltf::AccessorTypes::SCALAR<float>>>;

class CesiumMetadataImpl {
public:
  ~CesiumMetadataImpl(){};
  CesiumMetadataImpl(const DotNet::CesiumForUnity::CesiumMetadata& metadata){};
  void JustBeforeDelete(const DotNet::CesiumForUnity::CesiumMetadata& metadata){};
  void loadMetadata(const DotNet::UnityEngine::GameObject* pGameObject, const CesiumGltf::Model* pModel);

  void loadMetadata(
      const DotNet::CesiumForUnity::CesiumMetadata& metadata,
      const DotNet::UnityEngine::Transform& transform,
      int triangleIndex,
      DotNet::System::Array1<DotNet::CesiumForUnity::MetadataProperty>
          properties);

  int getNumberOfProperties(
      const DotNet::CesiumForUnity::CesiumMetadata& metadata,
      const DotNet::UnityEngine::Transform& transform);

private:
  void loadMetadata();

  std::unordered_map<const DotNet::UnityEngine::GameObject*, const CesiumGltf::Model*> _pModels;

  using FeatureTable = std::unordered_map<std::string, PropertyType>;

  using FeatureIDAttribute = std::pair<std::string, AccessorType>;

};
} // namespace CesiumForUnityNative
