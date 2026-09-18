#include "Gate.h"
#include "../Pin/Pin.h"
#include <QPainter>

Gate::Gate(QGraphicsItem* parent)
    : QGraphicsItem(parent),
      width(100),
      height(60)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

Gate::~Gate()
{
    for (Pin* pin : inputPins)
        delete pin;

    for (Pin* pin : outputPins)
        delete pin;
}

QRectF Gate::boundingRect() const
{
    /*
        Gate body:
        x = 0
        y = 0
        width = 100
        height = 60

        Pins extend approximately 30 pixels
        outside on both sides.
    */

    return QRectF(-30, 0, width + 60, height);
}

std::vector<Pin*>& Gate::getInputPins()
{
    return inputPins;
}

std::vector<Pin*>& Gate::getOutputPins()
{
    return outputPins;
}

qreal Gate::getWidth() const
{
    return width;
}

qreal Gate::getHeight() const
{
    return height;
}

void Gate::paint(QPainter* painter,
                 const QStyleOptionGraphicsItem*,
                 QWidget*)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);

    painter->drawPath(getPath());
}