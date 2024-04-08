using System.Data;
using System.Data.SqlClient;
using Dapper;
using DapperHW;

var connectionString = "Data Source=localhost;Initial Catalog=Academy; Integrated Security=True;";

using IDbConnection conn = new SqlConnection(connectionString);

var selectSql = "SELECT * FROM Teachers";

var Teachers = conn.Query<Teacher>(selectSql);

foreach (var teacher in Teachers)
{
    Console.WriteLine($"{teacher.Id} {teacher.Name} {teacher.Surname} {teacher.Salary}");
}

var newTeacher = new Teacher
{
    Name = "Роберт",
    Surname = "Братишка",
    Salary = 500
};

var insertSql = "INSERT INTO Teachers (Name, Surname, Salary) VALUES (@Name, @Surname, @Salary);";
conn.Execute(insertSql, newTeacher);

var selectSql = "SELECT * FROM Teachers;";
var teachers = conn.Query<Teacher>(selectSql);

foreach (var teacher in teachers)
{
    Console.WriteLine($"{teacher.Id} {teacher.Name} {teacher.Surname} {teacher.Salary}");
}


var deleteSql = "DELETE FROM Teachers where Name = 'John'";
conn.Execute(deleteSql);

var selectSql = "SELECT * FROM Teachers;";
var teachers = conn.Query<Teacher>(selectSql);

foreach (var teacher in teachers)
{
    Console.WriteLine($"{teacher.Id} {teacher.Name} {teacher.Surname} {teacher.Salary}");
}



var updateSql = "UPDATE Teachers SET Salary = @NewSalary WHERE Name = @TeacherName";

var parameters = new { NewSalary = 5000, TeacherName = "Роберт" };

conn.Execute(updateSql, parameters);

var selectSql = "SELECT * FROM Teachers;";
var teachers = conn.Query<Teacher>(selectSql);

foreach (var teacher in teachers)
{
    Console.WriteLine($"{teacher.Id} {teacher.Name} {teacher.Surname} {teacher.Salary}");
}

