import React, { useState } from "react";
import "./CatalogList.css";
import shoes from "../../ShoesArray";
import redLikeFill from "../../Logos/red-like-fill.svg";
import redLike from "../../Logos/red-like.svg";
import blackLike from "../../Logos/black-like.svg";
import { Link } from "react-router-dom";

const sortOptions = [
  { value: "price-asc", label: "По возр. цены" },
  { value: "price-desc", label: "По убыв. цены" },
  { value: "popularity", label: "Популярные" },
];



export default function CatalogList() {

  
  const [sort, setSort] = useState(sortOptions[0].value);
  const [liked, setLiked] = useState({});

  const handleSortChange = (event) => {
    setSort(event.target.value);
  };

  const handleLikeClick = (id) => {
    setLiked((prevLiked) => ({
      ...prevLiked,
      [id]: !prevLiked[id],
    }));
  };
 
  return (
    <div className="list-container">
      <div className="sort-by">
        <h>Сортировать по:</h>
        <select
          className="sort-select"
          value={sort}
          onChange={handleSortChange}
        >
          {sortOptions.map((option) => (
            <option key={option.value} value={option.value}>
              {option.label}
            </option>
          ))}
        </select>
      </div>
      <div className="shoes-list">
        {shoes.map((shoe) => (
          <Link
            key={shoe.id}
            to={`/product/${shoe.title}`}
            className="card"
          >
            <div className="image-container">
              <img
                src={require(`../../Sneakers/${shoe.title}.jpg`)}
                alt={shoe.name}
              />
              <button
                className={`like-button ${liked[shoe.id] ? "liked" : ""}`}
                onClick={(e) => {
                  handleLikeClick(shoe.id);
                }}
              >
                <img
                  src={liked[shoe.id] ? redLikeFill : blackLike}
                  alt="like"
                />
              </button>
            </div>
            <div className="card-information">
            <p className="card-brand">{shoe.brand}</p>
            <h3 className="card-shoe-gender">
              {shoe.gender === "Male"
                ? "Мужские "
                : shoe.gender === "Female"
                ? "Женские "
                : "Детские "}
              {shoe.name}
            </h3>
            <p className="card-price">{shoe.price} ₽</p>
            </div>

          </Link>
        ))}
      </div>
    </div>
  );
}
