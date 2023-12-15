#pragma once

#include "Base.h"

class Pelota : public Base
{
private:
    float angulo;            // �ngulo actual de la pelota
    float velocidadAngular;  // Velocidad angular de la pelota
    float velocidadLineal;   // Velocidad lineal de la pelota

public:
    Pelota(Graphics^ g)
    {
        x = rand() % (int)g->VisibleClipBounds.Width;
        y = rand() % (int)g->VisibleClipBounds.Height;

        velocidadLineal = 2.0f;  // Puedes ajustar la velocidad lineal seg�n tus necesidades
        angulo = 45.0f;
        velocidadAngular = 0.1f;  // Puedes ajustar la velocidad angular seg�n tus necesidades
    }

    void Mover(Graphics^ g)
    {
        // Calcula las componentes dx y dy utilizando funciones trigonom�tricas
        dx = velocidadLineal * cos(angulo * (Math::PI / 180.0));
        dy = velocidadLineal * sin(angulo * (Math::PI / 180.0));

        // Actualiza la posici�n seg�n las nuevas componentes dx y dy
        if (x + dx >= 0 && (x + ancho + dx) < g->VisibleClipBounds.Width)
        {
            x += dx;
        }

        if (y + dy >= 0 && (y + alto + dy) < g->VisibleClipBounds.Height)
        {
            y += dy;
        }

        // Actualiza el �ngulo
        angulo += velocidadAngular;

        // Puedes agregar l�mites al �ngulo si es necesario
        // Por ejemplo: if (angulo > 360) angulo -= 360;

        // Puedes utilizar la matriz de transformaci�n para rotar la pelota
        Drawing2D::Matrix^ matrizRotacion = gcnew Drawing2D::Matrix();
        matrizRotacion->RotateAt(angulo, Point(x + ancho / 2, y + alto / 2));

        // Aplica la matriz de transformaci�n a los gr�ficos utilizando Transform
        g->Transform = matrizRotacion;
    }

    void Mostrar(Graphics^ g)
    {
        // Restaura la transformaci�n despu�s de dibujar la pelota
        g->ResetTransform();

        // Dibuja la pelota (sin la transformaci�n de rotaci�n aplicada)
        g->FillRectangle(Brushes::Green, Area());
    }
};
