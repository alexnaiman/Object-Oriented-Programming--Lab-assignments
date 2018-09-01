import React, { Component } from 'react';
import { Grid, Row, Col } from 'react-bootstrap';

export default class Dashboard extends Component {
  state = {}
  render() {
    return (
      <div className="container">
        <div style={{flex: 1, backgroundColor:'yellow'}}>
          <div className="donatorLogSign"><h1>Donator</h1>
          </div>
        </div>
        <div style={{flex: 1, backgroundColor:'pink'}}>
          <div className="donatorLogSign"><h1>Cause</h1>
          </div>
        </div>
      </div>
    );
  }
}
