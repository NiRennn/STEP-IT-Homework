using Microsoft.Extensions.Configuration;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DataTableLesson
{
    public partial class MainWindow : Form
    {
        private SqlConnection conn;
        private SqlDataAdapter adapter;
        private DataSet ds;

        public MainWindow()
        {
            InitializeComponent();

            var builder = new ConfigurationBuilder();
            builder.AddUserSecrets<MainWindow>();

            var config = builder.Build();

            var connectionString = config["Default"];

            conn = new SqlConnection(connectionString);

            conn.Open();
        }

        private void UpdateTablesList()
        {
            using SqlCommand cmd = new SqlCommand("select [name] from sys.tables", conn);
            using SqlDataReader reader = cmd.ExecuteReader();

            while (reader.Read())
            {
                tablesBox.Items.Add(reader["name"]);
            }
        }

        private void MainWindow_Load(object sender, EventArgs e)
        {
            UpdateTablesList();
        }

        private void getAllDatabtn_Click(object sender, EventArgs e)
        {
            if (tablesBox.SelectedItem == null)
            {
                MessageBox.Show("Select table first", "ERROR!!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            adapter = new SqlDataAdapter($"select * from {tablesBox.SelectedItem.ToString()}", conn);

            ds = new DataSet();
            adapter.Fill(ds);

            dbDataGridView.DataSource = ds.Tables[0];
        }

        private void SaveBtn_Click(object sender, EventArgs e)
        {
            using SqlCommandBuilder builder = new SqlCommandBuilder(adapter);

            DataTable table = (DataTable)dbDataGridView.DataSource;

            adapter.Update(table);
        }

        private void deleteBtn_Click(object sender, EventArgs e)
        {
            if (dbDataGridView.SelectedRows.Count > 0)
            {
                DataGridViewRow selectedRow = dbDataGridView.SelectedRows[0];

                ds.Tables[0].Rows.Remove(((DataRowView)selectedRow.DataBoundItem).Row);

                dbDataGridView.DataSource = ds.Tables[0];
            }
            else
            {
                MessageBox.Show("Select a row first", "ERROR!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }



}


