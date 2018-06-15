#include<iostream>
using namespace std;
template<typename T>
class nodo{
public:
    T valor;
    nodo* siguiente;
    nodo(){
        valor=NULL;
        siguiente=nullptr;
    }
    nodo(T val){
        valor=val;
        siguiente=nullptr;
    }
    void delleteall(){
        if(siguiente){
            siguiente->delleteall();
        }
        delete this;
    }
    void print(){
        cout<<valor<<"->";
    }
    ~nodo(){}
};
template<typename T>
class lista{
public:
    nodo<T> *m_head;
    nodo<T> *fin;
    int m_num_nodes;
    lista(){
        m_num_nodes=0;
        m_head=nullptr;
        fin=nullptr;
    }
    void addhead(T valor){
        nodo<T>* newnodo=new nodo<T> (valor);
        if(!m_head){
            m_head=newnodo;
            m_head->siguiente=m_head;
            fin=m_head;
        }
        else{
            fin->siguiente=newnodo;
            newnodo->siguiente=m_head;
            fin=newnodo;

        }
        m_num_nodes++;
    }
     void addfin(T data){
        nodo<T>* newnode= new nodo<T>(data);
        if(!m_head){
            m_head=newnode;
            m_head->siguiente=m_head;
            fin=newnode;
        }
        else{
            fin->siguiente=newnode;
            newnode->siguiente=m_head;
            fin=newnode;
        }
        m_num_nodes++;
     }
    void addbetw(T data){
        nodo<T>* new_nodo=new nodo<T>(data);
        nodo<T>* temp=m_head;
        if(!m_head){
            m_head=new_nodo;
        }
        else{
            if(m_head->valor > data){
                new_nodo->siguiente=m_head;
                m_head=new_nodo;
                fin=new_nodo;
            }
            else{
                while((temp->siguiente != nullptr)&& (temp->siguiente->valor < data)){
                    temp=temp->siguiente;

                }
                new_nodo->siguiente = temp->siguiente;
                temp->siguiente = new_nodo;
                fin=new_nodo;
            }
        }
        m_num_nodes++;
    }
    void dellall(){
       m_head->delleteall();
       m_head = 0;
    }
    void print(){
        nodo<T>* temp=m_head;
        if(!m_head){
            cout<<"la lista esta vacia"<<endl;
        }
        else{
            while(temp){
                temp->print();
                if(!temp->siguiente){
                    cout<<m_head->valor<<endl;
                }
                temp=temp->siguiente;
            }
        }
        cout<<endl<<endl;
    }
};
int main(){
    lista<int> list_1;
    list_1.addhead(5);
    list_1.addbetw(8);
    //list_1.addbetw(7);
   // list_1.print();
    cout<<"hole";
}
