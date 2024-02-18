using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace TrendyolApp.Migrations
{
    /// <inheritdoc />
    public partial class Fourth : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "UserId",
                table: "WarehouseInfo");

            migrationBuilder.CreateIndex(
                name: "IX_WarehouseInfo_ProductId",
                table: "WarehouseInfo",
                column: "ProductId");

            migrationBuilder.AddForeignKey(
                name: "FK_WarehouseInfo_Products_ProductId",
                table: "WarehouseInfo",
                column: "ProductId",
                principalTable: "Products",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_WarehouseInfo_Products_ProductId",
                table: "WarehouseInfo");

            migrationBuilder.DropIndex(
                name: "IX_WarehouseInfo_ProductId",
                table: "WarehouseInfo");

            migrationBuilder.AddColumn<int>(
                name: "UserId",
                table: "WarehouseInfo",
                type: "int",
                nullable: false,
                defaultValue: 0);
        }
    }
}
