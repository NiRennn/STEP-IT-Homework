import React from 'react';
import CityItem from './CityItem';

const CityList = ({ cities, onSelectCity }) => {
  return (
    <div className="city-list">
      {cities.map(city => (
        <CityItem key={city.id} city={city} onSelectCity={onSelectCity} />
      ))}
    </div>
  );
};

export default CityList;
