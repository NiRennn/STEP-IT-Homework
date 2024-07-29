import React from 'react';
import './BrandsCarousel.css'

const BrandsCarousel = () => {
  return (
    <div className="brand-carousel-container">
      <div className="brand-carousel-slides">
        <img
          src={require("../../swiper-images/Adidas_Logo.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/Air-Jordan-Jumpman-logo.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/converse-new1270.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/new-balance.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/Vans-Logo-1966.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/Reebok_2019_logo.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/under-armour-logo.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/puma-logo-logo.svg").default}
          alt="Favorites"
        />
      </div>
      <div className="brand-carousel-slides">
        <img
          src={require("../../swiper-images/Adidas_Logo.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/Air-Jordan-Jumpman-logo.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/converse-new1270.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/new-balance.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/Vans-Logo-1966.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/Reebok_2019_logo.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/under-armour-logo.svg").default}
          alt="Favorites"
        />
        <img
          src={require("../../swiper-images/puma-logo-logo.svg").default}
          alt="Favorites"
        />
      </div>
    </div>
  );
};

export default BrandsCarousel;
