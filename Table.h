#pragma once
#include "Column.h"

template <typename T>
class Table : public Column<T>{

protected:
    static unsigned int m_counter;
    unsigned int m_tableNumber;
    unsigned int m_size;
    vector<Column<T>> m_columns;
    string m_tableName;

public:
    Table(){
        m_tableNumber = ++m_counter;
        m_size = m_columns.size();
        m_tableName = "\nDefault table\n";
        vector<Column<T>> temp;
        m_columns = temp;
        cout << "\nDefault table constructor called\n";
    }

    Table(vector<Column<T>> columns, string tableName){
        m_tableNumber = ++m_counter;
        m_size = columns.size();
        m_tableName = tableName;
        for(int i = 0; i < m_size; ++i){
            m_columns.push_back(columns[i]);
        }  
        cout << "\nTable constructor called\n";
    }

    void getTable(){
        cout << "\nGetting table... " << "\n" << m_tableName << "\n" << "Table " << m_tableNumber << "\n" << "----------\n";
        for (Column<T>& i : m_columns) {
            i.getColumn();
            cout << "----------\n";
        }
    }

    unsigned int getSize(){ return m_size; }

    void setName(string name){
        m_tableName = name;
    }

    void addColumn(Column<T> newColomn){
        cout << "Add the column...\n";
        m_columns.push_back(newColomn);
        m_size++;
    }

    void removeColumn(unsigned int columnNumber){
        for(int i = 0; i < m_size-1; ++i)
            if(i == columnNumber)
                swap(m_columns[i], m_columns[m_size-1]);
                cout << "\nRemoving the column...";
                m_columns[m_size-1].getColumn();
                m_columns.pop_back();
                m_size--;
                return;
        std::cout << "There is no such colomn!";
        return;
    } 

    void getTypesOfColumns(){
        for(int i = 0; i < m_size; ++i){
            cout << m_columns[i].getType() << " ";
        }
    }

    void getWholeRow(unsigned int number){
        for(int i = 0; i < m_size-1; ++i){
            try{
                if(number > m_columns[i].getSize()){
                    throw std::invalid_argument("The number must be between the rows numbers");
                }
                for(int j = 0; j < m_columns[i].getSize() - 2; ++j){
                    cout << m_columns[j].cellWithID(number) << ", ";
                }
            }
            catch (std::invalid_argument& e){
                cerr << e.what() << "\n";
                return; 
            }
        }
    }

    void select(unsigned int serialNumber, T value){
        for(int i = 0; i < m_size; ++i){
            for(int j = 0; j < m_columns[i].getSize(); ++j){
                if(m_columns[j].cellWithID(serialNumber) == value){
                    cout << "Getting whole row inside the operation select... ";
                    getWholeRow(serialNumber);
                    return;
                }
            }
        }
    }

    unsigned int count(T& searchValue){
        int counter = m_size * m_columns[0].getSize();
        for(int i = 0; i < m_size; ++i){
            for(int j = 0; j < m_columns[i].getSize(); j++){
                if(m_columns[i].cellWithID(j) == searchValue){
                    cout << "Number of rows in table are: ";
                    return counter;
                }
            }
        }
        cout << "There is no such search value!";
        return 0;
    }

    void insert(vector <T> newRow){
        for(int i = 0; i < m_size; ++i){
            m_columns[i].addCell(newRow[i]);
        }
    }

    unsigned int getTableNumber() const { return m_tableNumber; };

    unsigned int getColumnsNumber() const { return m_size; };
    
    string getTableName() const { return m_tableName; };
};

template <typename T>
unsigned int Table<T>::m_counter = 0;
