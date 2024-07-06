import React from 'react';

const CityDetails = ({ city }) => {
  if (!city) return <p>Выберите город для просмотра подробностей</p>;

  return (
    <div className="city-details">
      <h2>{city.name}</h2>
      <img src={city.coatOfArms} alt={`${city.name} герб`} className="city-coat-of-arms" />
      <p><strong>Описание:</strong> {city.description}</p>
      <p><strong>Количество жителей:</strong> {city.population}</p>
      <p><strong>Площадь:</strong> {city.area} км²</p>
    </div>
  );
};

export default CityDetails;
