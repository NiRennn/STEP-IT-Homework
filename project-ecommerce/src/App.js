import React from 'react';
import { Outlet } from 'react-router-dom';
import { UserProvider } from './contexts/UserContext'; // Импортируем UserProvider
import './App.css';

function App() {
  return (
    <UserProvider>
      <div className="App">
        <main>
          <Outlet />
        </main>
      </div>
    </UserProvider>
  );
}

export default App;
