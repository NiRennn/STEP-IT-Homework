import "./App.css";

const Login = () => {
  return (
    <div className="Login-container">
      <div className="Login-container-items">
        <p>Log In</p>
        <input Type="username" placeHolder="Username"></input>
        <input Type="password" placeHolder="Password"></input>
        <button className="login-button">Log In</button>
      </div>
    </div>
  );
};



export default Login;