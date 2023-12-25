use Academy;
go;


create table People(
[Id] int primary key identity(1, 1),
[Name] nvarchar(30) NOT NULL,
[Surname] nvarchar(30) NOT NULL,
[Age] int NOT NULL check (Age >= 14 and Age < 100)
);


create table Employee(
[Id] int primary key identity(1, 1),
[Salary] smallmoney NOT NULL check ([Salary] >= 300),
[Experience] int NOT NULL check ([Experience] >= 0)
);

create table Faculty(
[Id] int primary key identity(1, 1),
[Name] nvarchar(30) NOT NULL
);

create table Students(
[Id] int primary key identity(1, 1),
[PersonId] int foreign key references People(Id),
GPA int  not null check (GPA <= 12 and GPA >= 1)
);

create table Teachers(
[Id] int primary key identity(1, 1),
[PersonId] int foreign key references People(Id),
[EmployeeId] int foreign key references Employee(Id)
);


create table Groups(
[Id] int primary key identity(1, 1),
[Name] nvarchar(30) NOT NULL,
[Course] int NOT NULL check ([Course] >= 1 and [Course] <= 6),
[FacultyId] int foreign key references Faculty(Id)
);

create table GroupData(
[Id] int primary key identity(1, 1),
[StudentId] int foreign key references Students(Id),
[GroupId] int foreign key references Groups(Id)
);

create table StudyPlan(
[Id] int primary key identity(1, 1),
[TeacherId] int foreign key references Teachers(Id),
[GroupId] int foreign key references Groups(Id)
);



insert into People(Name, Surname, Age) values(N'Elnur', N'Mamedov', 19);
insert into People(Name, Surname, Age) values(N'Kenan', N'Mamedli', 15);
insert into People (Name, Surname, Age) values ('Wheeler', 'Ebbers', 19);
insert into People (Name, Surname, Age) values ('Nanon', 'Delamaine', 24);
insert into People (Name, Surname, Age) values ('Hugibert', 'Bitchener', 30);
insert into People (Name, Surname, Age) values ('Margeaux', 'Duerdin', 32);
insert into People (Name, Surname, Age) values ('Skippy', 'Braunes', 26);
insert into People (Name, Surname, Age) values ('Moshe', 'Prendeguest', 34);
insert into People (Name, Surname, Age) values ('Gonzales', 'Light', 31);
insert into People (Name, Surname, Age) values ('Sibylle', 'Boyett', 22);
insert into People (Name, Surname, Age) values ('Bernadette', 'Vasler', 17);
insert into People (Name, Surname, Age) values ('Andy', 'Crookston', 19);
insert into People (Name, Surname, Age) values ('Ingaborg', 'Blakeden', 29);
insert into People (Name, Surname, Age) values ('Ange', 'Gentsch', 25);
insert into People (Name, Surname, Age) values ('Baily', 'Ragbourn', 19);
insert into People (Name, Surname, Age) values ('Adolphus', 'Been', 23);
insert into People (Name, Surname, Age) values ('Dixie', 'Feacham', 27);


insert into Employee (Salary, Experience) values ('$500', 4);
insert into Employee (Salary, Experience) values ('$670', 6);
insert into Employee (Salary, Experience) values ('$390', 2);

INSERT INTO Faculty (Name) VALUES ('Information Technology');
INSERT INTO Faculty (Name) VALUES ('Economics');
INSERT INTO Faculty (Name) VALUES ('Medicine');
INSERT INTO Faculty (Name) VALUES ('Foreign Languages');


insert into Students(PersonId, GPA) values(1,12);
insert into Students(PersonId, GPA) values(2,11);
insert into Students(PersonId, GPA) values(4,9);
insert into Students(PersonId, GPA) values(5,10);
insert into Students(PersonId, GPA) values(6,8);
insert into Students(PersonId, GPA) values(7,7);
insert into Students(PersonId, GPA) values(9,12);
insert into Students(PersonId, GPA) values(10,11);
insert into Students(PersonId, GPA) values(11,8);
insert into Students(PersonId, GPA) values(12,11);
insert into Students(PersonId, GPA) values(13,9);
insert into Students(PersonId, GPA) values(14,7);
insert into Students(PersonId, GPA) values(15,11);
insert into Students(PersonId, GPA) values(17,12);

DBCC CHECKIDENT ('Students', RESEED, 0);


insert into Teachers(PersonId, EmployeeId) values (3,1);
insert into Teachers(PersonId, EmployeeId) values (8,2);
insert into Teachers(PersonId, EmployeeId) values (16,3);

insert into Groups(Name, Course, FacultyId) values (N'101',1,1);
insert into Groups(Name, Course, FacultyId) values (N'201',2,1);
insert into Groups(Name, Course, FacultyId) values (N'301',3,1);

insert into Groups(Name, Course, FacultyId) values (N'102',1,2);
insert into Groups(Name, Course, FacultyId) values (N'202',2,2);

insert into Groups(Name, Course, FacultyId) values (N'103',1,3);
insert into Groups(Name, Course, FacultyId) values (N'203',2,3);


insert into Groups(Name, Course, FacultyId) values (N'304',3,4);


insert into GroupData (StudentId, GroupId) values (1, 1);
insert into GroupData (StudentId, GroupId) values (2, 5);
insert into GroupData (StudentId, GroupId) values (3, 3);
insert into GroupData (StudentId, GroupId) values (4, 8);
insert into GroupData (StudentId, GroupId) values (5, 2);
insert into GroupData (StudentId, GroupId) values (6, 7);
insert into GroupData (StudentId, GroupId) values (7, 4);
insert into GroupData (StudentId, GroupId) values (8, 7);
insert into GroupData (StudentId, GroupId) values (9, 1);
insert into GroupData (StudentId, GroupId) values (10, 3);
insert into GroupData (StudentId, GroupId) values (11, 4);
insert into GroupData (StudentId, GroupId) values (12, 6);
insert into GroupData (StudentId, GroupId) values (13, 8);
insert into GroupData (StudentId, GroupId) values (14, 2);


insert into StudyPlan (TeacherId, GroupId) values (1,1);
insert into StudyPlan (TeacherId, GroupId) values (1,2);
insert into StudyPlan (TeacherId, GroupId) values (1,3);
insert into StudyPlan (TeacherId, GroupId) values (2,4);
insert into StudyPlan (TeacherId, GroupId) values (2,5);
insert into StudyPlan (TeacherId, GroupId) values (2,6);
insert into StudyPlan (TeacherId, GroupId) values (2,7);
insert into StudyPlan (TeacherId, GroupId) values (3,8);

select * from People;

select * from Students;

select * from Employee;

select * from Faculty;

select * from Teachers;

select *  from Groups;

select * from GroupData;

select * from StudyPlan;






SELECT
    People.Name AS StudentName,
    People.Surname AS StudentSurname,
    People.Age AS StudentAge,
    Students.GPA,
    Groups.Name AS GroupName,
    Groups.Course,
    Faculty.Name AS FacultyName
FROM
    Students
INNER JOIN
    People ON Students.PersonId = People.Id
INNER JOIN
    GroupData ON Students.Id = GroupData.StudentId
INNER JOIN
    Groups ON GroupData.GroupId = Groups.Id
INNER JOIN
    Faculty ON Groups.FacultyId = Faculty.Id

