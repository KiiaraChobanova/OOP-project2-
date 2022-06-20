#pragma once
#include "table.h"

template <typename T>
class Catalog : public Table<T>{

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

    void getCatalog(){
        cout << "\nSize of catalog is: " << m_size;

        for (Table<T>& i : m_tables) {
            i.getTable();
            cout << "==========\n";
        }
    }

    void addTable(Table<T>& newTable){
        m_tables.push_back(newTable);
        m_size++;
    }

    void removeTable(unsigned int tableNumber){
        cout << "Removing table...";
        for(int i = 0; i < m_size; ++i){
            if(i == tableNumber)
                swap(m_tables[i], m_tables[m_size]);
                m_tables.pop_back();
                m_size--;
                return;
        }
        std::cout << "There is no such table!";
        return;
    }

    void showtables(){
        cout << "\nShowing tables names... \n";
        for(int i = 0; i < m_size; ++i){
            cout << m_tables[i].getTableName() << " ";
        }
    }

    void describe(const string name){ // add m_type of column
        for(int i = 0; i < m_size; ++i){
            if(m_tables[i].getTableName() == name){
            cout << "\nGeting columns types... ";
                m_tables[i].getTypesOfColumns();
                return;
            }
        }
        cout << "There is no have such table!";
        return;
    }

    void select(unsigned int serialNumber, T value, string tableName){
        for(int i = 0; i < m_size; ++i){
            if(m_tables[i].getTableName() == tableName){
                m_tables[i].select(serialNumber, value);
                return;
            }
            cout << "There is no have such table! ";
            return;
        }
    }

    void rename(string oldName, string newName){
        for(int i = 0; i < m_size; ++i){
            if(m_tables[i].getTableName() == newName){
                cout << "\nThis name is not unique!\n";
                return;
            }
        }
        for(int i = 0; i < m_size; ++i){
            if(m_tables[i].getTableName() == oldName)
                m_tables[i].setName(newName);
                return;
        }
        cout << "\nThere is no have such table!\n";
        return;
    }

    unsigned int count(string tableName, T searchValue){
        int counter = 0;
        for(int i = 0; i < m_size; ++i){
            if(m_tables[i].getTableName() == tableName){
                counter += m_tables[i].count(searchValue);        
            }
        }
        return counter;
    }

    void insert(string tableName, vector <T> newRow){
        cout << "\nInserting new row... \n";
        for(int i = 0; i < m_size; ++i){
            if(m_tables[i].getTableName() == tableName){
                m_tables[i].insert(newRow);
            }
        }
    }

    void addColumn(string tableName){
        vector<T> newCells;
        string type = "NULL";
        Column<T> newColumn(newCells, type);

        for(int i = 0; i < m_size; ++i){
            if(m_tables[i].getTableName() == tableName){
                m_tables[i].addColumn(newColumn);
            }
        }
    }

};