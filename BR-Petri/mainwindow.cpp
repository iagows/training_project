#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //TODO : refazer esse menu
    this->itemMenu = menuBar()->addMenu(tr("oi"));

    this->scene = new PetriScene(itemMenu, this);
    this->ui->graphicsView->setScene(this->scene);

    connect(scene, SIGNAL(itemInserted(IPetriItem*)),
            this, SLOT(itemInserted(IPetriItem*)));
    connect(scene, SIGNAL(textInserted(QGraphicsTextItem*)),
            this, SLOT(textInserted(QGraphicsTextItem*)));
    connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),
            this, SLOT(itemSelected(QGraphicsItem*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_normal_clicked()
{
    this->scene->setMode(PetriScene::MoveItem);
}

void MainWindow::on_bt_place_clicked()
{
    this->scene->setMode(PetriScene::InsItem);
    this->scene->setItemType(IPetriItem::Place);
}

void MainWindow::on_bt_fplace_clicked()
{
    this->scene->setMode(PetriScene::InsItem);
    this->scene->setItemType(IPetriItem::FPlace);
}

void MainWindow::on_bt_ttrans_clicked()
{
    this->scene->setMode(PetriScene::InsItem);
    this->scene->setItemType(IPetriItem::TTrans);
}

void MainWindow::on_bt_itrans_clicked()
{
    this->scene->setMode(PetriScene::InsItem);
    this->scene->setItemType(IPetriItem::ITrans);
}

void MainWindow::on_bt_arc_clicked()
{
    this->scene->setMode(PetriScene::InsArc);
    this->scene->setArcType(IPetriArc::Activator);
}

void MainWindow::on_bt_iarc_clicked()
{
    this->scene->setMode(PetriScene::InsArc);
    this->scene->setArcType(IPetriArc::Inhibitor);
}

void MainWindow::on_bt_farc_clicked()
{
    this->scene->setMode(PetriScene::InsArc);
    this->scene->setArcType(IPetriArc::FActivator);
}

void MainWindow::itemInserted(IPetriItem *item)
{
    //TODO aqui
    (void)item;
}

void MainWindow::textInserted(QGraphicsTextItem *item)
{
    //TODO aqui
    (void)item;
}

void MainWindow::itemSelected(QGraphicsItem *item)
{
    //TODO aqui
    (void)item;
}
