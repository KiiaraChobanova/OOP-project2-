#pragma once
#include "table.h"

template <class T>
class Catalog {

private:
    unsigned int m_size;
    vector<Table<T>> m_tables;

public:

    Catalog(){
        m_size = 0;
        vector<Table<T>> temp;
        m_tables = temp;
        cout << "\nDefault catalog constructor called\n";
    }

    Catalog(vector<Table<T>> tables){
        m_size = tables.size();
        for(int i = 0; i < m_size; ++i){
            m_tables.push_back(tables[i]); 
        }
        cout << "\nCatalog constructor called\n";
    }

    void printCatalog(){
        cout << "\nSize of catalog is: " << m_size;

        for (Table<T>& i : m_tables) {
            i.printTable();
            cout << "==========\n";
        }
    }

    void addTable(Table<T>& newTable){
        m_tables.push_back(newTable);
        m_size++;
    }

    void removeTable(unsigned int tableNumber){
        cout << "Removing table...";
        try{
            for(int i = 0; i < m_size; ++i){
                if(i == tableNumber)
                    swap(m_tables[i], m_tables[m_size]);
                    m_tables.pop_back();
                    m_size--;
                    return;
            }
            throw std::invalid_argument("There is no have table with this number!");
        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
            return; 
        }
    }

    void showtables(){
        cout << "\nShowing tables names... \n";
        for(int i = 0; i < m_size; ++i){
            cout << m_tables[i].printTableName() << " ";
        }
    }

    void describe(const string name){ 
        try{
            for(int i = 0; i < m_size; ++i){
                if(m_tables[i].printTableName() == name){
                cout << "\nGeting columns types... ";
                    m_tables[i].printTypesOfColumns();
                    return;
                }
            }
            throw std::invalid_argument("There is no have table with this name!");

        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
            return; 
        }
    }

    void select(unsigned int serialNumber, T value, string tableName){
        try{
            for(int i = 0; i < m_size; ++i){
                if(m_tables[i].printTableName() == tableName){
                    m_tables[i].select(serialNumber, value);
                    return;
                }
            }
            throw std::invalid_argument("There is no have such table!");

        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
            return; 
        }
    }

    void rename(string oldName, string newName){
        cout << "Renaming... ";
        for(int i = 0; i < m_size; ++i){
            if(m_tables[i].printTableName() == newName){
                cout << "\nThis name is not unique!\n";
                return;
            }
        }
        try{
            for(int i = 0; i < m_size; ++i){
                if(m_tables[i].printTableName() == oldName)
                    m_tables[i].setName(newName);
                    return;
            }
            throw std::invalid_argument("There is no have such table!");
        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
            return; 
        }
    }

    unsigned int count(string tableName, T searchValue){
        int counter = 0;
        for(int i = 0; i < m_size; ++i){
            if(m_tables[i].printTableName() == tableName){
                counter += m_tables[i].count(searchValue);        
            }
        }
        return counter;
    }

    void insert(string tableName, vector <T> newRow){
        cout << "\nInserting new row... \n";
        try{
            for(int i = 0; i < m_size; ++i){
                if(m_tables[i].printTableName() == tableName){
                    m_tables[i].insert(newRow);
                    return;
                }
            }
            throw std::invalid_argument("There is no have such table!");
        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
            return; 
        }

    }

    void addColumn(string tableName){
        vector<T> newCells;
        string type = "NULL";
        Column<T> newColumn(newCells, type);
        try{
            for(int i = 0; i < m_size; ++i){
                if(m_tables[i].printTableName() == tableName){
                    m_tables[i].addColumn(newColumn);
                    return;
                }
            }
            throw std::invalid_argument("There is no have such table!");
        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
            return; 
        }
    }

    void print(string tableName){
        cout << "Print table... ";
        try{
            for(int i = 0; i < m_size; ++i){
                if(m_tables[i].printTableName() == tableName){
                    m_tables[i].printTable();
                    return;
                }
            }
            throw std::invalid_argument("There is no have such table!");
        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
            return; 
        }
    }

    void myDelete(string tableName, unsigned int searchColumn,T searchValue){
        try{
            for(int i = 0; i < m_size; ++i)
                if(m_tables[i].printTableName() == tableName){
                    m_tables[i].myDelete(searchColumn, searchValue);
                    return;
                }
            throw std::invalid_argument("There is no have such table!");
        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
            return; 
        }
    }

    void import(){
        ifstream otherTable("otherTable.txt");
        if(!otherTable){
            cout << "Problem with oppening the file!";
            return;
        }
        char ch;
        while(!otherTable.eof()){
            otherTable.get(ch);
            cout << ch;
        }
        otherTable.close();
    }
};
