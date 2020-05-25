#include<iostream>
#include"ArregloDePersonas.h"

    ArregloDePersonas::ArregloDePersonas( Persona personas[], int tam){
        this->tam=tam;
        persona=new Persona[tam];
        for(int i=0;i<tam;i++)
            *(persona+i)=personas[i];
        
    }
    ArregloDePersonas::ArregloDePersonas( ArregloDePersonas &o){
        tam=o.tam;
        persona=new Persona[tam];
        for(int i=0;i<tam;i++)
            *(persona+i)=o.persona[i];
    }
    ArregloDePersonas::~ArregloDePersonas(){
    }
    void ArregloDePersonas::redimensionar(int n){
        Persona *new_arr=new Persona[n];
        for(int i=0; i<tam; i++)
            *(new_arr+i)=*(persona+i);
        tam=n;
        delete[] persona;
        persona=new_arr;
    }
    void ArregloDePersonas::push_back( Persona &p){
        //this->tam+=1;
        redimensionar(++tam);
        persona[tam-1]=p;
    }
    void ArregloDePersonas::insert(const int posicion, const Persona &p){
        //tam++;
        redimensionar(++tam);
        for(int i=tam-1;i>posicion-1;i--)
            persona[i]=persona[i-1];
        persona[posicion-1]=p;
    }
    void ArregloDePersonas::remmove(const int pos){
        tam--;
        for(int i=pos-1;i<tam;i++)
            persona[i]=persona[i+1];
        redimensionar(tam);
    }
    int ArregloDePersonas::getSize(){ return tam;
    }
    void ArregloDePersonas::clear(){
        delete[] persona;
    }
    
    
    
    
    