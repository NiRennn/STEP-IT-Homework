CREATE DATABASE Ecommerce;
GO;
USE Ecommerce;

CREATE TABLE Cars (
    Id INT PRIMARY KEY IDENTITY (1,1),
    Brand NVARCHAR(50) NOT NULL,
    Model NVARCHAR(50) NOT NULL ,
    Year INT NOT NULL ,
    FuelTypeId INT NOT NULL ,
    BodyTypeId INT NOT NULL ,
    ColorId INT NOT NULL ,
    ImageLink NVARCHAR(MAX),
    FOREIGN KEY (FuelTypeId) REFERENCES FuelTypes(Id),
    FOREIGN KEY (BodyTypeId) REFERENCES BodyTypes(Id),
    FOREIGN KEY (ColorId) REFERENCES Colors(Id)
);

CREATE TABLE Users (
    Id INT PRIMARY KEY IDENTITY (1,1),
    username NVARCHAR(15) NOT NULL,
    password NVARCHAR(20) NOT NULL,
    email  NVARCHAR(50) NOT NULL
);

CREATE TABLE ProductList (
    Id INT PRIMARY KEY IDENTITY (1,1),
    CarId INT NOT NULL,
    SellerId INT NOT NULL,
    Price DECIMAL NOT NULL,
    Quantity INT,
    FOREIGN KEY (CarId) REFERENCES Cars(Id),
    FOREIGN KEY (SellerId) REFERENCES Sellers(Id)
);

CREATE TABLE ManufacturingCountries (
    Id INT PRIMARY KEY IDENTITY (1,1),
    CountryName VARCHAR(50)
);

CREATE TABLE FuelTypes (
    Id INT PRIMARY KEY IDENTITY (1,1),
    FuelType VARCHAR(50)
);

CREATE TABLE BodyTypes (
    Id INT PRIMARY KEY IDENTITY (1,1),
    BodyType VARCHAR(50)
);

CREATE TABLE Colors (
    Id INT PRIMARY KEY IDENTITY (1,1),
    ColorName VARCHAR(50)
);

CREATE TABLE Sellers (
    Id INT PRIMARY KEY IDENTITY (1,1),
    UserId INT,
    CompanyName VARCHAR(50),
    ContactNumber VARCHAR(20),
    CountryId INT,
    Rating INT,
    FOREIGN KEY (UserId) REFERENCES Users(Id),
    FOREIGN KEY (CountryId) REFERENCES ManufacturingCountries(Id)
);