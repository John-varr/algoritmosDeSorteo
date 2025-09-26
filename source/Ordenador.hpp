#include <cstdint>
#pragma once
/*
Credits
Author: Prof. Arturo Camacho, ECCI-Universidad de Costa Rica
Modified by: Prof. Allan Berrocal, ECCI-Universidad de Costa Rica
*/
class Ordenador {
    private:
    public:
      Ordenador() = default;
      ~Ordenador() = default;
      void ordenamientoPorSeleccion(std::uint32_t *A, std::uint32_t n) const;
      void ordenamientoPorInserccion(std::uint32_t *A, std::uint32_t n) const;
      void ordenamientoPorMezcla(std::uint32_t *A, std::uint32_t n) const;
      void ordenamientoPorMonticulos(std::uint32_t *A, std::uint32_t n) const;
      void ordenamientoRapido(std::uint32_t *A, std::uint32_t n) const;
      void ordenamientoPorResiduos(std::uint32_t *A, std::uint32_t n) const;

    /**
     * @brief Retorna un std::string con los datos de la tarea.
     * 
     * Este método devuelve una cadena de texto que contiene el carné, nombre y tarea.
     * 
     * @return std::string Una cadena de texto con los datos de la tarea.
     */
    constexpr const char* imprimirDatosDeTarea() const {
      return "Carné: C4K672, Nombre: John Esteban Vargas Arroyo, Tarea 1";
    } 
};