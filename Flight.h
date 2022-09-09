#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <time.h>

using namespace std;

// Quiz #6
// 1. Utilizando esta classe agregue los atributos del vuelo: aerolinea, numero de vuelo, cantidad de pasajeros
// 2. Complete el constructor de la clase, de tal forma que se pueda modificar el flightTime para una hora y minutos específicos
// 3. Implementar alguna forma de convertir el time a un número entero de tal forma que entre menor la hora menor el número, eso en getIntTimeValue()
// 4. En el test.cpp, implementar la función fillFlights()
// fecha de entrega: jueves 8 de setiembre antes de las 10pm
// entrega al asistente al correo: kevinqj.2002@gmail.com
// subject: estructuras de datos - quiz #6
// adjuntan el archivo test.cpp y Flight.h

class Flight {
    
    private: 
        time_t flightTime;
        tm *currentTime;
        string aerolinea;
        int numeroVuelo;
        int cantidadPasajeros;
        int hour;
        int minutes;

    public: 
        Flight(int pHour, int pMinutes, int pNumeroVuelo, int pCantidadPasajeros) {
            this->hour = pHour;
            this->minutes = pMinutes;
            this->numeroVuelo = pNumeroVuelo;
            this->cantidadPasajeros = pCantidadPasajeros; 
            flightTime = time(NULL);
            currentTime = localtime(&flightTime);
            currentTime->tm_hour = pHour;
            currentTime->tm_min = pMinutes;
            
            changeFlightTime();
        }

        char* flightTimeString() {
            char* result = ctime(&flightTime);
            return result;
        }

        int getIntTimeValue() {
            int result = getCurrentHour();
            return result;
        }

        int getCurrentHour(){
            return hour;
        }

        int getNumeroVuelo(){
            return numeroVuelo;
        }

        int getCantidadPasajeros(){
            return cantidadPasajeros;
        }

        void changeFlightTime(){
            time_t auxFlightTime = flightTime;
            int year=0, day=0, hour=0, minute=0;

            year = auxFlightTime / 31536000;
            auxFlightTime %= 31536000;
            day = auxFlightTime / 86400;
            auxFlightTime %= 86400;
            hour = auxFlightTime / 3600;
            auxFlightTime %= 3600;
            minute = auxFlightTime / 60;
            auxFlightTime %= 60;

            flightTime -= ((hour - 6) * 3600 + (minute * 60));  //se resta 6 a las horas porque el flightime en 0 comienza desde las 18 horas y no desde 0
            flightTime += ((currentTime->tm_hour * 3600) + (currentTime->tm_min * 60));
        }

};