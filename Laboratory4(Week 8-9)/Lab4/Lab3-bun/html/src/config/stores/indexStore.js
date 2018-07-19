import { createStore, applyMiddleware } from 'redux'
import { composeWithDevTools } from 'redux-devtools-extension'
import promiseMiddleware from 'redux-promise-middleware'
import thunk from 'redux-thunk'
import reducers from './../reducers/indexReducer'

function reduxStore (initialState) {
  const store = createStore(reducers, initialState, composeWithDevTools(applyMiddleware(
    promiseMiddleware({
      promiseTypeSuffixes: ['loading', 'success', 'error']
    }),
    thunk
  )))

  if (module.hot) {
    // Enable Webpack hot module replacement for reducers
    module.hot.accept('../reducers/indexReducer', () => {
      // We need to require for hot reloading to work properly.
      const nextReducer = require('../reducers/indexReducer.js')  // eslint-disable-line global-require

      store.replaceReducer(nextReducer)
    })
  }
  return store
}

export default reduxStore
