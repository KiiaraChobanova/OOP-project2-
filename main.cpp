#include "Catalog.h"

int main(){
    
    //section for class Column
    vector<long long int> vect;
    vect = {-1,2,3,4,5,6,7};
    Column<long long int> c(vect, "INTEGER");
    c.printColumn();
    long long int a = 14;
    cout << "Cells number is: " << c.getCellsNumber() << "\n";
    cout << "Column number is: " << c.getColumnNumber() << "\n";
    cout << "Size of column " << c.getColumnNumber() <<" is: " << c.getSize() << "\n";
    c.printColumn();
    c.addCell(a);
    cout << "Size of column " << c.getColumnNumber() <<" is: " << c.getSize() << "\n";
    c.printColumn();
    c.removeCell(5);
    cout << "Size of column " << c.getColumnNumber() <<" is: " << c.getSize() << "\n";
    c.printColumn();
    int id = 2;
    cout << "\nCell with id = " << id << " is: " << c.cellWithID(id);
    //end of section for class Column


    //section for class Table
    vector<long long int> vect1, vect2, vect3, vect4;
    vect1 = {-1,2,3};
    vect2 = {5, 3, 2, 1, 6};
    vect3 = {111, 222, 333};
    vect4 = {9,8,7,6};
    string tableName = "First table";
    Column<long long int> c1(vect1,"INTEGER"), c2(vect2, "INTEGER");
    Table<long long int> t({c1, c2}, tableName);

    ofstream firstTableFile("firstTableInfo.txt");
    if(!firstTableFile.is_open()){
        cout << "Problem with opening the file";
        return -1;
    }
    firstTableFile << t; // write table in file
    firstTableFile.close(); 
    t.printTable();
    cout << t.printTableName() << " is renaming to the ";
    string secondName = "table number one";
    t.setName(secondName);
    cout << t.printTableName() << "..." << "\n";
    t.printTable();
    Column<long long int> c3(vect3, "INTEGER");
    cout << "In this table have: " << t.printColumnsNumber() << " columns\n";
    t.addColumn(c3);
    t.printTable();
    cout << "In this table have: " << t.printColumnsNumber() << " columns\n";
    t.removeColumn(1);
    t.printTable();
    cout << "In this table have: " << t.printColumnsNumber() << " columns\n";
    long long int searchValue1 = 2;
    cout << t.count(searchValue1);
    t.insert(vect4);
    t.printTable();
    cout << "Type of all columns are: ";
    t.printTypesOfColumns();
    cout << "\n" << "Getting whole row...  ";
    t.getWholeRow(2); 
    cout << "\n";
    //t.getWholeRow(10);
    cout << "Select operation...\n";
    t.select(1, 2);
    cout << "\n";
    t.myDelete(0, -1);
    t.printTable();
    //end of section for class Table


    // section for class Catalog
    vector<string> vect5;
    vect5 = {"Kiara", "Kiara"};
    Column<string> c4(vect5, "STRING");
    string firstTableName = "First string table";
    Table<string> t1({c4}, firstTableName);
    Catalog<string> cat1({t1});
    cat1.printCatalog();
    string secondTableName = "second string table";
    Table<string> t2({c4}, secondTableName);
    //cout << t2.printTableNumber(); // with 1 more because of first table t
    cat1.addTable(t2);
    cat1.printCatalog();
    cat1.removeTable(2);
    cat1.printCatalog();
    cat1.showtables();
    cat1.describe(firstTableName); 
    cout << "\n";
    //cat1.describe(secondTableName);
    cat1.rename(firstTableName, secondTableName);
    cat1.showtables();
    cout << "\n";
    string searchValue2 = "Kiara";
    cout << cat1.count(secondTableName, searchValue2);
    vector <string> newRow = {"hi"};
    cat1.insert(secondTableName, newRow);
    cat1.printCatalog();
    cat1.addColumn(secondTableName);
    cat1.printCatalog();
    cat1.print(secondTableName);
    cat1.import();
    // end of section for class Catalog

}
