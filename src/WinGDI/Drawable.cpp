//=============================================================================
//File Name: Drawable.cpp
//Description: Provides interface for WinGDI drawable objects
//Author: Tyler Veness
//=============================================================================

#include "Drawable.hpp"

#include <wingdi.h>

Drawable::Drawable( const Vector& position ,
        const Vector& size ,
        COLORREF fillColor ,
        COLORREF outlineColor ,
        int outlineThickness )
{
    m_boundingRect.left = position.X;
    m_boundingRect.top = position.Y;
    m_boundingRect.right = position.X + size.X;
    m_boundingRect.bottom = position.Y + size.Y;

    m_fillColor = fillColor;
    m_outlineColor = outlineColor;
    m_outlineThickness = outlineThickness;
}

Drawable::~Drawable() {

}

void Drawable::setPosition( const Vector& position ) {
    // Keep width and height the same at the new position
    m_boundingRect.right = position.X + ( m_boundingRect.right - m_boundingRect.left );
    m_boundingRect.bottom = position.Y + ( m_boundingRect.bottom - m_boundingRect.top );

    m_boundingRect.left = position.X;
    m_boundingRect.top = position.Y;
}

void Drawable::setPosition( short x , short y ) {
    // Keep width and height the same at the new position
    m_boundingRect.right = x + ( m_boundingRect.right - m_boundingRect.left );
    m_boundingRect.bottom = y + ( m_boundingRect.bottom - m_boundingRect.top );

    m_boundingRect.left = x;
    m_boundingRect.top = y;
}

const Vector Drawable::getPosition() {
    return Vector( static_cast<short>(m_boundingRect.left) ,
        static_cast<short>(m_boundingRect.top) );
}

void Drawable::setSize( const Vector& size ) {
    m_boundingRect.right = m_boundingRect.left + size.X;
    m_boundingRect.bottom = m_boundingRect.top + size.Y;
}

void Drawable::setSize( short width , short height ) {
    m_boundingRect.right = m_boundingRect.left + width;
    m_boundingRect.bottom = m_boundingRect.top + height;
}

const Vector Drawable::getSize() {
    return Vector( static_cast<short>(m_boundingRect.right - m_boundingRect.left) ,
        static_cast<short>(m_boundingRect.bottom - m_boundingRect.top) );
}

void Drawable::setFillColor( COLORREF color ) {
    m_fillColor = color;
}

COLORREF Drawable::getFillColor() {
    return m_fillColor;
}

void Drawable::setOutlineColor( COLORREF color ) {
    m_outlineColor = color;
}

COLORREF Drawable::getOutlineColor() {
    return m_outlineColor;
}

void Drawable::setOutlineThickness( int thickness ) {
    m_outlineThickness = thickness;
}

int Drawable::getOutlineThickness() {
    return m_outlineThickness;
}

const RECT& Drawable::getBoundingRect() {
    return m_boundingRect;
}
