import React from "react";
import ReactDOM from "react-dom/client";
import "./index.css";
import App from "./App";
import { createBrowserRouter, RouterProvider } from "react-router-dom";
import Routes from "./Routes";
import { FavoritesProvider } from './contexts/FavoritesContext';
import { UserProvider } from './contexts/UserContext';

const router = createBrowserRouter(Routes);

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(
  <FavoritesProvider>
    <UserProvider>
      <RouterProvider router={router} />
    </UserProvider>
  </FavoritesProvider>
);
