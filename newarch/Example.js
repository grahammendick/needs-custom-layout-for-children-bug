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
      With the new React Native architecture, large titles only work the first
      time you see them. Press the button and you'll see a large 'World' title
      on the next screen. If you go back and press the button again then the
      'World' title is small instead.
    </Text>
  </>
);

export default Example;
