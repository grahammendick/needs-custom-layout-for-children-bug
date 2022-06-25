import React from 'react';
import { View, Text } from 'react-native';
import { NavigationContext } from 'navigation-react';
import { NavigationBar, RightBar, ActionBar } from 'navigation-react-native';

const Hello = () => (
  <>
    <NavigationBar title="Hello">
      <RightBar>
        <BarButton title="search" show="always">
            <ActionBar>
              <View style={{flex: 1, backgroundColor: 'green', alignItems: 'center', justifyContent: 'center'}}>
                <Text style={{width: 100, textAlign: 'center', backgroundColor: 'yellow'}}>Hello</Text>
              </View>
            </ActionBar>
          </BarButton>
        </RightBar>
      </NavigationBar>
    </NavigationBar>
    <Text>
      With the new React Native architecture, large titles only work the first
      time you see them. Press the button and you'll see a large 'World' title
      on the next screen. If you go back and press the button again then the
      'World' title is small instead.
    </Text>
  </>
);

export default Hello;
