import './App.css';


const Registration = () => {
    return (
      <div className="Login-container">
        <div className="Login-container-items">
          <p>Register</p>
          <input Type="username" placeHolder="Username"></input>
          <input Type="email" placeHolder="Email" ></input>
  
          <input Type="password" placeHolder="Password"></input>
          <button className="register-button">Register</button>
        </div>
      </div>
    );
  };


  export default Registration;