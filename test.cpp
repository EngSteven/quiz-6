#include "Flight.h"
#include "DLinkedlist/List.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

// debe llenar una lista de pCantidad vuelos aleatorios cuya hora y minutos de partida esten entre pStartHour y pEndHour
// tomando en cuenta las restricciones de los minutos de salida segun el ejercicio 3 del caso #3
void fillFlights(int pCantidad, int pStartHour, int pEndHour, List<Flight> *& listFlights) {
    
    int randHour=0, randMinutes=0, randDelayMinutes=0, nPasajeros=0;
    srand(time(0));
    for(int indexFlight=0; indexFlight<pCantidad; indexFlight++){
        randHour = rand() % (pEndHour-pStartHour) + pStartHour;  //hora
        randMinutes = 0 + rand() % (42);            //minutos 
        randDelayMinutes = 0 + rand() % (17);       //minutos de atraso
        randMinutes += randDelayMinutes;
        nPasajeros = rand() % (40-20) + 20;
        Flight *flight = new Flight(randHour, randMinutes, indexFlight+1, nPasajeros);
        listFlights->add(flight);
    }
} 

int main() {
    List<Flight> * listFlights = new List<Flight>();
    Flight *flight;
    int cont=1;
    fillFlights(5, 4, 7, listFlights);
    while(!listFlights->isEmpty()){
        flight = listFlights->remove(0);
        cout << "\nFlight #" << flight->getNumeroVuelo() << endl;
        cout << flight->flightTimeString() << " El entero es: " << flight->getIntTimeValue() << endl;
        cout << "Cantidad de pasajeros: " << flight->getCantidadPasajeros() <<endl;
        cont++;
    }
}