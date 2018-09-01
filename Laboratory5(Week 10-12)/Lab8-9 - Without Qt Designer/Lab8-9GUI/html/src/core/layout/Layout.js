import React, { PropTypes } from 'react';
import { connect } from 'react-redux';
import { Navbar, Nav, NavItem } from 'react-bootstrap';

class Layout extends React.Component {
  render() {
    return (
      <div>
        {this.props.children}
      </div>
    );
  }
}

Layout.propTypes = {
  children: PropTypes.node
};

export default connect()(Layout);
