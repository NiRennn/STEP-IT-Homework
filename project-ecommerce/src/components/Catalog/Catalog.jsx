import React, { useState } from "react";
import "./Catalog.css";
import Header from "../Header/Header";
import Footer from "../Footer/Footer";
import shoes from "../../ShoesArray";
import CatalogFilter from "../CatalogFilter/CatalogFilter";
import CatalogList from "../CatalogList/CatalogList";

export default function Catalog() {
  const [filters, setFilters] = useState({
    price: [0, 100000],
    brands: [],
    sizes: [],
    gender: [],
  }); 

  const [activeGender, setActiveGender] = useState(null); 

  const getFilteredShoes = () => {
    return shoes.filter(shoe => {
      const price = parseFloat(shoe.price.replace(/\s/g, ''));
      if (price < filters.price[0] || price > filters.price[1]) {
        return false;
      }
      if (filters.brands.length > 0 && !filters.brands.includes(shoe.brand)) {
        return false;
      }
      if (filters.sizes.length > 0 && !shoe.sizes.some(size => filters.sizes.includes(size.toString()))) {
        return false;
      }
      if (filters.gender.length > 0 && !filters.gender.includes(shoe.gender.toLowerCase())) { 
        return false;
      }
      return true;
    });
  };

  const handleGenderChange = (gender) => {
    setFilters(prevFilters => ({
      ...prevFilters,
      gender: gender ? [gender] : [], 
    }));
    setActiveGender(gender);
  };

  return (
    <div className="catalog-container">
      <Header />
      <p className="all-shoes-p">Вся обувь — {shoes.length}</p>
      <div className="filter-list-container">
        <CatalogFilter
          filters={filters}
          setFilters={setFilters}
          activeGender={activeGender}
          setActiveGender={handleGenderChange}
        />
        <CatalogList filters={filters} shoes={getFilteredShoes()} />
      </div>
      <Footer />
    </div>
  );
}
