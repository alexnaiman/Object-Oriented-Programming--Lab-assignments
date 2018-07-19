import React, { Component } from 'react';
import { browserHistory } from 'react-router';

export default class TableRow extends Component {
  render() {
    const { row, properties } = this.props;
    // const filteredProperties = properties.map()
    return (
      <tr>
        {properties.map((k, index) => {
          if (k === 'Source') return <td  key={index}><a href={'https://' + row[k]} target="_blank">source</a></td>;
          return <td key={index}>{row[k]}</td>;
        })}
      </tr>
    );
  }
}
