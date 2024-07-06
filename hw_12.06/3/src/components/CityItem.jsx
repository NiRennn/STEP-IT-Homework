import React from 'react';

const CityItem = ({ city, onSelectCity }) => {
  return (
    <div className="city-item" onClick={() => onSelectCity(city)}>
      <h3>{city.name}</h3>
    </div>
  );
};

export default CityItem;
