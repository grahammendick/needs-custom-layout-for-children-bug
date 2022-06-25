import React from 'react';
import { View, Text } from 'react-native';
import { NavigationContext } from 'navigation-react';
import { NavigationBar, RightBar, BarButton, ActionBar } from 'navigation-react-native';

const Example = () => (
  <>
    <NavigationBar barTintColor="white">
      <RightBar>
        <BarButton title="Hello" show="always">
          <ActionBar>
            <View style={{ flex: 1, backgroundColor: 'white', alignItems: 'center', justifyContent: 'center', borderColor: 'black', borderWidth: 1 }}>
              <Text style={{ width: 100, textAlign: 'center' }}>World</Text>
            </View>
          </ActionBar>
        </BarButton>
      </RightBar>
    </NavigationBar>
    <Text>
      The new React Native architecture doesn't check needsCustomLayoutForChildren.
      Press the 'Hello' button and you'll see the 'World' action view. The trouble is
      that it can't be closed because React Native has positioned it over the top of
      the 'close' arrow that should appear in the top left.
    </Text>
  </>
);

export default Example;
