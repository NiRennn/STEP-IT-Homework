import "./Item.css";
import React from 'react';

const Item = ({ shoe }) => {
  const shoeImg = require(`../../Sneakers/${shoe.title}.jpg`);

  return (
    <div className='popular-item-container'>
      <img src={shoeImg} alt={shoe.title} />
      <h2>{shoe.name}</h2>
      <b>{shoe.price} руб.</b>
    </div>
  );
}

export default Item;
