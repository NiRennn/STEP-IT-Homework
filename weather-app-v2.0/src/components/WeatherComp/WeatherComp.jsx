import "./WeatherComp.css";
import React from "react";

export const WeatherComp = ({ data, onRemove }) => {
  return (
    <>
      <div className="weather-widget">
        <div className="image-section">
          {/* <button className="delete-button" onClick={onRemove}>x</button> */}
          <img
            src={`https://openweathermap.org/img/wn/${data.weather[0].icon}@2x.png`}
            alt="weather-img"
          />
          <p>{data.weather[0].description}</p>
        </div>
        <div className="info-section">
          <h3>{data.name}</h3>
          <p>{Math.round(data.main.temp - 273.15)}°C</p>
          <p>Humidity: {data.main.humidity}%</p>
          <p>Feels like: {Math.round(data.main.feels_like - 273.15)}°C</p>
        </div>
      </div>
    </>
  );
};
