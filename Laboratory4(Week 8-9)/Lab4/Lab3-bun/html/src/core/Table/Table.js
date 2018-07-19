import React, { Component } from 'react';
import data from '../../../data.json';
import Row from './TableRow';

export default class Table extends Component {
  render() {
    const {properties, title, data} = this.props;
    //const properties = Object.getOwnPropertyNames(data["tutorials"][0]);
    return (
      <div className="container">
        <h1>{title}</h1>
        <div className="tbl-header">
          <table>
            <thead>
              <tr>
                {properties.map((k, index) => <th key={index}>{k}</th>)}
              </tr>
            </thead>
          </table>
        </div>
        <div className="tbl-content">
          <table >
            <tbody>
              {data.tutorials.map(k => <Row row={k} properties={properties} />)}
            </tbody>
          </table>
        </div>
      </div>
    );
  }
}
