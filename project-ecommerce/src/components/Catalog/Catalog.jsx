import React, {useState, useEffect} from "react";
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
  });   
  
  // const [filteredShoes, setFilteredShoes] = useState(shoes);

  // useEffect(() => {
  //   const applyFilters = () => {
  //     const filtered = shoes.filter((shoe) => {
  //       const matchesPrice = shoe.price >= filters.price[0] && shoe.price <= filters.price[1];
  //       const matchesBrand = filters.brands.length === 0 || filters.brands.includes(shoe.brand);
  //       const matchesSize = filters.sizes.length === 0 || shoe.sizes.some((size) => filters.sizes.includes(size));
        
  //       return matchesPrice && matchesBrand && matchesSize;
  //     });
  //     setFilteredShoes(filtered);
  //   };

  //   applyFilters();
  // }, [filters]);
  
  return (
    <div className="catalog-container">
      <Header />
      <p className="all-shoes-p">Вся обувь — {shoes.length}</p>

      <div className="filter-list-container">
        <CatalogFilter filters={filters} setFilters={setFilters} />
        <CatalogList filters={filters} />
      </div>
 
      <Footer />
    </div>
  );
}
