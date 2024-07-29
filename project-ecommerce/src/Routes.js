import News from "./components/News/News";
import Catalog from "./components/Catalog/Catalog";
import HomePage from "./components/HomePage/HomePage";
import Login from "./components/Login/Login";
import ProductPage from "./components/ProductPage/ProductPage";
import Register from "./components/Register/Register";
import Favorites from "./components/Favorites/Favorites";


const Routes = [
  {
    path: "/",
    element: <HomePage />,
  },
  {
    path: "/home",
    element: <HomePage />,
  },
  {
    path: "/catalog",
    element: <Catalog/>,
  },
  {
    path: "/catalog/:gender",
    element: <Catalog/>,
  },
  {
    path: "/product/:title",
    element: <ProductPage/>,
  },
  {
    path: "/news",
    element: <News/>
  },
  {
    path: "/favorites",
    element: <Favorites/>
  }


];



export default Routes;