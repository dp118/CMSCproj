/*******************************
 * File: Tqueue.cpp
 * Author: Duarmienne Pineda
 * Date: 12/3/20
 * Section: 14
 * Email: dpineda1@gl.umbc.edu
 * Description:
 *******************************/
#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T, int N> //T is the data type and N is the container's capacity
class Tqueue {
public:
    //Name: Tqueue - Default Constructor
    //Precondition: None (Must be templated)
    //Postcondition: Creates a queue using dynamic array
    Tqueue(); //Default Constructor
    //Name: Copy Constructor
    //Precondition: Existing Tqueue
    //Postcondition: Copies an existing Tqueue
    Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
    //Name: Destructor
    //Desc: Empties m_data
    //Precondition: Existing Tqueue
    //Postcondition: Destructs existing Tqueue
    ~Tqueue(); //Destructor
    //Name: Enqueue
    //Desc: Adds item to the back of queue (checks for capacity)
    //Precondition: Existing Tqueue
    //Postcondition: Size is incremented if successful and m_back increases
    void Enqueue(T data); //Adds item to queue (to back)
    //Name: Dequeue
    //Desc: Removes item from queue (from front)
    //      **Automatically moves all data to start at index 0 (using loop**
    //Precondition: Existing Tqueue
    //Postcondition: Size is decremented if successful.
    //               Data in m_front is removed and remaining data is move to the front.
    void Dequeue();
    //Name: Sort
    //Desc: Sorts the contents of the Tqueue (any algorithm you like)
    //Precondition: Existing Tqueue
    //Postcondition: Contents of Tqueue is sorted (low to high)
    void Sort();
    //Name: IsEmpty
    //Precondition: Existing Tqueue
    //Postcondition: Returns 1 if queue is empty else 0
    int IsEmpty(); //Returns 1 if queue is empty else 0
    //Name: IsFull
    //Precondition: Existing Tqueue
    //Postcondition: Returns 1 if queue is full else 0
    int IsFull(); //Returns 1 if queue is full else 0
    //Name: Size
    //Desc: Returns size of queue
    //Precondition: Existing Tqueue
    //Postcondition: Returns size of queue (difference between m_back and m_front)
    int Size();
    //Name: Overloaded assignment operator
    //Precondition: Existing Tqueue
    //Postcondition: Sets one Tqueue to same as a second Tqueue using =
    Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
    //Name: At
    //Precondition: Existing Tqueue with index starting at 0
    //Postcondition: Returns object from Tqueue using At()
    T& At(int x);//Returns data from queue at location
    //Name: DisplayAll()
    //Precondition: Existing Tqueue (not used in MediaPlayer)
    //Postcondition: Outputs all items in Tqueue (must be cout compatible -
    //               may require overloaded << in object)
    void DisplayAll();
private:
    T* m_data; //Data of the queue (Must be dynamically allocated array)
    int m_front; //Front of the queue (for this project should always remain at 0)
    int m_back; //Back of the queue (will increase as the size increases)
};

// default tqueue constructor
template<class T, int N>
Tqueue<T, N>::Tqueue() {
    m_front = 0;
    m_back = -1;
    m_data = new T[N];
}

// copy constructor foor tqueue
template<class T, int N>
Tqueue<T, N>::Tqueue(const Tqueue<T, N> &x) {
    delete [] m_data;
    m_back = x.m_back;
    m_data = new T[x.m_back + 1];
    for(int i = 0; i <= m_back; i++)
        m_data[i] = x.m_data[i];
}

// tqueue destructor
template<class T, int N>
Tqueue<T, N>::~Tqueue() {
    m_front = 0;
    m_back = 0;
    m_data = nullptr;
}

// adds data to end of queue
template<class T, int N>
void Tqueue<T, N>::Enqueue(T data) {
    if(m_back < N){
        m_back++;
        m_data[m_back] = data;
        }
}

// removes the data from the front
template<class T, int N>
void Tqueue<T, N>::Dequeue() {
    if (IsEmpty() == 1)
        cout << "The queue is empty." << endl;
    else{
        for (int i = 0; i <= m_back; i++){
            m_data[i] = m_data[i+1];
        }
        m_back--;
    }
}

// sorting of queue
template<class T, int N>
void Tqueue<T, N>::Sort() {
    //bubble sort
    int flag = 1;
    for(int i = 0; i < Size()-1 && flag == 1; i++){
        flag = 0;
        for(int j = 0; j < Size() - i - 1; j++){
            if (m_data[j] > m_data[j + 1]){
                // swaps the data of one value to the next
                T temp = m_data[j];
                m_data[j] = m_data[j + 1];
                m_data[j + 1] = temp;
                flag = 1;
            }
        }
    }
}

// checks if queue is empty
template<class T, int N>
int Tqueue<T, N>::IsEmpty() {
    if (Size() == 0)
        return 1;
    return 0;
}

// checks if queue is full
template<class T, int N>
int Tqueue<T, N>::IsFull() {
    if (Size() >= N)
        return 1;
    return 0;
}

// gets the size of queue
template<class T, int N>
int Tqueue<T, N>::Size() {
    return m_back-m_front + 1;
}

// tqueue overloaded assignment operator
template<class T, int N>
Tqueue<T, N> &Tqueue<T, N>::operator=(Tqueue<T, N> y) {
    if (this != &y){
        delete [] m_data;
        m_back = y.m_back;
        m_data = new T[y.m_back + 1];
        for(int i = 0; i <= m_back; i++)
            m_data[i] = y.m_data[i];
            //m_data[i] = y.At(i);
    }
    return (*this);
}

//gets data at a certain location
template<class T, int N>
T &Tqueue<T, N>::At(int x) {
    return m_data[x];
}

// displays the tqueue
template<class T, int N>
void Tqueue<T, N>::DisplayAll() {
    for(int i = 0; i <= m_back; i++)
        cout << At(i) << endl;
}

#endif
