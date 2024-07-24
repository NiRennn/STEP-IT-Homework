import Catalog from "./components/Catalog/Catalog";
import HomePage from "./components/HomePage/HomePage";
import ProductPage from "./components/ProductPage/ProductPage";

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
    path: "/product/:title",
    element: <ProductPage/>
  }

];



export default Routes;