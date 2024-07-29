import React from "react";
import "./GenderSelection.css";
import { Link } from "react-router-dom";

const GenderSelection = () => {
  return (
    <div className="container-gender-selection">
      <Link to={`/catalog`}>
        <div className="container-gender-selection-item">
          <img
            src="https://static.street-beat.ru/upload/resize_cache/iblock/c1a/420_500_1/7dryv4b9evwtymen1t1r1gjb00ju72rj.jpg"
            alt="Мужчинам"
          />
          <div className="container-gender-selection-item-text">Мужчинам</div>
        </div>
      </Link>

      <Link to={`/catalog`}>
        <div className="container-gender-selection-item">
          <img
            src="https://static.street-beat.ru/upload/resize_cache/iblock/b74/420_500_1/6gng0q82w5hlc658hcsltjkvwmtjmkik.jpg"
            alt="Женщинам"
          />
          <div className="container-gender-selection-item-text">Женщинам</div>
        </div>
      </Link>
      <Link to={`/catalog`}>
        <div className="container-gender-selection-item">
          <img
            src="https://static.street-beat.ru/upload/resize_cache/iblock/15b/420_500_1/bfojbfsur0am1y3wdan4gjsswdwhtm6v.jpg"
            alt="Детям"
          />
          <div className="container-gender-selection-item-text">Детям</div>
        </div>
      </Link>
    </div>
  );
};

export default GenderSelection;
