#include <iostream>

using namespace std;

class Motor{
private:
	bool estado;
	// Métodos:
	void setEstado(bool estado){ // No lo necesitamos en publico, ya que vamos a acceder a este metodo desde un metodo publico.
		this->estado = estado;
	}
public:
	Motor(){
		this->estado = false; // Apagado (false) es el valor por defecto. 
	}
	bool getEestado(){
		return this->estado = estado;
	}
	void arrancar() {
		this->setEstado(true);
	}
	void apagar() {
		this->setEstado(false);
	}
	void imprimir(){
		if (this->estado) {
			cout << "El motor esta encendido." << endl;
		} else {
			cout << "El motor esta apagado." << endl;
		}
	}
};

class Ventana{
private:
	bool estado;
	// Métodos:
	void setEstado(bool estado){ // No lo necesitamos en publico, ya que vamos a acceder a este metodo desde un metodo publico.
		this->estado = estado;
	}
public:
	Ventana(){
		this->estado = false; // Cerradas (false) es el valor por defecto.
	}
	bool getEestado(){
		return this->estado = estado;
	}
	void abrirVentana() {
		this->setEstado(true);
	}
	void cerrarVentana() {
		this->setEstado(false);
	}
	void imprimir(){
		if (this->estado) {
			cout << "La ventana esta abierta." << endl;
		} else {
			cout << "La ventana esta cerrada." << endl;
		}
	}
};

class Puerta{
private:
	bool estado;
	Ventana ventanilla;
	// Podríamos construirla mediante referencia.
	// Métodos.
	void setEstado(bool estado) {
		this->estado = estado;
	}
public:
	Puerta(){ // Primera letra del constructor en mayúscula!! O no funciona.
		this->estado = false;
	}
	bool getEstado(){
		return this->estado;
	}
	Ventana getVentanilla(){
		return this->ventanilla;
	}
	void abrirPuerta(){
		this->setEstado(true);
	}
	void cerrarPuerta(){
		this->setEstado(false);
	}
	void imprimir(){
		if (this->estado){
			cout << "La puerta esta abierta.";
		} else {
			cout << "La puerta esta cerrada.";
		}
	cout << endl;
	this->ventanilla.imprimir();
	}
};

int main() {
	cout << "Motor:" << endl;
	Motor miMotor;
	miMotor.imprimir();
	cout << "Arrancamos el motor:" << endl;
	miMotor.arrancar();
	miMotor.imprimir();
	cout << "Apagamos el motor:" << endl;
	miMotor.apagar();
	miMotor.imprimir();

	cout << "Ventana:" << endl;
	Ventana miVentana;
	miVentana.imprimir();
	cout << "Abrimos la ventana:" << endl;
	miVentana.abrirVentana();
	miVentana.imprimir();
	cout << "Cerramos la ventana:" << endl;
	miVentana.cerrarVentana();
	miVentana.imprimir();

	cout << "Puerta:" << endl;
	Puerta miPuerta;
	miPuerta.imprimir();
	miPuerta.abrirPuerta();
	miPuerta.imprimir();
	miPuerta.cerrarPuerta();
	miPuerta.imprimir();
	cout << "Abrir la ventana de la puerta:" << endl;
	miPuerta.getVentanilla().imprimir();
	Ventana miVentanilla = miPuerta.getVentanilla();
	miVentanilla.abrirVentana();
	miPuerta.imprimir();


}