// =============================================================================
// File Name: ProgressBar.cpp
// Description: Provides an interface to a progress bar with WinGDI
// Author: FRC Team 3512, Spartatroniks
// =============================================================================

#include "ProgressBar.hpp"

ProgressBar::ProgressBar(bool netUpdate, QWidget* parent) :
    QWidget(parent), NetUpdate(netUpdate) {
    QVBoxLayout* layout = new QVBoxLayout();
    setLayout(layout);

    m_bar = new QProgressBar(this);
    m_bar->setMinimum(0);
    m_bar->setMaximum(100);
    layout->addWidget(m_bar);

    m_text = new Text(false, this);
    layout->addWidget(m_text);

    setPercent(0.f);
}

void ProgressBar::setPercent(float percent) {
    if (percent > 100) {
        percent = 100;
    }

    m_bar->setValue(percent);
    m_bar->update();
}

float ProgressBar::getPercent() {
    return m_bar->value();
}

void ProgressBar::setString(const std::wstring& text) {
    m_text->setString(text);
}

std::wstring ProgressBar::getString() {
    return m_text->getString();
}

void ProgressBar::updateValue() {
    NetValue* printValue = getValue(m_varIds[0]);
    NetValue* percentValue = getValue(m_varIds[1]);

    if (printValue != nullptr) {
        setString(NetUpdate::fillValue(printValue));
    }

    if (percentValue != nullptr) {
        std::cout << "percentValue->getType()=" << percentValue->getType() << "\n";
        std::cout << "percent=" << (int)*static_cast<unsigned char*>(percentValue->getValue()) << "\n";
        setPercent(*static_cast<unsigned char*>(percentValue->getValue()));
    }
}
