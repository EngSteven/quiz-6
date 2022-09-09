#include "Flight.h"
#include "DLinkedlist/List.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

// debe llenar una lista de pCantidad vuelos aleatorios cuya hora y minutos de partida esten entre pStartHour y pEndHour
// tomando en cuenta las restricciones de los minutos de salida segun el ejercicio 3 del caso #3
void fillFlights(int pCantidad, int pStartHour, int pEndHour, List<Flight> *& listFlights) {
    
    int randHour=0, randMinutes=0, randDelayMinutes=0;
    srand(time(0));
    for(int indexFlight=0; indexFlight<pCantidad; indexFlight++){
        randHour = rand() % (pEndHour-pStartHour) + pStartHour;  //hora
        randMinutes = 0 + rand() % (42);            //minutos 
        randDelayMinutes = 0 + rand() % (17);       //minutos de atraso
        randMinutes += randDelayMinutes;
        Flight *flight = new Flight(randHour, randMinutes);
        listFlights->add(flight);
    }
    //hacer un rand de 0-42 para establecer los minutos, de 0-17 para el atraso y 0-24 para la hora
} 

int main() {
    List<Flight> * listFlights = new List<Flight>();
    Flight *flight;
    int cont=1;
    fillFlights(5, 4, 7, listFlights);
    while(!listFlights->isEmpty()){
        flight = listFlights->remove(0);
        cout << "\nFlight: " << cont << endl;
        cout << flight->flightTimeString() << "y el entero es: " << flight->getIntTimeValue() << endl;
        cont++;
    }
}