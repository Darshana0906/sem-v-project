#include "Pin.h"

Pin::Pin(Gate* owner, bool isInput)
    : owner(owner),
      input(isInput),
      position(0, 0)
{
}

Gate* Pin::getOwner() const
{
    return owner;
}

bool Pin::isInput() const
{
    return input;
}

QPointF Pin::getPosition() const
{
    return position;
}

void Pin::setPosition(const QPointF& newPosition)
{
    position = newPosition;
}