import QtQuick 2.0
import System 1.0

import Base 1.0

Rectangle {
    id: root

    property string text
    property int textSize
    property string imgSource

    anchors.left: parent.left
    anchors.right: parent.right

    Row {
        anchors.fill: root
        spacing: Style.baseSpacing
        Image {
            anchors.top: parent.top
            anchors.bottom: parent.botom
            source: root.imgSource
        }
        BaseText {
            text: root.text
            font.pixelSize: root.textSize
        }
    }
}
