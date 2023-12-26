use Academy;


create table Curators(
    Id int not null primary key identity (1,1),
    Name nvarchar(max) not null check (Name != ''),
    Surname nvarchar(max) not null check (Surname != '')
);

create table Departments(
    Id int not null primary key identity (1,1),
    Financing money not null default (0) check (Financing >= 0),
    Name nvarchar(100) not null unique check (Name != ''),
    FacultyId int not null foreign key references Faculties(Id)
);

create table Faculties(
    Id int not null primary key identity (1,1),
    Financing money not null default (0) check (Financing >= 0),
    Name nvarchar(100) not null unique check (Name != '')
);


create table Groups(
    Id int not null primary key identity (1,1),
    Name nvarchar(10) not null unique check (Name != ''),
    Year int not null check (Year <= 5 and Year >= 1),
    DepartmentId int not null foreign key references Departments(Id)
);

create table GroupsCurators(
    Id int not null primary key identity (1,1),
    CuratorId int not null foreign key references Curators(Id),
    GroupId int not null foreign key references Groups(Id)
);

create table GroupsLectures(
    Id int not null primary key identity (1,1),
    GroupId int not null foreign key references Groups(Id),
    LectureId int not null foreign key references Lectures(Id)
);

create table Lectures(
    Id int not null primary key identity (1,1),
    LectureRoom nvarchar(max) not null check (LectureRoom != ''),
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

INSERT INTO Curators (Name, Surname) VALUES
('John', 'Doe'),
('Alice', 'Johnson'),
('Bob', 'Smith'),
('Elena', 'Petrova'),
('Michael', 'Brown');

INSERT INTO Departments (Financing, Name, FacultyId) VALUES
(50000, 'Computer Science', 1),
(60000, 'Economics', 2),
(70000, 'Mathematics', 3),
(80000, 'Physics', 4),
(90000, 'Biology', 1);

INSERT INTO Faculties (Financing, Name) VALUES
(100000, 'Engineering'),
(110000, 'Social Sciences'),
(120000, 'Natural Sciences'),
(130000, 'Medical Sciences'),
(140000, 'Arts and Humanities');

INSERT INTO Groups (Name, Year, DepartmentId) VALUES
('G101', 1, 1),
('G201', 2, 2),
('G301', 3, 3),
('G401', 4, 4),
('G501', 5, 5);

INSERT INTO GroupsCurators (CuratorId, GroupId) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5);

INSERT INTO GroupsLectures (GroupId, LectureId) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5);

INSERT INTO Lectures (LectureRoom, SubjectId, TeacherId) VALUES
('Room101', 1, 1),
('Room201', 2, 2),
('Room301', 3, 3),
('Room401', 4, 4),
('Room501', 5, 5);

INSERT INTO Subjects (Name) VALUES
('Database Management'),
('Economics Principles'),
('Calculus'),
('Quantum Physics'),
('Genetics');

INSERT INTO Teachers (Name, Salary, Surname) VALUES
('John', 50000, 'Doe'),
('Alice', 60000, 'Johnson'),
('Bob', 70000, 'Smith'),
('Elena', 80000, 'Petrova'),
('Michael', 90000, 'Brown');




-- 1. Вывести все возможные пары строк преподавателей и групп.
select Teachers.*, Groups.*
from Teachers
cross join Groups

-- 2. Вывести названия факультетов, фонд финансирования
-- кафедр которых превышает фонд финансирования факультета.
select distinct F1.Name AS FacultyName
from Faculties F1
join Departments D ON F1.Id = D.FacultyId
join Faculties F2 ON D.Financing > F2.Financing


-- 3. Вывести фамилии кураторов групп и названия групп, которые они курируют.
select C.Surname as CuratorsSurname, G.Name as GroupName
from Curators C join GroupsCurators GC
on C.Id = GC.CuratorId
join Groups G
on GC.GroupId = G.Id


-- 4. Вывести имена и фамилии преподавателей, которые читают
-- лекции у группы “G301”.
select T.Name as TeacherName, T.Surname as TeacherSurname
from Teachers T
join Lectures L on T.Id = L.TeacherId
join GroupsLectures GL on L.Id = GL.LectureId
join Groups G on GL.GroupId = G.Id
where G.Name = N'G301'


-- 5. Вывести фамилии преподавателей и названия факультетов
-- на которых они читают лекции.
select distinct  T.Surname, F.Name as FacultyName
from Teachers T
join Lectures L on T.Id = L.TeacherId
join Subjects S on L.SubjectId = S.Id
join Departments D on S.Id = D.FacultyId
join Faculties F on D.FacultyId = F.Id;

-- 6. Вывести названия кафедр и названия групп, которые к
-- ним относятся.
select D.Name, G.Name as GroupName
from Departments D
join Groups G on D.Id = G.DepartmentId

-- 7. Вывести названия дисциплин, которые читает преподаватель “Bob Smith”.
select S.Name as SubjectName
from Teachers T
join Lectures L on T.Id = L.SubjectId
join Subjects S on L.SubjectId = S.Id
where T.Name =  N'Bob' and T.Surname = N'Smith'

-- 8. Вывести названия кафедр, на которых читается дисциплина
-- “Economics Principles”.
select D.Name as DepartmentName
from Subjects S
join Lectures L on S.Id = L.SubjectId
join GroupsLectures GL on L.Id = GL.LectureId
join Groups G on GL.GroupId = G.Id
join Departments D on D.Id = G.DepartmentId
where S.Name = N'Economics Principles'

-- 9. Вывести названия групп, которые относятся к факультету
-- “Medical Sciences”.
select G.Name as GroupName
from Groups G
join Departments D on G.DepartmentId = D.Id
join Faculties F on D.FacultyId = F.Id
where F.Name = N'Medical Sciences'

-- 10. Вывести названия групп 5-го курса, а также название факультетов, к которым они относятся.
select G.Name as GroupName
from Groups G
join Departments D on G.DepartmentId = D.Id
join Faculties F on D.FacultyId = F.Id
where G.Year = 5

-- 11. Вывести полные имена преподавателей и лекции, которые
-- они читают (названия дисциплин и групп), причем отобрать
-- только те лекции, которые читаются в аудитории “Room301”
select T.Name as TeacherName, T.Surname as TeacherSurname, S.Name as SubjectName, G.Name as GroupName
from Teachers T
join Lectures L on T.Id = L.TeacherId
join GroupsLectures GL on L.Id = GL.LectureId
join Groups G on GL.GroupId = G.Id
join Subjects S on L.SubjectId = S.Id
where L.LectureRoom = N'Room301'

