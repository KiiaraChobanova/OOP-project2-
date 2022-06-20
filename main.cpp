#include "Catalog.h"

int main(){

    // //section for class Column
    // vector<long long int> vect;
    // vect = {-1,2,3,4,5,6,7};
    // Column<long long int> c(vect, "INTEGER");
    // c.getColumn();
    // long long int a = 14;
    // cout << "Cells number is: " << c.getCellsNumber() << "\n";
    // cout << "Column number is: " << c.getColumnNumber() << "\n";
    // cout << "Size of column " << c.getColumnNumber() <<" is: " << c.getSize() << "\n";
    // c.getColumn();
    // c.addCell(a);
    // cout << "Size of column " << c.getColumnNumber() <<" is: " << c.getSize() << "\n";
    // c.getColumn();
    // c.removeCell(9);
    // cout << "Size of column " << c.getColumnNumber() <<" is: " << c.getSize() << "\n";
    // c.getColumn();
    // int id = 2;
    // cout << "\nCell with id = " << id << " is: " << c.cellWithID(id);
    // //end of section for class Column


    // //section for class Table
    // vector<long long int> vect1, vect2, vect3, vect4;
    // vect1 = {-1,2,3};
    // vect2 = {5, 3, 2, 1, 6};
    // vect3 = {111, 222, 333};
    // vect4 = {9,8,7,6};
    // string tableName = "First table";
    // Column<long long int> c1(vect1,"INTEGER"), c2(vect2, "INTEGER");
    // Table<long long int> t({c1, c2}, tableName);
    // t.getTable();
    // cout << t.getTableName() << " is renaming to the ";
    // string secondName = "table number one";
    // t.setName(secondName);
    // cout << t.getTableName() << "..." << "\n";
    // t.getTable();
    // Column<long long int> c3(vect3, "INTEGER");
    // cout << "In this table have: " << t.getColumnsNumber() << " columns\n";
    // t.addColumn(c3);
    // t.getTable();
    // cout << "In this table have: " << t.getColumnsNumber() << " columns\n";
    // t.removeColumn(1);
    // t.getTable();
    // cout << "In this table have: " << t.getColumnsNumber() << " columns\n";
    // cout << "In this table have: " << t.getColumnsNumber() << " columns\n";
    // long long int searchValue = 1;
    // cout << t.count(searchValue);
    // t.insert(vect4);
    // t.getTable();
    // cout << "Type of all columns are: ";
    // t.getTypesOfColumns();
    // cout << "\n" << "Getting whole row... ";
    // t.getWholeRow(2); 
    // cout << "\n";
    // t.getWholeRow(10);
    // cout << "Select operation...\n";
    // t.select(1, 2);
    // //end of section for class Table


    // // section for class Catalog
    // vector<string> vect5;
    // vect5 = {"Kiara", "Kiara"};
    // Column<string> c1(vect5, "STRING");
    // string firstTableName = "First string table";
    // Table<string> t1({c1}, firstTableName);
    // Catalog<string> cat1({t1});
    // cat1.getCatalog();
    // string secondTableName = "second string table";
    // Table<string> t2({c1}, secondTableName);
    // //cout << t2.getTableNumber(); // with 1 more because of first table t
    // cat1.addTable(t2);
    // cat1.getCatalog();
    // cat1.removeTable(2);
    // cat1.getCatalog();
    // cat1.showtables();
    // cat1.describe(firstTableName); 
    // cout << "\n";
    // cat1.describe(secondTableName);
    // cat1.rename(firstTableName, secondTableName);
    // cat1.showtables();
    // cout << "\n";
    // string searchValue = "Kiara";
    // cout << cat1.count(secondTableName, searchValue);
    // vector <string> newRow = {"hi"};
    // cat1.insert(secondTableName, newRow);
    // cat1.getCatalog();
    // cat1.addColumn(secondTableName);
    // cat1.getCatalog();
    // // end of section for class Catalog

}