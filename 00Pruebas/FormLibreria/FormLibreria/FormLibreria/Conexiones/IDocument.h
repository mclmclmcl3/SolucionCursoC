#pragma once

#include <vector>

template <typename T>
class IDocument
{
public:
    virtual ~IDocument() = default;

    virtual void Escribir(const T& data) = 0;
    virtual std::vector<T> Leer() = 0;
    virtual bool Existe(const T& data) = 0;
    virtual void EscribirDatos(const std::vector<T>& datos) = 0;
    virtual bool ArchivoVacio() = 0;
};
