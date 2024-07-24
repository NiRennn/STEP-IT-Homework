import React, { useState } from "react";
import { useParams } from "react-router-dom";
import shoes from "../../ShoesArray";
import "./ProductPage.css";
import Header from "../Header/Header";
import Footer from "../Footer/Footer";

export default function ProductPage() {
  const { title } = useParams();
  const shoe = shoes.find((shoe) => shoe.title === title);
  const [currentImage, setCurrentImage] = useState(0);
  const [liked, setLiked] = useState(false);
  const [selectedSizes, setSelectedSizes] = useState([]);

  if (!shoe) {
    return (
      <div className="product-page">
        <Header />
        <div className="product-container">
          <p>Товар не найден</p>
        </div>
        <Footer />
      </div>
    );
  }

  const handlePrevImage = () => {
    setCurrentImage((prevImage) =>
      prevImage === 0 ? shoe.images.length - 1 : prevImage - 1
    );
  };

  const handleNextImage = () => {
    setCurrentImage((prevImage) =>
      prevImage === shoe.images.length - 1 ? 0 : prevImage + 1
    );
  };

  const handleSizeClick = (size) => {
    if (shoe.sizes.includes(size)) {
      setSelectedSizes((prevSizes) =>
        prevSizes.includes(size)
          ? prevSizes.filter((s) => s !== size)
          : [...prevSizes, size]
      );
    }
  };

  const handleLikeClick = (e) => {
    e.preventDefault();
    setLiked((prevLiked) => !prevLiked);
  };

  const allSizes = Array.from({ length: 15 }, (_, i) => i + 35);

  const similarShoes = shoes
    .filter((s) => s.brand === shoe.brand && s.title !== shoe.title)
    .slice(0, 4);

  return (
    <div className="product-page">
      <Header />
      <div className="product-page-top">
        <div className="container-for-something"></div>
        <div className="product-container">
          <div className="product-gallery">
            <div className="product-gallery-all-images">
              {shoe.images.map((image, index) => (
                <img
                  key={index}
                  src={require(`../../Sneakers/${image}`)}
                  alt={image}
                  className={`all-images ${
                    currentImage === index ? "active" : ""
                  }`}
                  onClick={() => setCurrentImage(index)}
                />
              ))}
            </div>
            <div className="main-image-container">
              <div className="arrow left-arrow" onClick={handlePrevImage}>
                &lt;
              </div>
              <img
                src={require(`../../Sneakers/${shoe.images[currentImage]}`)}
                alt={shoe.name}
                className="main-image"
              />
              <div className="arrow right-arrow" onClick={handleNextImage}>
                &gt;
              </div>
            </div>
          </div>
          <div className="product-information">
            <h2>
              {shoe.gender === "Male"
                ? "Мужские "
                : shoe.gender === "Female"
                ? "Женские "
                : "Детские "}
              {shoe.name}
            </h2>
            <h>Артикул {shoe.article}</h>
            <h>Цвет: {shoe.color}</h>
            <h2>{shoe.price} руб.</h2>
            <h>Выберите размер</h>
            <div className="sizes-container">
              {allSizes.map((size) => (
                <span
                  key={size}
                  className={`size ${
                    shoe.sizes.includes(size)
                      ? selectedSizes.includes(size)
                        ? "available active"
                        : "available"
                      : "unavailable"
                  }`}
                  onClick={() => handleSizeClick(size)}
                >
                  {size}
                </span>
              ))}
            </div>

            <div className="buy-cart-container">
              <button className="add-to-cart-button">Добавить к заказу</button>
              <button className="fast-buy-button">Быстрый заказ</button>
              <button
                className="product-page-like-button"
                onClick={handleLikeClick}
              >
                <svg
                  xmlns="http://www.w3.org/2000/svg"
                  viewBox="0 0 24 24"
                  width="24px"
                  height="24px"
                  fill={liked ? "red" : "black"}
                >
                  <path d="M12 21.35l-1.45-1.32C5.4 15.36 2 12.28 2 8.5 2 5.42 4.42 3 7.5 3c1.74 0 3.41.81 4.5 2.09C13.09 3.81 14.76 3 16.5 3 19.58 3 22 5.42 22 8.5c0 3.78-3.4 6.86-8.55 11.54L12 21.35z" />
                </svg>
              </button>
            </div>
          </div>
        </div>
      </div>
      <hr className="break-line"></hr>
      <div className="product-page-mid">
        <div className="product-description">
          <h2>Описание товара</h2>
          <h className="desc">{shoe.description}</h>
          <div className="peculiarities-compound">
            <div className="peculiarities">
              <h3>Особенности</h3>
              {shoe.peculiarities.map((peculiarities, index) => (
                <li key={index}>{peculiarities}</li>
              ))}
            </div>
            <div className="compound">
              <h3>Состав</h3>
              <h>{shoe.materials}</h>
            </div>
          </div>
        </div>
      </div>
      <hr className="break-line"></hr>
      <div className="similar-products">
        <h3>Похожие модели</h3>
        <div className="similar-products-container">
          {/* <div className="similar-left-arrow"></div> */}
          {similarShoes.map((similarShoe) => (
            <div className="similar-product-item" key={similarShoe.id}>
              <img
                src={require(`../../Sneakers/${similarShoe.images[0]}`)}
                alt={similarShoe.name}
                className="similar-product-image"
              />
              <div className="similar-product-info">
                <p>{similarShoe.price} руб.</p>
                <h>{similarShoe.name}</h>
              </div>
            </div>
          ))}
          {/* <div className="similar-right-arrow"></div> */}
        </div>
      </div>
      <Footer />
    </div>
  );
}
