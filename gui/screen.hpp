#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <QWidget>

#include "rendering/raytracer.hpp"
#include "rendering/scene.hpp"

class Screen : public QWidget
{
    Q_OBJECT
public:
    explicit Screen(QWidget *parent = 0);
    virtual ~Screen() = default;

protected:
    virtual void paintEvent(QPaintEvent* evt) override;
    virtual void resizeEvent(QResizeEvent* evt) override;

private:
    Scene m_scene;
    Raytracer m_raytracer;

};

#endif // SCREEN_HPP
