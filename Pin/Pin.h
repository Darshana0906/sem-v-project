#ifndef PIN_H
#define PIN_H

#include <QPointF>

class Gate;

class Pin
{
public:
    Pin(Gate* owner, bool isInput);

    Gate* getOwner() const;
    bool isInput() const;

    QPointF getPosition() const;
    void setPosition(const QPointF& newPosition);

private:
    Gate* owner;
    bool input;
    QPointF position;
};

#endif