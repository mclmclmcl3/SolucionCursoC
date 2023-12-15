#pragma once

#include "Base.h"

class Pelota : public Base
{
private:
    float angulo;            // Ángulo actual de la pelota
    float velocidadAngular;  // Velocidad angular de la pelota
    float velocidadLineal;   // Velocidad lineal de la pelota

public:
    Pelota(Graphics^ g)
    {
        x = rand() % (int)g->VisibleClipBounds.Width;
        y = rand() % (int)g->VisibleClipBounds.Height;

        velocidadLineal = 2.0f;  // Puedes ajustar la velocidad lineal según tus necesidades
        angulo = 45.0f;
        velocidadAngular = 0.1f;  // Puedes ajustar la velocidad angular según tus necesidades
    }

    void Mover(Graphics^ g)
    {
        // Calcula las componentes dx y dy utilizando funciones trigonométricas
        dx = velocidadLineal * cos(angulo * (Math::PI / 180.0));
        dy = velocidadLineal * sin(angulo * (Math::PI / 180.0));

        // Actualiza la posición según las nuevas componentes dx y dy
        if (x + dx >= 0 && (x + ancho + dx) < g->VisibleClipBounds.Width)
        {
            x += dx;
        }

        if (y + dy >= 0 && (y + alto + dy) < g->VisibleClipBounds.Height)
        {
            y += dy;
        }

        // Actualiza el ángulo
        angulo += velocidadAngular;

        // Puedes agregar límites al ángulo si es necesario
        // Por ejemplo: if (angulo > 360) angulo -= 360;

        // Puedes utilizar la matriz de transformación para rotar la pelota
        Drawing2D::Matrix^ matrizRotacion = gcnew Drawing2D::Matrix();
        matrizRotacion->RotateAt(angulo, Point(x + ancho / 2, y + alto / 2));

        // Aplica la matriz de transformación a los gráficos utilizando Transform
        g->Transform = matrizRotacion;
    }

    void Mostrar(Graphics^ g)
    {
        // Restaura la transformación después de dibujar la pelota
        g->ResetTransform();

        // Dibuja la pelota (sin la transformación de rotación aplicada)
        g->FillRectangle(Brushes::Green, Area());
    }
};
