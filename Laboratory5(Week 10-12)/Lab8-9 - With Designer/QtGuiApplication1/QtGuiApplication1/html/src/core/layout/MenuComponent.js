import React, { Component, PropTypes } from 'react';
import { Menu } from 'semantic-ui-react';
import { browserHistory } from 'react-router';

export default class MenuComponent extends Component {

  handleItemClick = (e, { name }) => {
    this.setState({ activeItem: name });

   // find the menuItem with the given name and push it in browserHistory so the client is sent to the new page
    const item = this.props.menuItems.filter(menuItem => name === menuItem.name)[0];

    browserHistory.push(item.pathname);

  }

  render() {
    const activeItem = this.props.pathname;
    const menuItems = this.props.menuItems.map((item, index) => (
      <Menu.Item
        key={index}
        onClick={this.handleItemClick}
        name={item.name}
        active={activeItem === item.pathname}
        color="purple"
      >
        {item.name.toUpperCase()}
      </Menu.Item>
      ));
    return (
      <Menu>
        {menuItems}
      </Menu>
    );
  }
}
MenuComponent.propTypes = {
  menuItems: PropTypes.arrayOf(PropTypes.object).isRequired,
  pathname: PropTypes.string.isRequired
}