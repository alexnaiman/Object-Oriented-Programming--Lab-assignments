import 'babel-polyfill';
import React from 'react';
import ReactDOM from 'react-dom';
import { AppContainer } from 'react-hot-loader';
import { Provider } from 'react-redux';
import { Router, Route, browserHistory } from 'react-router';
import { syncHistoryWithStore } from 'react-router-redux';
import configureStore from './config/stores/indexStore';
import Layout from './core/layout/Layout';
import Repository from './core/Repository/Repository';
import Watchlist from './core/Watchlist/Watchlist';

require('./style/index.scss');

const store = configureStore()
const history = syncHistoryWithStore(browserHistory, store)

ReactDOM.render(
  <AppContainer>
    <Provider store={store}>
      <Router history={history}>
        <Route component={Layout}>
          <Route component={Repository} path="/" />
          <Route component={Watchlist} path="/watchlist" />
        </Route>
      </Router>
    </Provider>
  </AppContainer>,
  document.getElementById('app')
)
