
create database Academy2;
use Academy2;
go;

create table Departments(
    Id int not null primary key identity (1,1),
    Financing money not null default(0) check(Financing > 0),
    Name nvarchar(max) not null check (Name != '')
);

create table Faculties(
    Id int not null primary key identity (1,1),
    Dean nvarchar(max) not null check (Dean != ''),
    Name nvarchar(100) not null unique check (Name != '')
);

create table Groups(
    Id int not null primary key identity (1,1),
    Name nvarchar(10) not null unique check (Name != ''),
    Rating int not null check (Rating >= 0 and Rating <= 5),
    Year int not null check (Year >= 1 and Year <= 5)
);

create table Teachers(
    Id int not null primary key identity (1,1),
    EmploymentDate date not null check (EmploymentDate >= '1990-01-01'),
    IsAssistant bit not null default (0),
    IsProfessor bit not null default (0),
    Name nvarchar(max) not null check (Name <> ''),
    Surname nvarchar(max) not null check (Surname <> ''),
    Position nvarchar(max) not null check (Position <> ''),
    Premium money not null default (0) check (Premium >= 0),
    Salary money not null check (Salary > 0)
);

insert into Departments(Financing, Name)
values
     (10000, 'Mathematics'),
    (15000, 'Physics'),
    (12000, 'Chemistry'),
    (18000, 'Biology'),
    (20000, 'Computer Science'),
    (13000, 'History'),
    (16000, 'Literature'),
    (22000, 'Economics'),
    (17000, 'Psychology'),
    (19000, 'Sociology');


insert into Faculties(Dean, Name)
values
    ('Dr. Smith', 'Science'),
    ('Prof. Johnson', 'Arts'),
    ('Dr. Williams', 'Engineering'),
    ('Prof. Davis', 'Social Sciences'),
    ('Dr. Wilson', 'Business');


insert into Groups(Name, Rating, Year)
values
    ('Group1', 4, 1),
    ('Group2', 3, 2),
    ('Group3', 5, 3),
    ('Group4', 2, 4),
    ('Group5', 4, 1),
    ('Group6', 3, 2),
    ('Group7', 5, 3),
    ('Group8', 2, 4),
    ('Group9', 4, 1),
    ('Group10', 3, 2),
    ('Group11', 5, 3),
    ('Group12', 2, 4),
    ('Group13', 4, 1),
    ('Group14', 3, 2),
    ('Group15', 5, 3),
    ('Group16', 2, 4),
    ('Group17', 4, 1),
    ('Group18', 3, 2),
    ('Group19', 5, 3),
    ('Group20', 2, 4);



insert into Teachers (EmploymentDate, IsAssistant, IsProfessor, Name, Surname, Position, Premium, Salary)
values
    ('1995-03-15', 1, 0, 'John', 'Doe', 'Assistant Professor', 500, 3000),
    ('2000-06-22', 0, 1, 'Jane', 'Smith', 'Professor', 1000, 5000),
    ('1998-11-10', 1, 0, 'Michael', 'Johnson', 'Assistant Professor', 600, 3500),
    ('2005-02-28', 0, 1, 'Emily', 'Brown', 'Professor', 1200, 6000),
    ('1993-08-17', 0, 1, 'David', 'Miller', 'Professor', 1100, 5500),
    ('2008-04-03', 1, 0, 'Sophia', 'Wilson', 'Assistant Professor', 550, 3200),
    ('1997-09-25', 0, 0, 'Daniel', 'Anderson', 'Lecturer', 400, 2500),
    ('2003-07-12', 0, 1, 'Olivia', 'Thompson', 'Professor', 1300, 6500),
    ('1999-05-08', 1, 0, 'William', 'Clark', 'Assistant Professor', 700, 3800),
    ('2007-01-19', 0, 0, 'Ava', 'Garcia', 'Lecturer', 450, 2700),
    ('1994-12-04', 0, 1, 'James', 'Moore', 'Professor', 900, 4500),
    ('2004-10-31', 1, 0, 'Isabella', 'Hall', 'Assistant Professor', 600, 3500);

-- 1.
select * from Departments order by Id DESC;
-- 2.
select Name as "Group Name" , Rating as "Group Rating" from Groups;
-- 3.
select
    Surname,
    CONVERT(NVARCHAR(10), (Premium / Salary) * 100) AS "Percentage of Premium",
    CONVERT(NVARCHAR(10), ((Salary + Premium) / Salary) * 100) AS "Percentage of Total Salary"
from Teachers;
-- 4.
select
    'The dean of faculty ' + Name + ' is ' + Dean as FacultyDeanInfo
from Faculties;
-- 5.
select Surname
from Teachers
where IsProfessor = 1 and Salary > 1050;
-- 6.
select Name
from Departments
where Financing < 11000 or Financing > 25000;
-- 7.
select Name
from Faculties
where Name <> 'Social Sciences';
-- 8.
select Surname, Position
from Teachers
where IsProfessor = 0;
-- 9.
select Surname, Position, Salary, Premium
from Teachers
where IsAssistant = 1 and  Premium > 160 and Premium < 550
-- 10.
select Surname, Salary
from Teachers
where IsAssistant = 1;
-- 11.
select Surname, Position
from Teachers
where EmploymentDate > '2000-01-01'
-- 12.
select Name as 'Name of Department'
from Departments
where Name < 'Psychology'
order by Name;
-- 13.
select Surname
from Teachers
where IsAssistant = 1 and Salary + Premium < 3800;
-- 14.
select Name
from Groups
where Year = 5 and Rating >= 2 and Rating <= 4;
-- 15.
select Surname
from Teachers
where IsAssistant = 1 and (Salary < 550 or Premium < 200)