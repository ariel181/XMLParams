#ifndef FEATUREUPDATER_H
#define FEATUREUPDATER_H

#include <QObject>
#include "sharedpointerdefines.h"

/**
 * @brief The FeatureUpdater - klasa słurzy do połączenai sygnału widgetu z aktualizacja wartosci klasy feature.
 *
 */
class FeatureUpdater : public QObject
{
    Q_OBJECT
public:
    explicit FeatureUpdater(FeaturePtr feature, QObject *parent = 0);
    ~FeatureUpdater();

signals:

public slots:
    void valueChange(int val);
    void valueChange(bool val);
    void valueChange(QString val);

private:
    FeaturePtr _feature;
};

#endif // FEATUREUPDATER_H
