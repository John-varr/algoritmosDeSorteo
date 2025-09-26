#include <cstdint>
#pragma once
/*
Credits
Author: Prof. Arturo Camacho, ECCI-Universidad de Costa Rica
Modified by: Prof. Allan Berrocal, ECCI-Universidad de Costa Rica
*/
using namespace std;

class Ordenador {
    private:
      void merge(uint32_t *, uint32_t, uint32_t, uint32_t) const;
      void mergeSortRec(uint32_t *, uint32_t, uint32_t) const;
    public:
      Ordenador() = default;
      ~Ordenador() = default;
      void ordenamientoPorSeleccion(uint32_t *A, uint32_t n) const;
      void ordenamientoPorInserccion(uint32_t *A, uint32_t n) const;
      void ordenamientoPorMezcla(uint32_t *A, uint32_t n) const;
      void ordenamientoPorMonticulos(uint32_t *A, uint32_t n) const;
      void ordenamientoRapido(uint32_t *A, uint32_t n) const;
      void ordenamientoPorResiduos(uint32_t *A, uint32_t n) const;

    /**
     * @brief Retorna un string con los datos de la tarea.
     * 
     * Este método devuelve una cadena de texto que contiene el carné, nombre y tarea.
     * 
     * @return string Una cadena de texto con los datos de la tarea.
     */
    constexpr const char* imprimirDatosDeTarea() const {
      return "Carné: C4K672, Nombre: John Esteban Vargas Arroyo, Tarea 1";
    } 
};