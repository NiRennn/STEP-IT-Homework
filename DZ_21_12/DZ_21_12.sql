use Academy;
go;


CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Age INT,
    GPA FLOAT
);

CREATE TABLE Courses (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(50),
    Difficulty INT,
    Credits INT
);

CREATE TABLE Enrollments (
    EnrollmentID INT PRIMARY KEY,
    StudentID INT,
    CourseID INT,
    Grade FLOAT
);

INSERT INTO Students (StudentID, FirstName, LastName, Age, GPA)
VALUES
    (1, N'Иван', N'Иванов', 20, 3.5),
    (2, N'Мария', N'Петрова', 22, 3.8),
    (3, N'Александр', N'Сидоров', 21, 3.2),
    (4, N'Екатерина', N'Козлова', 23, 3.9),
    (5, N'Дмитрий', N'Федоров', 20, 3.0);

INSERT INTO Courses (CourseID, CourseName, Difficulty, Credits)
VALUES
    (101, N'Математика', 4, 3),
    (102, N'Физика', 3, 4),
    (103, N'Литература', 2, 3),
    (104, N'История', 2, 3),
    (105, N'Биология', 3, 4);

INSERT INTO Enrollments (EnrollmentID, StudentID, CourseID, Grade)
VALUES
    (1, 1, 101, 3.7),
    (2, 1, 102, 4.0),
    (3, 2, 101, 3.9),
    (4, 3, 103, 3.5),
    (5, 3, 105, 3.2),
    (6, 4, 102, 3.8),
    (7, 4, 104, 4.0),
    (8, 5, 105, 3.1),
    (9, 5, 101, 3.0);
-- Задание:
-- Средний GPA студентов, записанных на курс "Математика":
-- Вывести средний GPA студентов, которые записаны на курс "Математика" (CourseID = 101).
SELECT AVG(S.GPA) AS AverageGPA
FROM Students S
JOIN Enrollments E ON S.StudentID = E.StudentID
WHERE E.CourseID = 101;
--
-- Максимальный возраст студента, получившего оценку выше 3.5:
-- Найти максимальный возраст студента, который получил оценку выше 3.5.
SELECT MAX(S.Age) AS MaxAge
FROM Students S
JOIN Enrollments E on S.StudentID = E.StudentID
WHERE E.Grade > 3.5;

--
-- Количество курсов с сложностью выше 3:
-- Подсчитать количество курсов с уровнем сложности выше 3.
SELECT COUNT(*) AS CoursesCount
FROM Courses
WHERE Difficulty > 3;

--
-- Самый сложный курс:
-- Найти курс с максимальным уровнем сложности.

SELECT TOP 1 CourseName
FROM Courses
ORDER BY Difficulty DESC;










