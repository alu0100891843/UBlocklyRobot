extern "C" void RegisterStaticallyLinkedModulesGranular()
{
	void RegisterModule_SharedInternals();
	RegisterModule_SharedInternals();

	void RegisterModule_Core();
	RegisterModule_Core();

	void RegisterModule_Animation();
	RegisterModule_Animation();

	void RegisterModule_Audio();
	RegisterModule_Audio();

	void RegisterModule_Physics();
	RegisterModule_Physics();

	void RegisterModule_Terrain();
	RegisterModule_Terrain();

	void RegisterModule_TerrainPhysics();
	RegisterModule_TerrainPhysics();

	void RegisterModule_TextRendering();
	RegisterModule_TextRendering();

	void RegisterModule_UI();
	RegisterModule_UI();

	void RegisterModule_UnityConnect();
	RegisterModule_UnityConnect();

	void RegisterModule_IMGUI();
	RegisterModule_IMGUI();

	void RegisterModule_JSONSerialize();
	RegisterModule_JSONSerialize();

	void RegisterModule_UnityWebRequest();
	RegisterModule_UnityWebRequest();

	void RegisterModule_UnityAnalytics();
	RegisterModule_UnityAnalytics();

	void RegisterModule_TLS();
	RegisterModule_TLS();

	void RegisterModule_PerformanceReporting();
	RegisterModule_PerformanceReporting();

	void RegisterModule_WebGL();
	RegisterModule_WebGL();

}

template <typename T> void RegisterUnityClass(const char*);
template <typename T> void RegisterStrippedType(int, const char*, const char*);

void InvokeRegisterStaticallyLinkedModuleClasses()
{
	// Do nothing (we're in stripping mode)
}

namespace ObjectProduceTestTypes { class Derived; } 
namespace ObjectProduceTestTypes { class SubDerived; } 
class EditorExtension; template <> void RegisterUnityClass<EditorExtension>(const char*);
namespace Unity { class Component; } template <> void RegisterUnityClass<Unity::Component>(const char*);
class Behaviour; template <> void RegisterUnityClass<Behaviour>(const char*);
class Animation; 
class Animator; template <> void RegisterUnityClass<Animator>(const char*);
class AudioBehaviour; template <> void RegisterUnityClass<AudioBehaviour>(const char*);
class AudioListener; template <> void RegisterUnityClass<AudioListener>(const char*);
class AudioSource; 
class AudioFilter; 
class AudioChorusFilter; 
class AudioDistortionFilter; 
class AudioEchoFilter; 
class AudioHighPassFilter; 
class AudioLowPassFilter; 
class AudioReverbFilter; 
class AudioReverbZone; 
class Camera; template <> void RegisterUnityClass<Camera>(const char*);
namespace UI { class Canvas; } template <> void RegisterUnityClass<UI::Canvas>(const char*);
namespace UI { class CanvasGroup; } template <> void RegisterUnityClass<UI::CanvasGroup>(const char*);
namespace Unity { class Cloth; } 
class Collider2D; 
class BoxCollider2D; 
class CapsuleCollider2D; 
class CircleCollider2D; 
class CompositeCollider2D; 
class EdgeCollider2D; 
class PolygonCollider2D; 
class TilemapCollider2D; 
class ConstantForce; 
class Effector2D; 
class AreaEffector2D; 
class BuoyancyEffector2D; 
class PlatformEffector2D; 
class PointEffector2D; 
class SurfaceEffector2D; 
class FlareLayer; template <> void RegisterUnityClass<FlareLayer>(const char*);
class GUIElement; template <> void RegisterUnityClass<GUIElement>(const char*);
namespace TextRenderingPrivate { class GUIText; } template <> void RegisterUnityClass<TextRenderingPrivate::GUIText>(const char*);
class GUITexture; 
class GUILayer; template <> void RegisterUnityClass<GUILayer>(const char*);
class GridLayout; 
class Grid; 
class Tilemap; 
class Halo; 
class HaloLayer; 
class IConstraint; 
class AimConstraint; 
class LookAtConstraint; 
class ParentConstraint; 
class PositionConstraint; 
class RotationConstraint; 
class ScaleConstraint; 
class Joint2D; 
class AnchoredJoint2D; 
class DistanceJoint2D; 
class FixedJoint2D; 
class FrictionJoint2D; 
class HingeJoint2D; 
class SliderJoint2D; 
class SpringJoint2D; 
class WheelJoint2D; 
class RelativeJoint2D; 
class TargetJoint2D; 
class LensFlare; 
class Light; template <> void RegisterUnityClass<Light>(const char*);
class LightProbeGroup; 
class LightProbeProxyVolume; 
class MonoBehaviour; template <> void RegisterUnityClass<MonoBehaviour>(const char*);
class NavMeshAgent; 
class NavMeshObstacle; 
class OffMeshLink; 
class ParticleSystemForceField; 
class PhysicsUpdateBehaviour2D; 
class ConstantForce2D; 
class PlayableDirector; 
class Projector; 
class ReflectionProbe; template <> void RegisterUnityClass<ReflectionProbe>(const char*);
class Skybox; 
class SortingGroup; 
class StreamingController; 
class Terrain; template <> void RegisterUnityClass<Terrain>(const char*);
class VideoPlayer; 
class VisualEffect; 
class WindZone; 
namespace UI { class CanvasRenderer; } template <> void RegisterUnityClass<UI::CanvasRenderer>(const char*);
class Collider; template <> void RegisterUnityClass<Collider>(const char*);
class BoxCollider; template <> void RegisterUnityClass<BoxCollider>(const char*);
class CapsuleCollider; template <> void RegisterUnityClass<CapsuleCollider>(const char*);
class CharacterController; 
class MeshCollider; template <> void RegisterUnityClass<MeshCollider>(const char*);
class SphereCollider; template <> void RegisterUnityClass<SphereCollider>(const char*);
class TerrainCollider; template <> void RegisterUnityClass<TerrainCollider>(const char*);
class WheelCollider; 
class FakeComponent; 
namespace Unity { class Joint; } template <> void RegisterUnityClass<Unity::Joint>(const char*);
namespace Unity { class CharacterJoint; } 
namespace Unity { class ConfigurableJoint; } 
namespace Unity { class FixedJoint; } 
namespace Unity { class HingeJoint; } template <> void RegisterUnityClass<Unity::HingeJoint>(const char*);
namespace Unity { class SpringJoint; } 
class LODGroup; 
class MeshFilter; template <> void RegisterUnityClass<MeshFilter>(const char*);
class OcclusionArea; 
class OcclusionPortal; 
class ParticleSystem; 
class Renderer; template <> void RegisterUnityClass<Renderer>(const char*);
class BillboardRenderer; 
class LineRenderer; 
class RendererFake; 
class MeshRenderer; template <> void RegisterUnityClass<MeshRenderer>(const char*);
class ParticleSystemRenderer; 
class SkinnedMeshRenderer; 
class SpriteMask; 
class SpriteRenderer; 
class SpriteShapeRenderer; 
class TilemapRenderer; 
class TrailRenderer; 
class VFXRenderer; 
class Rigidbody; template <> void RegisterUnityClass<Rigidbody>(const char*);
class Rigidbody2D; 
namespace TextRenderingPrivate { class TextMesh; } template <> void RegisterUnityClass<TextRenderingPrivate::TextMesh>(const char*);
class Transform; template <> void RegisterUnityClass<Transform>(const char*);
namespace UI { class RectTransform; } template <> void RegisterUnityClass<UI::RectTransform>(const char*);
class Tree; 
class GameObject; template <> void RegisterUnityClass<GameObject>(const char*);
class NamedObject; template <> void RegisterUnityClass<NamedObject>(const char*);
class AssetBundle; 
class AssetBundleManifest; 
class ScriptedImporter; 
class AudioMixer; 
class AudioMixerController; 
class AudioMixerGroup; 
class AudioMixerGroupController; 
class AudioMixerSnapshot; 
class AudioMixerSnapshotController; 
class Avatar; 
class AvatarMask; 
class BillboardAsset; 
class ComputeShader; template <> void RegisterUnityClass<ComputeShader>(const char*);
class Flare; 
namespace TextRendering { class Font; } template <> void RegisterUnityClass<TextRendering::Font>(const char*);
class GameObjectRecorder; 
class LightProbes; template <> void RegisterUnityClass<LightProbes>(const char*);
class LocalizationAsset; 
class Material; template <> void RegisterUnityClass<Material>(const char*);
class ProceduralMaterial; 
class Mesh; template <> void RegisterUnityClass<Mesh>(const char*);
class Motion; 
class AnimationClip; 
class PreviewAnimationClip; 
class NavMeshData; 
class OcclusionCullingData; 
class PhysicMaterial; 
class PhysicsMaterial2D; 
class PreloadData; template <> void RegisterUnityClass<PreloadData>(const char*);
class RuntimeAnimatorController; template <> void RegisterUnityClass<RuntimeAnimatorController>(const char*);
class AnimatorController; 
class AnimatorOverrideController; template <> void RegisterUnityClass<AnimatorOverrideController>(const char*);
class SampleClip; template <> void RegisterUnityClass<SampleClip>(const char*);
class AudioClip; template <> void RegisterUnityClass<AudioClip>(const char*);
class Shader; template <> void RegisterUnityClass<Shader>(const char*);
class ShaderVariantCollection; 
class SpeedTreeWindAsset; 
class Sprite; template <> void RegisterUnityClass<Sprite>(const char*);
class SpriteAtlas; template <> void RegisterUnityClass<SpriteAtlas>(const char*);
class SubstanceArchive; 
class TerrainData; template <> void RegisterUnityClass<TerrainData>(const char*);
class TerrainLayer; 
class TextAsset; template <> void RegisterUnityClass<TextAsset>(const char*);
class CGProgram; template <> void RegisterUnityClass<CGProgram>(const char*);
class MonoScript; template <> void RegisterUnityClass<MonoScript>(const char*);
class Texture; template <> void RegisterUnityClass<Texture>(const char*);
class BaseVideoTexture; 
class WebCamTexture; 
class CubemapArray; template <> void RegisterUnityClass<CubemapArray>(const char*);
class LowerResBlitTexture; template <> void RegisterUnityClass<LowerResBlitTexture>(const char*);
class ProceduralTexture; 
class RenderTexture; template <> void RegisterUnityClass<RenderTexture>(const char*);
class CustomRenderTexture; 
class SparseTexture; 
class Texture2D; template <> void RegisterUnityClass<Texture2D>(const char*);
class Cubemap; template <> void RegisterUnityClass<Cubemap>(const char*);
class Texture2DArray; template <> void RegisterUnityClass<Texture2DArray>(const char*);
class Texture3D; template <> void RegisterUnityClass<Texture3D>(const char*);
class VideoClip; 
class VisualEffectAsset; 
class VisualEffectResource; 
class GameManager; template <> void RegisterUnityClass<GameManager>(const char*);
class GlobalGameManager; template <> void RegisterUnityClass<GlobalGameManager>(const char*);
class AudioManager; template <> void RegisterUnityClass<AudioManager>(const char*);
class BuildSettings; template <> void RegisterUnityClass<BuildSettings>(const char*);
class DelayedCallManager; template <> void RegisterUnityClass<DelayedCallManager>(const char*);
class GraphicsSettings; template <> void RegisterUnityClass<GraphicsSettings>(const char*);
class InputManager; template <> void RegisterUnityClass<InputManager>(const char*);
class MonoManager; template <> void RegisterUnityClass<MonoManager>(const char*);
class NavMeshProjectSettings; 
class Physics2DSettings; 
class PhysicsManager; template <> void RegisterUnityClass<PhysicsManager>(const char*);
class PlayerSettings; template <> void RegisterUnityClass<PlayerSettings>(const char*);
class QualitySettings; template <> void RegisterUnityClass<QualitySettings>(const char*);
class ResourceManager; template <> void RegisterUnityClass<ResourceManager>(const char*);
class RuntimeInitializeOnLoadManager; template <> void RegisterUnityClass<RuntimeInitializeOnLoadManager>(const char*);
class ScriptMapper; template <> void RegisterUnityClass<ScriptMapper>(const char*);
class StreamingManager; 
class TagManager; template <> void RegisterUnityClass<TagManager>(const char*);
class TimeManager; template <> void RegisterUnityClass<TimeManager>(const char*);
class UnityConnectSettings; template <> void RegisterUnityClass<UnityConnectSettings>(const char*);
class VFXManager; 
class LevelGameManager; template <> void RegisterUnityClass<LevelGameManager>(const char*);
class LightmapSettings; template <> void RegisterUnityClass<LightmapSettings>(const char*);
class NavMeshSettings; 
class OcclusionCullingSettings; 
class RenderSettings; template <> void RegisterUnityClass<RenderSettings>(const char*);
class NativeObjectType; 
class PropertyModificationsTargetTestObject; 
class SerializableManagedHost; 
class SerializableManagedRefTestClass; 
namespace ObjectProduceTestTypes { class SiblingDerived; } 
class TestObjectVectorPairStringBool; 
class TestObjectWithSerializedAnimationCurve; 
class TestObjectWithSerializedArray; 
class TestObjectWithSerializedMapStringBool; 
class TestObjectWithSerializedMapStringNonAlignedStruct; 
class TestObjectWithSpecialLayoutOne; 
class TestObjectWithSpecialLayoutTwo; 

void RegisterAllClasses()
{
void RegisterBuiltinTypes();
RegisterBuiltinTypes();
	//Total: 80 non stripped classes
	//0. Camera
	RegisterUnityClass<Camera>("Core");
	//1. Behaviour
	RegisterUnityClass<Behaviour>("Core");
	//2. Unity::Component
	RegisterUnityClass<Unity::Component>("Core");
	//3. EditorExtension
	RegisterUnityClass<EditorExtension>("Core");
	//4. ReflectionProbe
	RegisterUnityClass<ReflectionProbe>("Core");
	//5. QualitySettings
	RegisterUnityClass<QualitySettings>("Core");
	//6. GlobalGameManager
	RegisterUnityClass<GlobalGameManager>("Core");
	//7. GameManager
	RegisterUnityClass<GameManager>("Core");
	//8. Renderer
	RegisterUnityClass<Renderer>("Core");
	//9. Shader
	RegisterUnityClass<Shader>("Core");
	//10. NamedObject
	RegisterUnityClass<NamedObject>("Core");
	//11. Material
	RegisterUnityClass<Material>("Core");
	//12. Light
	RegisterUnityClass<Light>("Core");
	//13. MeshFilter
	RegisterUnityClass<MeshFilter>("Core");
	//14. MeshRenderer
	RegisterUnityClass<MeshRenderer>("Core");
	//15. Mesh
	RegisterUnityClass<Mesh>("Core");
	//16. Texture
	RegisterUnityClass<Texture>("Core");
	//17. Texture2D
	RegisterUnityClass<Texture2D>("Core");
	//18. Cubemap
	RegisterUnityClass<Cubemap>("Core");
	//19. Texture3D
	RegisterUnityClass<Texture3D>("Core");
	//20. Texture2DArray
	RegisterUnityClass<Texture2DArray>("Core");
	//21. CubemapArray
	RegisterUnityClass<CubemapArray>("Core");
	//22. RenderTexture
	RegisterUnityClass<RenderTexture>("Core");
	//23. GUIElement
	RegisterUnityClass<GUIElement>("Core");
	//24. GUILayer
	RegisterUnityClass<GUILayer>("Core");
	//25. GameObject
	RegisterUnityClass<GameObject>("Core");
	//26. MonoBehaviour
	RegisterUnityClass<MonoBehaviour>("Core");
	//27. TextAsset
	RegisterUnityClass<TextAsset>("Core");
	//28. ComputeShader
	RegisterUnityClass<ComputeShader>("Core");
	//29. LowerResBlitTexture
	RegisterUnityClass<LowerResBlitTexture>("Core");
	//30. PreloadData
	RegisterUnityClass<PreloadData>("Core");
	//31. UI::RectTransform
	RegisterUnityClass<UI::RectTransform>("Core");
	//32. Transform
	RegisterUnityClass<Transform>("Core");
	//33. Sprite
	RegisterUnityClass<Sprite>("Core");
	//34. SpriteAtlas
	RegisterUnityClass<SpriteAtlas>("Core");
	//35. Animator
	RegisterUnityClass<Animator>("Animation");
	//36. AnimatorOverrideController
	RegisterUnityClass<AnimatorOverrideController>("Animation");
	//37. RuntimeAnimatorController
	RegisterUnityClass<RuntimeAnimatorController>("Animation");
	//38. AudioClip
	RegisterUnityClass<AudioClip>("Audio");
	//39. SampleClip
	RegisterUnityClass<SampleClip>("Audio");
	//40. Rigidbody
	RegisterUnityClass<Rigidbody>("Physics");
	//41. Collider
	RegisterUnityClass<Collider>("Physics");
	//42. MeshCollider
	RegisterUnityClass<MeshCollider>("Physics");
	//43. BoxCollider
	RegisterUnityClass<BoxCollider>("Physics");
	//44. Unity::HingeJoint
	RegisterUnityClass<Unity::HingeJoint>("Physics");
	//45. Unity::Joint
	RegisterUnityClass<Unity::Joint>("Physics");
	//46. Terrain
	RegisterUnityClass<Terrain>("Terrain");
	//47. TerrainData
	RegisterUnityClass<TerrainData>("Terrain");
	//48. TextRenderingPrivate::TextMesh
	RegisterUnityClass<TextRenderingPrivate::TextMesh>("TextRendering");
	//49. TextRendering::Font
	RegisterUnityClass<TextRendering::Font>("TextRendering");
	//50. UI::Canvas
	RegisterUnityClass<UI::Canvas>("UI");
	//51. UI::CanvasGroup
	RegisterUnityClass<UI::CanvasGroup>("UI");
	//52. UI::CanvasRenderer
	RegisterUnityClass<UI::CanvasRenderer>("UI");
	//53. MonoScript
	RegisterUnityClass<MonoScript>("Core");
	//54. UnityConnectSettings
	RegisterUnityClass<UnityConnectSettings>("UnityConnect");
	//55. AudioManager
	RegisterUnityClass<AudioManager>("Audio");
	//56. PhysicsManager
	RegisterUnityClass<PhysicsManager>("Physics");
	//57. PlayerSettings
	RegisterUnityClass<PlayerSettings>("Core");
	//58. TimeManager
	RegisterUnityClass<TimeManager>("Core");
	//59. InputManager
	RegisterUnityClass<InputManager>("Core");
	//60. TagManager
	RegisterUnityClass<TagManager>("Core");
	//61. MonoManager
	RegisterUnityClass<MonoManager>("Core");
	//62. GraphicsSettings
	RegisterUnityClass<GraphicsSettings>("Core");
	//63. DelayedCallManager
	RegisterUnityClass<DelayedCallManager>("Core");
	//64. BuildSettings
	RegisterUnityClass<BuildSettings>("Core");
	//65. RuntimeInitializeOnLoadManager
	RegisterUnityClass<RuntimeInitializeOnLoadManager>("Core");
	//66. ResourceManager
	RegisterUnityClass<ResourceManager>("Core");
	//67. ScriptMapper
	RegisterUnityClass<ScriptMapper>("Core");
	//68. FlareLayer
	RegisterUnityClass<FlareLayer>("Core");
	//69. AudioBehaviour
	RegisterUnityClass<AudioBehaviour>("Audio");
	//70. AudioListener
	RegisterUnityClass<AudioListener>("Audio");
	//71. TextRenderingPrivate::GUIText
	RegisterUnityClass<TextRenderingPrivate::GUIText>("TextRendering");
	//72. LightmapSettings
	RegisterUnityClass<LightmapSettings>("Core");
	//73. LevelGameManager
	RegisterUnityClass<LevelGameManager>("Core");
	//74. CGProgram
	RegisterUnityClass<CGProgram>("Core");
	//75. RenderSettings
	RegisterUnityClass<RenderSettings>("Core");
	//76. LightProbes
	RegisterUnityClass<LightProbes>("Core");
	//77. CapsuleCollider
	RegisterUnityClass<CapsuleCollider>("Physics");
	//78. SphereCollider
	RegisterUnityClass<SphereCollider>("Physics");
	//79. TerrainCollider
	RegisterUnityClass<TerrainCollider>("TerrainPhysics");

}