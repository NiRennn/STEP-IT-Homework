import "./App.css";
import Catalog from "./components/Catalog/Catalog";
import Footer from "./components/Footer/Footer";
import Header from "./components/Header/Header";
import HomePage from "./components/HomePage/HomePage";
// import shoes from "./ShoesArray";
import { Outlet } from "react-router-dom";

function App() {
  return (
    <div className="App">
      
      {/* <header>
        <Header />
      </header> */}
      <main>
        <Outlet />
        {/* Outlet is used to render nested routes */}
      </main>
      {/* <footer>
        <Footer />
      </footer> */}
    </div>
  );
}

export default App;
