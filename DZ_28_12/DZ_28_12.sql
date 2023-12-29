use Academy;

create table Departments(
    Id int not null primary key identity (1,1),
    Name nvarchar(100) not null unique check (Name != ''),
    Financing money not null default (0) check (Financing >= 0),
    FacultyId int not null foreign key references Faculties(Id)
);

create table Faculties(
    Id int not null primary key identity (1,1),
    Name nvarchar(100) not null unique check (Name != ''),
);

create table Groups(
    Id int not null primary key identity (1,1),
    Name nvarchar(10) not null unique check (Name != ''),
    Year int not null check (Year <= 5 and Year >= 1),
    DepartmentId int not null foreign key references Departments(Id)
);


create table GroupsLectures(
    Id int not null primary key identity (1,1),
    GroupId int not null foreign key references Groups(Id),
    LectureId int not null foreign key references Lectures(Id)
);

create table Lectures(
    Id int not null primary key identity (1,1),
    LectureRoom nvarchar(max) not null check (LectureRoom != ''),
    DayOfWeek int not null check (DayOfWeek >= 1 and DayOfWeek <= 7),
    SubjectId int not null foreign key references Subjects(Id),
    TeacherId int not null foreign key references Teachers(Id)
);

create table Subjects(
    Id int not null primary key identity (1,1),
    Name nvarchar(100) not null unique check (Name != '')
);

create table Teachers(
    Id int not null primary key identity (1,1),
    Name nvarchar(max) not null check (Name != ''),
    Surname nvarchar(max) not null check (Surname != ''),
    Salary money not null check (Salary > 0)
);


INSERT INTO Faculties (Name) VALUES
  ('Computer Science'),
  ('Engineering'),
  ('Software Development');

INSERT INTO Departments (Name, Financing, FacultyId) VALUES
  ('Computer Science Department', 500000, 1),
  ('Engineering Department', 600000, 2),
  ('Software Development', 65000,3);

INSERT INTO Groups (Name, Year, DepartmentId) VALUES
  ('CS101', 3, 1),
  ('ECO201', 5, 3),
  ('ENG301', 2, 1),
  ('MED101', 1, 2),
  ('SS201', 4, 2),
  ('HUM301', 2, 3);

INSERT INTO Subjects (Name) VALUES
  ('Introduction to Programming'),
  ('Mechanical Engineering Basics'),
  ('Programming'),
  ('Web Development'),
  ('Computer Graphics'),
  ('Physics');

INSERT INTO Teachers (Name, Surname, Salary) VALUES
  ('John', 'Doe', 50000),
  ('Alice', 'Smith', 48000),
  ('Bob', 'Johnson', 55000);


INSERT INTO Lectures (LectureRoom, DayOfWeek, SubjectId, TeacherId) VALUES
  ('A101', 2, 2, 1),
  ('B202', 3, 2, 1),
  ('C303', 1, 3, 2),
  ('D404', 5, 1, 3),
  ('E505', 2, 5, 3),
  ('F606', 4, 6, 3);

INSERT INTO GroupsLectures(GroupId, LectureId) VALUES
  (3,4),
  (2,3),
  (1,1),
  (4,2),
  (6,5),
  (5,6);



-- 1. Вывести количество преподавателей кафедры “Software
-- Development”.
select count(TeacherId)
from Lectures
where SubjectId in (select Id from Subjects where Id in (select Id from Departments where Name = 'Software Development'));

-- 2. Вывести количество лекций, которые читает преподаватель
-- “Joh Doe”.
select count(*)
from Lectures
where TeacherId = (select id from Teachers where Name = 'John' and Surname = 'Doe');

-- 3. Вывести количество занятий, проводимых в аудитории
-- “B202”.
select DayOfWeek
from Lectures
where LectureRoom = 'B202'

-- 4. Вывести названия аудиторий и количество лекций, проводимых в них.
select  LectureRoom, DayOfWeek as LectureCount
from Lectures


-- 5. Вывести количество студентов, посещающих лекции преподавателя “Alice Smith”.
SELECT COUNT(DISTINCT GroupId)
FROM GroupsLectures
WHERE LectureId IN (SELECT Id FROM Lectures WHERE TeacherId = (SELECT Id FROM Teachers WHERE Name = 'Alice' AND Surname = 'Smith'));


-- 6. Вывести среднюю ставку преподавателей факультета
-- “Computer Science”.
select avg(Salary) as AverageSalary
from Teachers
WHERE Id IN (SELECT TeacherId FROM Lectures WHERE SubjectId IN (SELECT Id FROM Subjects WHERE Id IN (SELECT Id FROM Departments WHERE FacultyId IN (SELECT Id FROM Faculties WHERE Name = 'Computer Science'))));

-- 7. Вывести минимальное и максимальное количество студентов среди всех групп.
SELECT MIN(StudentsCount) AS MinStudentsCount, MAX(StudentsCount) AS MaxStudentsCount
FROM (SELECT DepartmentId, COUNT(*) AS StudentsCount FROM Groups GROUP BY DepartmentId) AS DepartmentStudentCounts;
-- 8. Вывести средний фонд финансирования кафедр.
SELECT AVG(Financing) AS AverageFinancing
FROM Departments;

-- 9. Вывести полные имена преподавателей и количество читаемых ими дисциплин.
SELECT CONCAT(Name, ' ', Surname) AS FullName, COUNT(*) AS LectureCount
FROM Teachers
JOIN Lectures ON Teachers.Id = Lectures.TeacherId
GROUP BY Teachers.Id, Name, Surname;

-- 10. Вывести количество лекций в каждый день недели.
SELECT DayOfWeek, COUNT(*) AS LectureCount
FROM Lectures
GROUP BY DayOfWeek;

-- 11. Вывести номера аудиторий и количество кафедр, чьи лекции в них читаются.
SELECT LectureRoom, COUNT(DISTINCT Departments.Id) AS DepartmentCount
FROM Lectures
JOIN Subjects ON Lectures.SubjectId = Subjects.Id
JOIN Departments ON Subjects.Id = Departments.Id
GROUP BY LectureRoom;

-- 12.Вывести названия факультетов и количество дисциплин,
-- которые на них читаются.
SELECT Faculties.Name AS FacultyName, COUNT(DISTINCT Subjects.Id) AS SubjectCount
FROM Faculties
JOIN Departments ON Faculties.Id = Departments.FacultyId
JOIN Subjects ON Departments.Id = Subjects.Id
GROUP BY Faculties.Id, Faculties.Name;

-- 13. Вывести количество лекций для каждой пары преподаватель-аудитория
SELECT CONCAT(Teachers.Name, ' ', Teachers.Surname) AS TeacherName, Lectures.LectureRoom, COUNT(*) AS LectureCount
FROM Lectures
JOIN Teachers ON Lectures.TeacherId = Teachers.Id
GROUP BY Teachers.Id, Lectures.LectureRoom;

