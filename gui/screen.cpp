#include "screen.hpp"
#include "image.hpp"

#include "rendering/primitives/sphere.hpp"

#include <QPainter>
#include <QResizeEvent>
#include <QTime>

#include <QDebug>

Screen::Screen(QWidget *parent) :
    QWidget(parent), m_scene(), m_raytracer(m_scene, width(), height(), 8, 6, 10)
{
    setMinimumSize(800, 600);

    m_scene.addPrimitive<Sphere>(utils::vector3d{0, 0, 80}, 2, utils::vector3d{0, 0, 1});
    m_scene.addPrimitive<Sphere>(utils::vector3d{2, 1, 60}, 1, utils::vector3d{1, 0, 0});
    m_scene.addPrimitive<Sphere>(utils::vector3d{-2, -1, 60}, 1, utils::vector3d{0, 1, 0});
}

namespace
{
    QColor vecToQColor(utils::vector3d vec)
    {
        return QColor(vec.x()*255, vec.y()*255, vec.z()*255);
    }
}

void Screen::paintEvent(QPaintEvent* evt)
{
    Q_UNUSED(evt);
    QPainter p(this);
    QTime start = QTime::currentTime();
    auto image = m_raytracer.draw();
    qDebug() << "rendered in " << start.msecsTo(QTime::currentTime()) << "ms";
    assert(image.width() == (std::size_t)width() && image.height() == (std::size_t)height());
    for(std::size_t x = 0; x < image.width(); x++)
        for(std::size_t y = 0; y < image.height(); y++)
        {
            p.setPen(vecToQColor(image(x, y)));
            p.drawPoint(x, y);
        }
}

void Screen::resizeEvent(QResizeEvent* evt)
{
    m_raytracer.setResolution(evt->size().width(), evt->size().height());
}
