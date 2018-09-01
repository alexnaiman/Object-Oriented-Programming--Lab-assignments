import React from 'react';
import classNames from 'classnames';

export default class LayerComponent extends React.Component {
  constructor(props) {
    super(props)
    this.handleScroll = this.handleScroll.bind(this);
    this.state = { translate3d: '' };
  }
  componentDidMount() {
    window.addEventListener('scroll', this.handleScroll);

  }
  componentWillUnmount() {
    window.removeEventListener('scroll', this.handleScroll);
  }


  handleScroll = (e) => {
    const {depth} = this.props;
    let topDistance = window.pageYOffset;
    let movement = topDistance * depth;
    //console.log(movement,topDistance);
    let translate3d = 'translate3d(0, ' + -movement + 'px, 0)';
    //console.log(translate3d);
    this.setState({ translate3d })
  }
  render() {
    const {translate3d} = this.state;
    return (
      <div className={classNames(this.props.classNames, 'layer')} style={{ WebkitTransform: this.state.translate3d }}   >
      </div>
    )

  }
}