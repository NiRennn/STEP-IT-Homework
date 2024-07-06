import React, { useState } from 'react';
import CityList from './components/CityList';
import CityDetails from './components/CityDetails';
import './App.css';

const App = () => {
  const [cities] = useState([
    {
      id: 1,
      name: 'Москва',
      description: 'Столица России',
      coatOfArms: 'https://upload.wikimedia.org/wikipedia/commons/thumb/1/17/Coat_of_arms_of_Moscow.svg/200px-Coat_of_arms_of_Moscow.svg.png',
      population: '13 149 803',
      area: 2561
    },
    {
      id: 2,
      name: 'Санкт-Петербург',
      description: 'Культурная столица России',
      coatOfArms: 'https://upload.wikimedia.org/wikipedia/commons/thumb/0/07/Coat_of_Arms_of_Saint_Petersburg_%282003%29.svg/200px-Coat_of_Arms_of_Saint_Petersburg_%282003%29.svg.png',
      population: '5 597 763',
      area: 1439
    },
    {
      id: 3,
      name: 'Баку',
      description: 'Столица Азербайджана',
      coatOfArms: 'https://upload.wikimedia.org/wikipedia/commons/thumb/b/bd/Coat_of_arms_of_Baku.svg/90px-Coat_of_arms_of_Baku.svg.png',
      population: '2 303 325',
      area: 2140
    },
    {
      id: 4,
      name: 'Тбилиси',
      description: 'Столица Грузии',
      coatOfArms: 'https://upload.wikimedia.org/wikipedia/commons/thumb/4/4f/Seal_of_Tbilisi%2C_Georgia.svg/90px-Seal_of_Tbilisi%2C_Georgia.svg.png',
      population: '1 172 010',
      area: 720
    },
  ]);

  const [selectedCity, setSelectedCity] = useState(null);

  return (
    <div className="app">
      <h1>Информация о городах России</h1>
      <CityList cities={cities} onSelectCity={setSelectedCity} />
      <CityDetails city={selectedCity} />
    </div>
  );
};

export default App;
