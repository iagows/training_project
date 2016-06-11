#ifndef PETRIPROPERTIES_H
#define PETRIPROPERTIES_H

#include <QWidget>

namespace Ui {
class PetriProperties;
}

class PetriProperties : public QWidget
{
    Q_OBJECT

public:
    explicit PetriProperties(QWidget *parent = 0);
    ~PetriProperties();

private slots:
    void on_le_place_name_textEdited(const QString &arg1);

    void on_le_place_tokens_textEdited(const QString &arg1);

    void on_le_itrans_name_textEdited(const QString &arg1);

    void on_le_itrans_prior_textEdited(const QString &arg1);

    void on_le_itrans_guard_textEdited(const QString &arg1);

private:
    Ui::PetriProperties *ui;

    void setData();
};

#endif // PETRIPROPERTIES_H
