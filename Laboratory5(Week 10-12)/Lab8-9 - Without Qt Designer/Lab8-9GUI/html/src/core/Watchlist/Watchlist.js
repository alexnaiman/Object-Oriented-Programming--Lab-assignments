import React, { Component } from 'react';
import data from '../../../watchlist.json';
import Table from '../Table/Table';

export default class Repository extends Component {
    render() {
        const properties = Object.getOwnPropertyNames(data["tutorials"][0]);
        return (
            <Table data={data} properties={properties} title="Master c++ watchlist"/>
        );
    }
}