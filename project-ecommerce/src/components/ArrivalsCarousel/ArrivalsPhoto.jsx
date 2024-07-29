import React from 'react';
import './ArrivalsPhoto.css';
import nikeDunkLowImage from '../HomeImages/nike-dunk-low-orange.jpeg';

const ArrivalsPhoto = () => {
  return (
    <div className="arrivals-image">
      <img src={nikeDunkLowImage} alt="Nike Dunk Low" />
    </div>
  );
};


export default ArrivalsPhoto;
