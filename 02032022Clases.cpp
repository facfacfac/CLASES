#include <iostream>

using namespace std;

// Las clases son estructuras de datos formadas por atributos (variables) de un objeto. que pueden ser de cualquier tipo (se pueden mezclar) y sus características (valores).

class rectangulo {
// public: hay que ponerlo para que se pueda cambiar directamente; pero no queremos que los atributos sean públicos, como regla general. Los métodos si son públicos como regla general.
private: // por defecto es privado, pero lo ponemos como recordatorio.
	double base;
	double altura;
public: // los métodos si suelen ser publicos.
	rectangulo(double base = 1, double altura = 1){ // esta función se denomina constructor, y sirve para crear un nuevo objeto de la clase. No hay que ponerle ningún tipo, solo el nombre de la clase y sus variables como parámetros. Los valores indicados son los valores por defecto.
		// this->base = base;
		// this->altura = altura;
		// También podemos llamar a las funciones set en el constructor.
		setBase(base);
		setAltura(altura);

	}
	// En C++ solo puede haber un constructor por clase!! En otros lenguajes sí puede haber un constructor.
	void setBase(double base){
		if (base>0) this->base = base; // El this-> indica que se refiere a la variable de esta clase y no a otra (p.ej.: no al parámetro pasado) El if es para que no se pongan valores negativos.
		else this->base = 1; // le ponemos el valor por defecto si no se cumple la condición (si no lo hacemos, pone basura, es decir, no pone valor).
	}
	void setAltura(double altura){
		(altura>0) ? this->altura = altura : this->base = 1;// Esto es otra forma de hacer los if else con una condición.
	}
	double getBase(){
		return this->base;
	}
	double getAltura(){
		return this->altura;
	}
	// Una método para conocer el área del rectángulo.
	double area(){
		return this->base*this->altura;
	}
	double perimetro(){
		return (this->base*2)+(this->altura*2);
	}
	// Una función para imprimir todo sobre la clase:
	void imprimir(){
		// cout << "La base es " << this->base << " y es " << this->altura << endl;
		// También podríamos pedirle que imprima el area y el perimetro:
		cout << "La base es " << this->base << " , la altura es " << this->altura << " , el area es " << this->area() << " y el perimetro es " << this->perimetro() << endl;
	}

}; // Al final de la clase se pone ; porque es una estructura.

class circulo {
private:
	double radio;
public:
	const double PI = 3.1416;
	circulo (double radio = 1) {
		setRadio(radio);
	}
	void setRadio(double radio) {
		(radio > 0) ? this->radio = radio : this->radio = 1;
	}
	double getRadio() {
		return this->radio;
	} 
	double area() {
		return (this->radio*this->radio)*this->PI;
	}
	double perimetro() {
		return (this->radio*2)*this->PI;
	}
	void imprimir() {
		cout << "El radio es " << this->radio << " , el area es " << this->area() << " y el perimetro es " << this->perimetro() << endl;
	}

};

int main() {

	rectangulo folio(-5,3); // los objetos se declaran con su clase como tipo.
	rectangulo tablero; // también se pueden dejar los valores por defecto.
	rectangulo manta(4); // O darle solo un valor; entonces, solo cambia la primera variable (las va cogiendo en orden de introducción... no podemos dejar las primeras  por defecto e introducir las últimas)
	/* No podemos cambiar una variable de un objeto directamente, porque son privadas:
	folio.base = 2
	*/

	circulo diana(5);
	//Esto es una forma de acceder: cout << "La base de folio es " << folio.getBase() << " y la altura es " << folio.getAltura() << endl; // Así accedemos a los valores de las variables.
	//Pero es mejor usar la función imprimir.
	cout << "Folio:" << endl;
	folio.imprimir();

	// Con los set, como son publicos, si podemos cambiar los valores:
	folio.setBase(2);
	folio.setAltura(2);
	folio.imprimir();

	cout << "Tablero:" << endl;
	tablero.imprimir();

	cout << "Manta:" << endl;
	manta.imprimir();

	cout << "Diana: " << endl;
	diana.imprimir();



	return 0;
}