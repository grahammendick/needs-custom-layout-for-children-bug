#include "MainComponentsRegistry.h"

#include <CoreComponentsRegistry.h>
#include <fbjni/fbjni.h>
#include <react/renderer/componentregistry/ComponentDescriptorProviderRegistry.h>
#include <react/renderer/components/navigation-react-native/ComponentDescriptors.h>
#include <react/renderer/components/navigation-react-native/NVActionBarComponentDescriptor.h>
#include <react/renderer/components/navigation-react-native/NVSearchBarComponentDescriptor.h>
#include <react/renderer/components/navigation-react-native/NVTitleBarComponentDescriptor.h>
#include <react/renderer/components/rncore/ComponentDescriptors.h>

namespace facebook {
namespace react {

MainComponentsRegistry::MainComponentsRegistry(ComponentFactory *delegate) {}

std::shared_ptr<ComponentDescriptorProviderRegistry const>
MainComponentsRegistry::sharedProviderRegistry() {
  auto providerRegistry = CoreComponentsRegistry::sharedProviderRegistry();

  // Custom Fabric Components go here. You can register custom
  // components coming from your App or from 3rd party libraries here.
  //
  // providerRegistry->add(concreteComponentDescriptorProvider<
  //        AocViewerComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVActionBarComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVBarButtonComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVBottomAppBarComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVBottomSheetComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVCollapsingBarComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVCoordinatorLayoutComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVExtendedFloatingActionButtonComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVFloatingActionButtonComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVNavigationBarComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVNavigationStackComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVSceneComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVSearchBarComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVSharedElementComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVStatusBarComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVTabBarItemComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVTabBarComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVTabBarPagerComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVTabBarPagerRTLComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVTabLayoutComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVTabLayoutRTLComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVTabNavigationComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVTitleBarComponentDescriptor>());
  providerRegistry->add(concreteComponentDescriptorProvider<NVToolbarComponentDescriptor>());
  return providerRegistry;
}

jni::local_ref<MainComponentsRegistry::jhybriddata>
MainComponentsRegistry::initHybrid(
    jni::alias_ref<jclass>,
    ComponentFactory *delegate) {
  auto instance = makeCxxInstance(delegate);

  auto buildRegistryFunction =
      [](EventDispatcher::Weak const &eventDispatcher,
         ContextContainer::Shared const &contextContainer)
      -> ComponentDescriptorRegistry::Shared {
    auto registry = MainComponentsRegistry::sharedProviderRegistry()
                        ->createComponentDescriptorRegistry(
                            {eventDispatcher, contextContainer});

    auto mutableRegistry =
        std::const_pointer_cast<ComponentDescriptorRegistry>(registry);

    mutableRegistry->setFallbackComponentDescriptor(
        std::make_shared<UnimplementedNativeViewComponentDescriptor>(
            ComponentDescriptorParameters{
                eventDispatcher, contextContainer, nullptr}));

    return registry;
  };

  delegate->buildRegistryFunction = buildRegistryFunction;
  return instance;
}

void MainComponentsRegistry::registerNatives() {
  registerHybrid({
      makeNativeMethod("initHybrid", MainComponentsRegistry::initHybrid),
  });
}

} // namespace react
} // namespace facebook
