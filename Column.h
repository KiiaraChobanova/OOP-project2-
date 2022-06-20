#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Column{
    
private:
    static unsigned int m_columnID;
    static unsigned int m_cellID;
    unsigned int m_columnNumber;
    unsigned int m_cellsNumber;

    vector<T> m_cells;
    unsigned int m_size;
    string m_type;

public:
    Column(){
        m_columnNumber = ++m_columnID;
        m_cellsNumber = m_cellID;
        vector<T> temp;
        m_cells = temp;
        m_size = 2;
        m_type = "NULL"; 
        cout << "\nDefault column constructor called\n";
    }

    Column(vector<T> cells, string type){
        m_type = type;
        m_columnNumber = ++m_columnID;
        for(int i = 0; i < cells.size(); ++i){
            m_cells.push_back(cells[i]);
            m_cellsNumber = ++m_cellID;
        }
        m_size = m_cells.size();
        cout << "\nColumn constructor called\n";
    }

    void getColumn(){ 
        cout << "\n" << "Column " << m_columnNumber << "\n" << m_type << "\n";
        for(int i = 0; i < m_size; ++i){
            cout << m_cells[i] << "\n";
        }
    }

    void addCell(const T& newCell){
        m_cells.push_back(newCell);
        m_size++;
        m_cellID++;
    }

    void removeCell(const unsigned int cellNumber){
        for(int i = 0; i < m_size; ++i){
            if(i == cellNumber)
                swap(m_cells[i], m_cells[m_size]);
                m_cells.pop_back();
                m_size--;
                return;
        }   
        std::cout << "There is no such cell!";
        return;
    }

    T cellWithID(unsigned int id){
        try{
            if(m_cellsNumber <= id)
                throw std::invalid_argument("The id must be between the cell numbers");
            return m_cells[id];
        } 
        catch (std::invalid_argument& e){
            cerr << e.what() << "\n";
        }
        return 0;
    }

    void setType(const string type){
        m_type = type;
    }

    string getType() const{ return m_type; }
    unsigned int getCellsNumber() const { return m_cellsNumber; }
    unsigned int getColumnNumber() const { return m_columnNumber; }
    unsigned int getSize()const { return m_size; };
   
};

template <typename T>
unsigned int Column<T>::m_columnID = 0;

template <typename T>
unsigned int Column<T>::m_cellID = 2;