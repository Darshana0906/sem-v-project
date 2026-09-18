#ifndef GATE_H
#define GATE_H

#include <QGraphicsItem>
#include <QPainterPath>
#include <vector>

class Pin;

class Gate : public QGraphicsItem
{
public:
    Gate(QGraphicsItem* parent = nullptr);
    ~Gate();

    QRectF boundingRect() const override;

    std::vector<Pin*>& getInputPins();
    std::vector<Pin*>& getOutputPins();

    qreal getWidth() const;
    qreal getHeight() const;

protected:
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem* option,
               QWidget* widget = nullptr) override;

    virtual QPainterPath getPath() const = 0;

    std::vector<Pin*> inputPins;
    std::vector<Pin*> outputPins;

    qreal width;
    qreal height;
};

#endif