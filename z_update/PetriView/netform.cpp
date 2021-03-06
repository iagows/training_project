#include "netform.h"
#include "ui_netform.h"

#include "visual/placeview.h"

NetForm::NetForm(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::NetForm)
{
    ui->setupUi(this);
    updateIds();

    this->createPlace(0,0);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 400, 400);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);

    //scale(qreal(0.8), qreal(0.8));

    setMinimumSize(400, 400);
    setWindowTitle(tr("Elastic Nodes"));

    PlaceView* pv = new PlaceView(this);
    scene->addItem(pv);
}

NetForm::~NetForm()
{
    delete ui;
}

void NetForm::createPlace(int x, int y)
{
    int id = getNextPlace();
    std::string placeName = "p_"+std::to_string(id);
    spnp::Place *p = new spnp::Place(id, placeName, 0,
                                     new spnp::Label(id, placeName, x, y),
                                     x, y);
    this->netData.add(p);
}

void NetForm::createTransition(int x, int y)
{
    int id = getNextTransition();
    std::string transitionName = "t_"+std::to_string(id);
    spnp::Transition *t = new spnp::Transition(id, transitionName,"1", x, y);

    this->netData.add(t);
}

void NetForm::createArc(int idP, int idT, bool fromPtoT)
{
    int id = getNextArc();
    std::string arcName = "a_"+std::to_string(id);
    spnp::Arc *a = new spnp::Arc(id, arcName, idP, idT, fromPtoT);

    this->netData.add(a);
}

void NetForm::removePlace(int id)
{
    this->netData.removePlace(id);
}

void NetForm::removeArc(int id)
{
    this->netData.removeArc(id);
}

void NetForm::removeTransition(int id)
{
    this->netData.removeTransition(id);
}

void NetForm::itemMoved()
{
    //atualizar posição dos arcos
}

void NetForm::zoomIn()
{
    scaleView(qreal(1.2));
}

void NetForm::zoomOut()
{
    scaleView(1 / qreal(1.2));
}

void NetForm::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void NetForm::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}

void NetForm::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void NetForm::updateIds()
{
    std::vector<spnp::Place*> *places = this->netData.getPlaces();
    int size = places->size();
    int maxId = 0;
    for(int i=0; i<size; ++i)
    {
        spnp::Place *p = places->at(i);
        maxId = maxId > p->id ? maxId : p->id;
    }
    this->idPlace = maxId+1;

    std::vector<spnp::Transition*> *transitions = this->netData.getTransitions();
    size = transitions->size();
    maxId = 0;
    for(int i=0; i<size; ++i)
    {
        spnp::Transition* t = transitions->at(i);
        maxId = maxId > t->id ? maxId : t->id;
    }
    this->idTransition = maxId+1;

    std::vector<spnp::Arc*> *arcs = this->netData.getArcs();
    size = arcs->size();
    maxId = 0;
    for(int i=0; i<size; ++i)
    {
        spnp::Arc* arc = arcs->at(i);
        maxId = maxId > arc->id ? maxId : arc->id;
    }
    this->idArc = maxId+1;
}

int NetForm::getNextPlace()
{
    return this->idPlace++;
}

int NetForm::getNextTransition()
{
    return this->idTransition++;
}

int NetForm::getNextArc()
{
    return this->idArc++;
}

