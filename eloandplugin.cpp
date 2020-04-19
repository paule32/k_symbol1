#include "eloand.h"
#include "eloandplugin.h"

#include <QtPlugin>

EloAndPlugin::EloAndPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void EloAndPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool EloAndPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *EloAndPlugin::createWidget(QWidget *parent)
{
    return new EloAnd(parent);
}

QString EloAndPlugin::name() const
{
    return QLatin1String("EloAnd");
}

QString EloAndPlugin::group() const
{
    return QLatin1String("kallup - electron");
}

QIcon EloAndPlugin::icon() const
{
    return QIcon(QLatin1String(":/Symbol1.png"));
}

QString EloAndPlugin::toolTip() const
{
    return QLatin1String("Elektronische Symbole");
}

QString EloAndPlugin::whatsThis() const
{
    return QLatin1String("Vorlage zum Bild Symbol1.png");
}

bool EloAndPlugin::isContainer() const
{
    return false;
}

QString EloAndPlugin::domXml() const
{
    return QLatin1String("<widget class=\"EloAnd\" name=\"eloAnd\">\n</widget>\n");
}

QString EloAndPlugin::includeFile() const
{
    return QLatin1String("eloand.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(k_eloandplugin, EloAndPlugin)
#endif // QT_VERSION < 0x050000
