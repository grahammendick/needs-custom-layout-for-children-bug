import React from 'react';
import {StateNavigator} from 'navigation';
import {NavigationHandler} from 'navigation-react';
import {NavigationStack, Scene} from 'navigation-react-native';
import Hello from './Hello';
import World from './World';

const stateNavigator = new StateNavigator([
  {key: 'hello', title: 'Hello'},
  {key: 'world', title: 'World', trackCrumbTrail: true},
]);

const App = () => (
  <NavigationHandler stateNavigator={stateNavigator}>
    <NavigationStack>
    <Scene stateKey="hello"><Hello /></Scene>
    <Scene stateKey="world"><World /></Scene>
    </NavigationStack>
  </NavigationHandler>
);

export default App;
