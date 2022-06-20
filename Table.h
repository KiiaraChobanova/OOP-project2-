#ifndef TABLE_H
#define TABLE_H

#include "Column.h"

template <typename T>
class Table{

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

    void printTable(){
        cout << "\nGetting table... " << "\n" << m_tableName << "\n" << "Table " << m_tableNumber << "\n" << "----------\n";
        for (Column<T>& i : m_columns) {
            i.printColumn();
            cout << "----------\n";
        }
    }

    void setName(string name){
        m_tableName = name;
    }

    void addColumn(Column<T> newColomn){
        cout << "Add the column...\n";
        m_columns.push_back(newColomn);
        m_size++;
    }

    void removeColumn(unsigned int columnNumber){
        try{
            for(int i = 0; i < m_size-1; ++i)
                if(i == columnNumber)
                    swap(m_columns[i], m_columns[m_size-1]);
                    cout << "\nRemoving the column...";
                    m_columns[m_size-1].printColumn();
                    m_columns.pop_back();
                    m_size--;
                    return;

                throw std::invalid_argument("There is no have column with this number!");
        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
            return; 
        }
    } 

    void printTypesOfColumns(){
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
            try{
                for(int j = 0; j < m_columns[i].getSize(); ++j){
                    if(m_columns[j].cellWithID(serialNumber) == value){
                        cout << "Getting whole row inside the operation select... ";
                        getWholeRow(serialNumber);
                        return;
                    }
                }
                throw std::invalid_argument("There is no have such column!");
            }
            catch (std::invalid_argument& e){
                cerr << e.what() << "\n";
                return; 
            }
        }
    }

    unsigned int count(T& searchValue){
        int counter = m_size * m_columns[0].getSize();
        for(int i = 0; i < m_size; ++i){
            try{
                for(int j = 0; j < m_columns[i].getSize(); j++){
                    if(m_columns[i].cellWithID(j) == searchValue){
                        cout << "Number of rows in table are: ";
                        return counter;
                    }
                }
                throw std::invalid_argument("There is no have such column!");
            }
            catch (std::invalid_argument& e){
                cerr << e.what() << "\n";
                return 0; 
            }
        }
        return 0;
    }

    void insert(vector <T> newRow){
        for(int i = 0; i < m_size; ++i){
            m_columns[i].addCell(newRow[i]);
        }
    }

    void deleteWholeRow(int numberOfRow){
        for(int i = 0; i < m_size; ++i){
            m_columns[i].removeCell(numberOfRow);
        }
    }

    void myDelete(int searchColumn, T searchValue){
        try{
            for(int i = 0; i < m_size; ++i)
                if(i == searchColumn){
                    try{
                        for(int j = 0; j < m_columns[i].getSize(); ++i)
                            if(m_columns[i].cellWithID(j) == searchValue){
                                deleteWholeRow(j);
                                return;
                            }
                        throw std::invalid_argument("There is no have such column!");
                    }
                    catch (std::invalid_argument& e){
                        cerr << e.what() << "\n";
                    }
                }
            throw std::invalid_argument("There is no have such column!");
        }
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
        }
    }

    unsigned int printTableNumber() const { return m_tableNumber; };

    unsigned int printColumnsNumber() const { return m_size; };
    
    string printTableName() const { return m_tableName; };

    unsigned int getSize() const { return m_size; }

    friend inline std::istream& operator >> (std::istream& in,  Table<T>& table){
        in >> table.m_tableName >> table.m_counter;
        for(int i = 0; i < table.getSize(); ++i){
            in >> table.m_columns[i];
        }
        return in;
    }

    friend inline std::ostream& operator << (std::ostream& out, const Table<T>& table){
        out << table.m_tableName << "\nTable number: "  << table.m_counter << "\n";
        for(int i = 0; i < table.getSize(); ++i){
            out << table.m_columns[i];
        }
        return out;
    }

};

template <typename T>
unsigned int Table<T>::m_counter = 0;

#endif
