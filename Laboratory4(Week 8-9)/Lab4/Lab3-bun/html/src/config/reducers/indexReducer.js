import { routerReducer } from 'react-router-redux'
import { combineReducers } from 'redux'

const combined = combineReducers(
  {
    routing: routerReducer
  }
)

module.exports = combined
