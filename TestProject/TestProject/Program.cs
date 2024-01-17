
using System.Data.SqlClient;
using Microsoft.Extensions.Configuration;

var builder = new ConfigurationBuilder();
builder.AddJsonFile("appsettings.json");

var config = builder.Build();

using SqlConnection conn = new(config.GetConnectionString("Default"));

conn.Open();

var command = new SqlCommand("SELECT count(*) from Teachers", conn);

int result = (int)command.ExecuteScalar();

Console.WriteLine(result);

var command = new SqlCommand("SELECT count(*) from Departments where Financing > 400000", conn);

int result = (int)command.ExecuteScalar();

Console.WriteLine(result);

var command = new SqlCommand("SELECT count(*) from Groups where Year > 2", conn);

int result = (int)command.ExecuteScalar();

Console.WriteLine(result);

var command = new SqlCommand("insert into Teachers(Name,Surname,Salary) values('Elvin','Azimov',49000)",conn);

int rows = command.ExecuteNonQuery();

Console.WriteLine(rows);

var command = new SqlCommand("insert into Teachers(Name,Surname,Salary) values('Elvin','Azimov',49000)",conn);

int rows = command.ExecuteNonQuery();

Console.WriteLine(rows);