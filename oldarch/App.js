import React from 'react';
import {StateNavigator} from 'navigation';
import {NavigationHandler} from 'navigation-react';
import {NavigationStack, Scene} from 'navigation-react-native';
import Example from './Example';

const stateNavigator = new StateNavigator([
  {key: 'example', title: 'Example'},
]);

const App = () => (
  <NavigationHandler stateNavigator={stateNavigator}>
    <NavigationStack>
      <Scene stateKey="example"><Example /></Scene>
    </NavigationStack>
  </NavigationHandler>
);

export default App;
