#include "AndGate.h"
#include "../Pin/Pin.h"
#include <QPainter>

AndGate::AndGate(QGraphicsItem* parent)
    : Gate(parent)
{
    // Create two input pins
    inputPins.push_back(new Pin(this, true));
    inputPins.push_back(new Pin(this, true));

    // Create one output pin
    outputPins.push_back(new Pin(this, false));

    // Set their initial positions
    updatePinPositions();
}

void AndGate::updatePinPositions()
{
    /*
        Input pins:
        25 pixels to the left of the gate body.

        Their vertical positions are proportional
        to the gate height.

        Output pin:
        24 pixels to the right of the gate body.
    */

    inputPins[0]->setPosition(
        QPointF(-25, height * 0.25)
    );

    inputPins[1]->setPosition(
        QPointF(-25, height * 0.75)
    );

    outputPins[0]->setPosition(
        QPointF(width + 24, height * 0.5)
    );
}

QPainterPath AndGate::getPath() const
{
    QPainterPath path;

    path.moveTo(0, 0);

    path.lineTo(width * 0.5, 0);

    path.cubicTo(
        width * 0.85, 0,
        width, height * 0.25,
        width, height * 0.5
    );

    path.cubicTo(
        width, height * 0.75,
        width * 0.85, height,
        width * 0.5, height
    );

    path.lineTo(0, height);

    path.closeSubpath();

    return path;
}

void AndGate::paint(QPainter* painter,
                    const QStyleOptionGraphicsItem*,
                    QWidget*)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);

    // Draw AND gate body
    painter->drawPath(getPath());

    // Input lines
    painter->drawLine(
        -20,
        height * 0.25,
        0,
        height * 0.25
    );

    painter->drawLine(
        -20,
        height * 0.75,
        0,
        height * 0.75
    );

    // Output line
    painter->drawLine(
        width,
        height * 0.5,
        width + 20,
        height * 0.5
    );

    // Input pin circles
    painter->drawEllipse(
        -29,
        height * 0.25 - 4,
        8,
        8
    );

    painter->drawEllipse(
        -29,
        height * 0.75 - 4,
        8,
        8
    );

    // Output pin circle
    painter->drawEllipse(
        width + 20,
        height * 0.5 - 4,
        8,
        8
    );
}