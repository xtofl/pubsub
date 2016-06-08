#ifndef SWITCH_H
#define SWITCH_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QStateMachine>

class Switch : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Switch(QPointF topleft, QString name, QObject *objectParent, QGraphicsItem *parent);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


signals:
    void clicked();

    void on();
    void off();

public slots:
    void fill();
    void clear();

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    QString name;

    struct Moving {
        QPointF from;
        QPointF to;
        QPointF diff() const { return to - from;}
    };
    Moving moving;
    QStateMachine *fsm;
    bool full = false;
};

#endif // SWITCH_H
