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
      The old React Native architecture does check needsCustomLayoutForChildren. So
      when you press the 'Hello' button you'll see the 'World' action view and a
      'close' button in the top left.
    </Text>
  </>
);

export default Example;
