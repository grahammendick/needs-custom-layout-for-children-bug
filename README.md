# needsCustomLayoutForChildren on the new React Native architecture
This repository contains 2 "Hello World" React Native apps. One is built with the old React Native architecture and the other is built with the new React Native architecture. The apps are the same. They each consist of 1 screen with a 'Hello'
button. When you press the button and you'll see a 'World' action view. There should
also be a button in the top left that closes the action view.

## Steps to recreate the problem
1. cd to the `newarch` app
2. Run `npm install`
3. Run `npx react-native run-android`
4. Press the 'Hello' button
5. The 'World' action view appears
6. The action view can't be closed because the button in the top left is missing.

Repeat the above steps in the oldarch app and you'll see that the close button appears
as expected in the top left at step 6.