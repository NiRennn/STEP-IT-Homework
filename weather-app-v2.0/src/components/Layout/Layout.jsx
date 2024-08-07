import { useState } from "react";
import { WeatherComp } from "../WeatherComp/WeatherComp";
import "./Layout.css";
import axios from "axios";

export const Layout = () => {
  const [location, setLocation] = useState('');
  const [results, setResults] = useState([]);
  const [error, setError] = useState("");

  const apiKey = "e93c7b4d4ae968ac01cfe1d59c137011";

  const getResponse = () => {
    if (!location) {
      setError("Please enter a city name.");
      return;
    }

    const url = `https://api.openweathermap.org/data/2.5/weather?q=${location}&appid=${apiKey}`;

    axios
      .get(url)
      .then((response) => {
        setResults([...results, response.data]);
        setError("");
        setLocation('');
      })
      .catch((error) => {
        setError("City not found.");
      });

  };

  const removeWeatherCopm = (index) => {
    setResults(results.filter((_,i) => i !== index));
  }

  return (
    <div className="layout-container">
      <div className="input-button">
        <input
          className="city-input"
          placeholder="Enter city"
          type="text"
          value={location}
          onChange={(e) => setLocation(e.target.value)}
        ></input>
        <button className="search-button" onClick={getResponse}>
          Add
        </button>
      </div>
      {error && <div className="error">{error}</div>}

      <div className="wheather-widget-container">
        {results.map((result,index) => (
            <WeatherComp data={result} key={index} onRemove ={() => removeWeatherCopm(index)}/>
        ))}
      </div>
    </div>
  );
};
