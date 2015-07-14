#ifndef PETRIVIEW_H
#define PETRIVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QMenu>

#include "diagram/petriscene.h"

class PetriView: public QGraphicsView
{
    Q_OBJECT
public:
    PetriView(QWidget *parent = nullptr);
    virtual ~PetriView();

    PetriScene* getScene() const;

public slots:
    void petriItemInserted(IPetriItem *item);
    void petriTextInserted(QGraphicsTextItem *item);
    void petriItemSelected(QGraphicsItem *item);
    void petriItemDeleted();
    void petriArcInserted(IPetriArc *arc);

    //right click
    void showContextMenu(const QPoint& pos);
    //zoom
    void scalingTime(qreal x);
    void animFinished();

signals:
    void sceneClicked();

#ifndef QT_NO_WHEELEVENT
protected:
    //zoom
    void wheelEvent(QWheelEvent *event) override;
#endif

private:
    PetriScene* scene;

    //zoom
    int _numScheduledScalings;

    QMenu menuPlace;
    QMenu menuTransition;
    QMenu menuArc;
    QMenu menuNet;

    void createMenus();

private slots:
    void rotate();
};

#endif // PETRIVIEW_H
