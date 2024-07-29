import React from "react";
import Item from "./Item";
import "./PopularNow.css";
import shoes from "../../ShoesArray";
import { Link } from "react-router-dom";

const PopularNow = () => {
  const popularShoes = shoes.sort((a, b) => b.rating - a.rating).slice(0, 4);

  return (
    <div className="popular-now-container">
      {popularShoes.map((shoe) => (
        // <Link to={`/product/${shoe.title}`}>
          <Item key={shoe.id} shoe={shoe} />
        // </Link>
      ))}
    </div>
  );
};

export default PopularNow;
