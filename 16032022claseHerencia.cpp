#include <iostream>
using namespace std;

class Persona{
  private:
    string nombre;
    string dni;
  public:
  // Constructor. Nombre por defecto es Celia, DNI por defecto es 12345678H.
    Persona(string nombre = "Celia", string dni = "12345678H"){
      this->nombre = nombre;
      this->dni = dni;
    }
  // Destructor. Se crea con el nombre de la clase precedido por ~.
  // Cuando acaba el main, se llama automáticamente al destructor.
    ~Persona(){
      cout << "Adios!" << endl;
    }
  // Métodos.
    // Getters y Setter.
    string getNombre(){
      return this->nombre;
    }
    void setNombre(string nombre){
      this->nombre = nombre;
    }
    string getDni(){
      return this->dni;
    }
    void setDni(string dni){
      this->dni = dni;
    }
    // Método imprimir.
    void imprimir(){
      cout << "Me llamo " << this->nombre << " y mi DNI es " << this->dni << "." << endl;
    }

};

// Vamos a hacer una clase heredada. Todos los alumnos son personas, por lo tanto, extendemos de persona.
class Alumno : public Persona{ // Todo lo que la clase persona va a ser publico para la subclase alumno.
  private:
    string clase;
    int curso;
  public:
    // Constructor
    Alumno (string clase = "DAW", int curso = 1) {
      this->clase = clase;
      this->curso = curso;
    }
    // El destructor es el mismo que Persona, porque Alumno es una Persona.
  // Métodos
    // Getters y Setters.
    string getClase(){
      return this->clase;
    }
    void setClase(string clase){
      this->clase = clase;
    }
    int getCurso(){
      return this->curso;
    }
    void setCurso(int curso){
      this->curso = curso;
    }
    // Imprimir.
    void imprimir(){ // Es necesario usar getNombre() y getDNI() porque el nombre y el dni de la persona son privados para alumno.
       cout << "Me llamo " << getNombre() << " y mi DNI es " << getDni() << "." << endl; // También podríamos poner this->getNombre() y this->getDni(), ya que han sido heredados.
      // No podemos decir directamente this->imprimir() porque estamos especializando la función para alumno.
      cout << "Estoy en el grado " << this->clase << " y mi curso es " << this->curso << "." << endl;
    }
};

int main(){
  Persona miPersona;
  Alumno miAlumno;

  cout << "Persona:" << endl;
  miPersona.imprimir();
  cout << "Cambio el nombre a Isaac." << endl;
  miPersona.setNombre("Isaac");
  miPersona.imprimir();

  cout << "Alumno:" << endl;
  miAlumno.imprimir();
  cout << "Cambio la clase a DAM." << endl;
  miAlumno.setClase("DAM");
  miAlumno.imprimir();




  return 0;
}
