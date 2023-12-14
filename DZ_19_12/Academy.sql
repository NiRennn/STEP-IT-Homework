create database Academy;

use Academy;

create table Teachers(
    Id int not null primary key identity (1,1),
    Name nvarchar(max),
    Surname nvarchar(max) not null check(Surname != ''),
    Salary money not null check(Salary > 0),
    Premium  money not null default(0) check(Premium>= 0),
    EmploymentDate date not null check ('01-01-1990' < EmploymentDate)

);

create table Groups(
    Id int primary key identity (1,1),
    Name nvarchar(10) not null unique ,
    Rating int not null check (Rating >= 1 and Rating <= 5),
    Year int not null check (Year >= 1 and Year <= 5)
);

create table Departments(
    Id int not null primary key identity (1,1),
    Financing money not null default(0) check (Financing >= 0),
    Name nvarchar(100) not null unique check (Name != '')
);

create table Faculties(
    Id int primary key not null identity (1,1),
    Name nvarchar(100) not null unique check (Name != '')
);

