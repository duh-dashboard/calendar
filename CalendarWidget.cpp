// Copyright (C) 2026 Sean Moon
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "CalendarWidget.h"

#include <QCalendarWidget>

CalendarWidget::CalendarWidget(QObject* parent) : QObject(parent) {}

void CalendarWidget::initialize(dashboard::WidgetContext* /*context*/) {}

QWidget* CalendarWidget::createWidget(QWidget* parent) {
    auto* cal = new QCalendarWidget(parent);
    cal->setNavigationBarVisible(true);
    cal->setGridVisible(false);
    cal->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    cal->setStyleSheet(
        // Navigation bar
        "QCalendarWidget QWidget#qt_calendar_navigationbar {"
        "  background-color: #181825;"
        "  padding: 4px 2px;"
        "}"
        // Prev / next month tool buttons
        "QCalendarWidget QToolButton {"
        "  color: #c8cee8;"
        "  background: transparent;"
        "  border: none;"
        "  border-radius: 4px;"
        "  padding: 2px 6px;"
        "  font-size: 13px;"
        "}"
        "QCalendarWidget QToolButton:hover {"
        "  background: #2d2d4a;"
        "}"
        // Month / year spin boxes inside the nav bar
        "QCalendarWidget QSpinBox {"
        "  color: #c8cee8;"
        "  background: transparent;"
        "  border: none;"
        "  font-size: 13px;"
        "  font-weight: 600;"
        "}"
        // Day-of-week header row
        "QCalendarWidget QHeaderView {"
        "  background-color: #1e1e2e;"
        "}"
        "QCalendarWidget QHeaderView::section {"
        "  background-color: #1e1e2e;"
        "  color: #606090;"
        "  font-size: 11px;"
        "  font-weight: 600;"
        "  border: none;"
        "  padding: 4px 0;"
        "}"
        // The main grid of days
        "QCalendarWidget QAbstractItemView {"
        "  background-color: #1a1a2a;"
        "  color: #c8cee8;"
        "  selection-background-color: #3a6acc;"
        "  selection-color: #ffffff;"
        "  outline: none;"
        "}"
        "QCalendarWidget QAbstractItemView:enabled {"
        "  color: #c8cee8;"
        "}"
        "QCalendarWidget QAbstractItemView:disabled {"
        "  color: #404060;"
        "}");

    return cal;
}

QJsonObject CalendarWidget::serialize() const {
    return {};
}

void CalendarWidget::deserialize(const QJsonObject& /*data*/) {}

dashboard::WidgetMetadata CalendarWidget::metadata() const {
    return {
        .name = "Calendar",
        .version = "1.0.0",
        .author = "Dashboard",
        .description = "Displays the current month calendar",
        .minSize = QSize(280, 220),
        .maxSize = QSize(600, 500),
        .defaultSize = QSize(320, 260),
    };
}
